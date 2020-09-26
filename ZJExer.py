import requests
import json
import html
from bs4 import BeautifulSoup
import os

userName = "s710436@whsh.tc.edu.tw"
JSESSIONID = "F5336A79198A914C9AACA7BFE40BE469"

headers = {
    "cookie": "JSESSIONID=" + JSESSIONID,
    "user-agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.125 Safari/537.36"
}


def getSubmissionPage(pageNum):
    url = "https://zerojudge.tw/Submissions?page=" + \
        str(pageNum) + "&&account="+userName
    r = requests.get(url, headers=headers)
    return r.text


def saveCode(SID):
    r = requests.get(
        'https://zerojudge.tw/Solution.json?data=Code&solutionid=' + SID[0], headers=headers)
    res = json.loads(r.text)
    count = 2
    fileName = "ZeroJudge/"+SID[1]+"."+res["language"]["suffix"]
    with open(fileName, "w+") as f:
        f.write(html.unescape(res["code"]))


def findAllACCodeSolutionId(soup):
    SIdList = list()
    count = 2
    if len(soup.find_all("tr")) == 2:
        return ["Finished"]
    for tr in soup.find_all("tr"):
        if tr.has_attr("solutionid") and "AC" in tr.text:
            a = tr.find_all("td")[2].select("a")[0]
            if a["href"][-4:] in str(SIdList):
                SIdList.append([tr["solutionid"], a["href"]
                                [-4:] + " " + a.text + " - " + str(count)])
                count += 1
            else:
                SIdList.append(
                    [tr["solutionid"], a["href"][-4:] + " " + a.text])
                count = 2
    return SIdList


def filterAllSubmissions():
    pageNum = 1
    while True:
        solutionIds = findAllACCodeSolutionId(
            BeautifulSoup(getSubmissionPage(pageNum), 'html.parser'))
        print(solutionIds)
        if "Finished" in solutionIds:
            print("Finished!")
            break
        for SID in solutionIds:
            saveCode(SID)
        pageNum += 1


if __name__ == "__main__":
    if not os.path.exists("ZeroJudge"):
        os.makedirs("ZeroJudge")
    filterAllSubmissions()
else:
    print("ZeroJudge Code Downloader")
