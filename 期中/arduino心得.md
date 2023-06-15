<h1> Arduino 學習心得  

##### 系級：資工二		姓名：林維新		學號：111010506
---
<h3>摘要  

> 此篇心得為本學期再學習Arduino上的筆記與心得，
筆記上將以圖片為主去講解實際操作內容，
在操作上除了需要了解Arduino該如何撰寫外，
可能還需要具備硬體連接能力，與網頁撰寫能力。
> 備註：在撰寫上會以ChatGTP作為輔助，會備註是由GTP所撰寫或更改。

<h3>目錄

- 環境建置
- 初次連接的快樂


<h3>環境建置


> 此次是以Linklt 7697作為程式寫入的平台，需要在Arduino中額外引入Linklt 7697的配置文件。
> 在建置環境需要以下步驟：
- 至Arduino官網下載最新的版本（2.0.3版）
- 在Arduino中引入Linklt 7697的配置文件
（https://files.gitbook.com/v0/b/gitbook-x-prod.appspot.com/o/spaces%2FY4gduUSLWOCI23CXUWej%2Fuploads%2FfDIyZSO3WxvVYeZFhkSQ%2Fpackage_mtk_linkit_7697_index.json?alt=media&token=029ccbdc-f32d-4e1c-b753-898ea26d720e）
- 測試Linklt 7697是否能被Arduino所偵測
> 還需要準備任一種可以繪製電路圖的程式或工具，在硬體實作時可協助更好了解如何連接與設計。
我所使用的是，在WindowsXP下的Protel 99se這套工具，是以虛擬機的方式開啟與執行。

<h3> 初次連接的快樂

> 接下來我們將嘗試第一次連接Linklt 7697與Arduino，準備好數據線連接至電腦。
以下我們將撰寫一隻簡單的程式，控制Linklt 7697透過板載的按鈕控制其指示燈。
<pre><code>This is a code block.（程式由ChatGTP所撰寫）

    const int buttonPin = 13;  // 連接到LinkIt 7697的數位輸入引腳
    const int ledPin = 12;    // 連接到指示燈的Arduino的數位輸出引腳

    void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);
    }

    void loop() {
    int buttonState = digitalRead(buttonPin);  // 讀取按鈕狀態

    if (buttonState == LOW) {
        digitalWrite(ledPin, HIGH);  // 按下按鈕時，點亮指示燈
    } else {
        digitalWrite(ledPin, LOW);   // 釋放按鈕時，熄滅指示燈
    }
    }
</code></pre>
> 當按鈕按下時，連接到指示燈的引腳將被設置為高電位，使其亮起。

<h3> 七段顯示器的連接實作

> 在實作上
<pre><code>程式由本人親自撰寫測試

    const byte pin0[4]={0, 1, 2, 3};
    const byte pin1[4]={4, 5, 6, 7};
    const byte LEDs0[10] = {
        B0000,
        B0001,
        B0010,
        B0011,
        B0100,
        B0101,
        B0110,
        B0111,
        B1000,
        B1001
    };
    const byte LEDs1[10] = {
        B0000,
        B0001,
        B0010,
        B0011,
        B0100,
        B0101,
        B0110,
        B0111,
        B1000,
        B1001
    };
    void setup() {
        for (byte i = 0; i < 4; i++){
            pinMode(pin0[i], OUTPUT);
            pinMode(pin1[i], OUTPUT);
        }

    }
    void loop() {
        for (byte index2 = 0; index2 < 10; index2++){
            for (byte index1 = 0; index1 < 10; index1++){
                for (byte i = 0; i < 4; i++){
                    digitalWrite(pin0[i], bitRead(LEDs0[index1], i));
                    digitalWrite(pin1[i], bitRead(LEDs0[index2], i));
                }
                delay(1000);
            }
        }
    }
</code></pre>