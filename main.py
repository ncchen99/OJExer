import GJExer
import ZJExer

print('''
   ____        __    ______   _  __    ______    ____ 
  / __ \      / /   / ____/  | |/ /   / ____/   / __ \ 
 / / / / __  / /   / __/     |   /   / __/     / /_/ /
/ /_/ / / /_/ /   / /___    /   |   / /___    / _, _/ 
\____/  \____/   /_____/   /_/|_|  /_____/   /_/ |_|        
                  __             __                             
  __ _  ___ _ ___/ / ___        / /   __ __       ___  ____ ____
 /  ' \/ _ `// _  / / -_)      / _ \ / // /      / _ \/ __// __/
/_/_/_/\_,_/ \_,_/  \__/      /_.__/ \_, /      /_//_/\__/ \__/ 
                                    /___/                      
\n 2020/9/26 V0.0.1 Bug hen 多ㄛ💩
''')
print("你想要從哪個Judge下載Code?")
choose = "偶好累"
while choose not in ["1", "2"]:
    choose = input("1 : ZeroJudge, 2 : GreenJudge : ")
print("\n接著請輸入JSESSIONID和使用者名稱，可參考GitHub的教學取得\n")
sessionId = input("請輸入JSESSIONID : ")
print()
userName = input("請輸入使用者名稱 : ")
print()
if choose == "1":
    ZJExer.filterAllSubmissions(userName, sessionId)
    print("完成，存到 /ZeroJudge　惹")
elif choose == "2":
    GJExer.filterAllSubmissions(userName, sessionId)
    print("完成，存到 /ｇreenJudge　惹")
