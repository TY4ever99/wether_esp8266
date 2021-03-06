#ifndef __MAIN_H__
#define __MAIN_H__


#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiUdp.h>
#include <ArduinoJson.h>
#include <TimeLib.h>
#include <TFT_eSPI.h> 
#include <SPI.h>
#include <TJpg_Decoder.h>

#include "font/ZdyLwFont_20.h"          //字体头文件
#include "font/FxLED_32.h"

#include "img/ty/ty.h"

unsigned int Gif_Mode = 1;          //1 - 龙猫 


#include "img/temperature.h"            //温度图标
#include "img/humidity.h"               //湿度图标
#include "img/watch_top.h"              //顶部图标
#include "img/watch_bottom.h"           //底部图标

TFT_eSPI tft = TFT_eSPI();              //引脚请自行配置tft_espi库中的 User_Setup.h文件
TFT_eSprite clk = TFT_eSprite(&tft);
TFT_eSprite clkb = TFT_eSprite(&tft);   //字体滚动用

const char* WIFI_SSID     = "GAME"; //家里无线路由器的账号和密码，----------要修改成自己的----------，引号不要去掉
const char* WIFI_PASSWORD = "lt199567";

HTTPClient httpClient;                  //创建 HTTPClient 对象
uint8_t loadNum = 6;                    //开机启动进度条的起始位置
uint16_t bgColor = 0xFFFF;              //背景颜色
String cityCode = "101040100";          //天气城市代码
uint8_t Dis_Count = 0;                  //滚动显示内容计数
String scrollText[5];                   //滚动显示的数据缓冲区

//---------------------NTP相关参数---------------------
static const char ntpServerName[] = "ntp1.aliyun.com"; //NTP服务器   
const int timeZone = 8;                 //时区，东八区为北京时间
WiFiUDP Udp;
unsigned int localPort = 8888;          //连接时间服务器的本地端口号
time_t prevDisplay = 0;                 //上一次获取到的时间
const int NTP_PACKET_SIZE = 48;         //NTP发送数据包长度
byte packetBuffer[NTP_PACKET_SIZE];     //NTP数据包缓冲区

//---------------------Time 相关参数---------------------
int Led_Flag = HIGH;                    //默认当前灭灯
bool Led_State = false;                 //灯状态
unsigned long now1;                     //轮流滚动时间计时
unsigned long LastTime1 = 0;
unsigned long now2;                     //定时获取天气
unsigned long LastTime2 = 0;
unsigned long now3;
unsigned long LastTime3 = 0;            //

time_t getNtpTime();
void digitalClockDisplay();
void printDigits(int digits);
String num2str(int digits);
void sendNTPpacket(IPAddress &address);

#endif
