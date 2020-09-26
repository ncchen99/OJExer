# OJ扣得輸出者 

[![AppVeyor](https://ci.appveyor.com/api/projects/status/github/Ne0nd0g/merlin?branch=dev&svg=true)](https://ci.appveyor.com/project/Ne0nd0g/merlin)

```
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
               2020/9/26 V0.0.1 Bug hen 多ㄛ💩
```
+ 目前只能下載ZeroJudge和GreenJudge的＠＠
+ 這個東東原本是串電37th的教學[牧犬羊](https://github.com/nevikw39/ZeroJudge_Exporter)高一時的作品，code十分精簡，還有GUI，只是它有點年久失修故障惹，偶找不太到問題，只好重幹一個🥴，原本想要做包括TIOJ和QDUOJ也的，不過現在蠻累的要去捆惹，晚安安🐂

# 🍖教學

## 🐛Zerojudge找使用者名稱和JSESSIONID

![](https://i.imgur.com/I7Yawnd.png)

> ### 💊開啟Zerojudge並登入，進入使用者資訊頁面（User infomation），藍藍的那個超連結是**使用者名稱**。
								
![](https://i.imgur.com/BW2gYv7.png)

> ### 🍭按下F12，選取Network欄位。

![](https://i.imgur.com/vijRTyZ.png)

> ### 🚌按一下`F5`或`CTRL+R` 開始擷取，找到`zerojudge.tw`這個文件。

![](https://i.imgur.com/HvTg3T4.png)
> ### 🎄拉開視窗，選取`Headers`往下拉找到`Request Headers` => `cookie` => `JSESSIONID`　複製等於後面**那駝東西**。

## 🙈GreenJudge也大同小異🐻

## 接著執行 main.py

![](https://i.imgur.com/ysu4gP4.png)
