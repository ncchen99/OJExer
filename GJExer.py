import requests
import json
import html
from bs4 import BeautifulSoup
import os

userName = ""
JSESSIONID = ""

headers = {
    "cookie": "JSESSIONID=" + JSESSIONID,
    "user-agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.125 Safari/537.36"
}


def getSubmissionPage(pageNum):
    url = "http://www.tcgs.tc.edu.tw:1218/RealtimeStatus?account=" + \
        userName + "&page=" + str(pageNum)
    r = requests.get(url, headers=headers)
    return r.text


def saveCode(SID):
    r = requests.get(
        'http://www.tcgs.tc.edu.tw:1218/ShowCode?solutionid=' + SID[0], headers=headers)
    r.encoding = 'utf8'
    code = r.text[r.text.index(
        "/********************************************"):r.text.index("</textarea>")]
    count = 2
    fileName = "GreenJudge/"+SID[1]+".cpp"
    with open(fileName, "w+") as f:
        f.write(code)


def findAllACCodeSolutionId(soup, pageNum):
    SIdList = list()
    count = 2
    if not "RealtimeStatus?account=" + \
            userName + "&amp;page=" + str(pageNum+1) in str(soup):
        return ["Finished"]
    for tr in soup.find_all("tr"):
        if "AC" in tr.text:
            a = tr.find_all("td")[2].select("a")[0]
            if a["href"][-4:] in str(SIdList):
                SIdList.append([tr.select("td")[0].string, a["href"]
                                [-4:] + " " + a.text + " - " + str(count)])
                count += 1
            else:
                SIdList.append(
                    [tr.select("td")[0].string, a["href"][-4:] + " " + a.text])
                count = 2
    return SIdList


def filterAllSubmissions():
    pageNum = 1
    while True:
        solutionIds = findAllACCodeSolutionId(
            BeautifulSoup(getSubmissionPage(pageNum), 'html.parser'), pageNum)
        print(solutionIds)
        if "Finished" in solutionIds:
            print("Finished!")
            break
        for SID in solutionIds:
            saveCode(SID)
        pageNum += 1


if __name__ == "__main__":
    if not os.path.exists("GreenJudge"):
        os.makedirs("GreenJudge")
    filterAllSubmissions()
else:
    print("ZeroJudge Code Downloader")


# print(getSubmissionPage(1))
