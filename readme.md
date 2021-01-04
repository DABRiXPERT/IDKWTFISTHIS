
# idkwtfisthis 說明書
上次更新日期(主程式)：**2021年01月03日**  
上次更新版本(主程式)：`0.10.0`  

上次更新日期(readme.md)：**2021年01月04日**  
readme.md編號：`210104A`  
### 主程式更新內容
將Release內的錯誤的檔案替換成新版。  
exe檔執行正常化(不用載編譯器)。
### readme.md更新內容
將示範圖片改為最新版。
# 目錄
~~原諒一下這裡沒辦法用目錄跳轉下一頁~~  
~~所以就手動跳轉吧。~~  
當我沒說  
現在可以了  
<!-- TOC -->
**1.** [這到底是什麼](#這到底是什麼)  
**2.** [如何下載](#如何下載)  
**3.** [怎麼玩](#怎麼玩)  
1. [開始遊戲](#開始遊戲)  
2. [遊戲結束](#遊戲結束)
3. [調整鍵位](#調整鍵位)  
**4.** [後記](#後記)  
<!-- /TOC -->
# 這到底是什麼
一個4K類音GAME模擬器  
製作非常的粗糙  
差不多像這樣  
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/title.png)  
# 如何下載
剛開始會看到這樣的網站  
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/1.png)  
按右邊的`Release`  
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/2.png)  
然後就會看到這個畫面  
按下面的`Assets`  
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/3.png)  
（先說一下這是舊版的，不過方法大同小異。）  
接著會看到有很多選項  
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/4.png)  
至於要下載什麼一個人需求都寫在圖片裡了。  
註：被劃掉的兩個檔案對整個專案的作用沒有很大，所以可以忽視掉。    
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/5.png)  
需要注意的是，我是在 **Windows 10 64位元** 下用 `C++17` 編譯的  
所以如果是用32位元或不是Windows的人都有可能無法正常運行。  
然後下載的時候瀏覽器會一直跑 **未受信任的檔案** 或是作業系統跳出這個錯誤：  
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/6.png)  
這個時候按 **其他資訊** 再按 **仍要執行** 就好了。  
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/7.png)  
到這邊就差不多了。
# 怎麼玩
一開始會看到這個界面：  
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/8.png)  
這上面的訊息很多，所以底下有解釋：  
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/9.png)  
只要按**空白鍵**就開始遊戲了。如果要調鍵位的話請到[這裡](#調整鍵位)繼續看。  
**註：絕對不要刪除`rank.iwit`，不然玩家紀錄會不見！**  
**雖然檔案`rank.iwit`會在消失後隨著遊戲重開而回復，但是紀錄絕對不會回復！**
### 開始遊戲
按空白鍵之後會看到這個：  
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/10.png)  
至於要做什麼的話下面圖片有寫：  
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/11.png)  
狀態欄是讓玩家知道離下一個目標還有多少分；像底下的圖片表示離第一名還有8分：
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/12.png)  
如果超越他人的弟第一的話就會顯示 `NEW HIGHSCORE!`  
如同上上一張圖片。
### 遊戲結束
如果手殘按錯的話會出現結算畫面：  
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/13.png)  
上面會顯示玩家的成績，如果排名在前五的話還會要求輸入名字，如同上面圖片。  
**註：最多只能輸入15個字元，不然會報錯**  
至於排行榜會紀錄在`rank.iwit`中，所以絕對**不要刪除該檔案！**  
**雖然檔案`rank.iwit`會在消失後隨著遊戲重開而回復，但是紀錄絕對不會回復！**  
(很重要所以我講了兩次)
### 調整鍵位
默認鍵位是`DFJK`。   
如果覺的鍵位很反人類或是想挑戰刺激一點的話(我是不知道能刺激到哪啦)就可以按 `S` 鍵調整。  
之後會看到這個畫面：  
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/14.png)  
這時候就會要求輸入更換`K0`位置的鍵位，只能輸入**一個**字元，輸入完要按`ENTER`。  
如果輸入兩個一樣的按鍵會出現錯誤訊息，如下圖：  
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/15.png)  
以下輸入`QWOP`後，標題界面會顯示我的設定：  
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/16.png)  
遊戲界面中也會套用：  
![down_pic](https://github.com/DABRiXPERT/idkwtfisthis/blob/master/gameplay_screenshot/17.png)  
不過我**並沒有設置紀錄鍵位**的功能，所以遊戲重開都要重打一次，之後更新會加進這個功能。
# 後記
這裡回答一些問題。  
#### 為什麼想要做這個專案？
原本只是為了應付學習歷程，不過做一做還蠻有興趣的所以保留了下來。
#### 什麼時候做的？花了多久？
2020年8月2日。在學習歷程系統關閉前從早上9點用到晚上6點花了9小時(不包含吃飯和休息只花了6小時。)
#### 感想？
沒這東西。
#### 之後有要做其他程式或更新這個程式嗎？
這個程式之後會更新啦，我都會寫在`version_log.txt`裡，要載原代碼才看得到。
至於其他程式的話，之後會做一個叫`burikusweeper.exe`的程式，其實就是用純文本C++寫的踩地雷，然後大概暑假之前會做UI版的`burikusweeper.ui`，只是換成圖形界面而已，程式語言應該是用C#...吧，反正在自主學習的時候可以研究一下。
#### 寫程式需要什麼東西？
電腦，機械鍵盤(建議)，某程式語言的基礎和編譯器或IDE(最好有)，刺激人心的音樂(BPM256或是塞爆32分的那種...好像在說誰)，還有最重要的三個東西：挫折感，自我懷疑還有堅持(雖然也不知道是在堅持什麼)，差不多就這樣。


### **==以下空白==**
