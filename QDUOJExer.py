import requests
import json
import html
from bs4 import BeautifulSoup
import os

# 不能用＠＠
headers = {
    "Cookie": "PHPSESSID=70ef07cd82cdc340fe38620b3771a52f; _ga=GA1.2.507212688.1594865270; pma_lang=en; phpMyAdmin=c63b5d69cc2717fb3d2efb55bef40662; pmaUser-1=%7B%22iv%22%3A%22y8kRPLX3tw%5C%2FnJBwvpIP3Jw%3D%3D%22%2C%22mac%22%3A%2263b8495a13ec202c775d93d487c51a3da5960bbd%22%2C%22payload%22%3A%22boYXaQSFlY5Vw%2BnQJO4WEA%3D%3D%22%7D; csrftoken=rb4nyzSCvw5JBFlT3P4RIczkWNwAGw91nkpx1GdVVlck456GjTmcdAqfc9BrZCRz; sessionid=5iw4szl4fu5axsj0ra6wi9aaetsxue57",
    "user-agent": "Chrome/84.0.4147.125",
    "Upgrade-Insecure-Requests": "1",
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9",
    "Host": "whsh.site"
}


def getSubmissionPage(pageNum):
    url = "http://whsh.site/status?myself=1&result=0&page=" + str(pageNum)
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
    print("ZeroJudge Code Downloader")
else:
    if not os.path.exists("ZeroJudge"):
        os.makedirs("ZeroJudge")
    filterAllSubmissions()
