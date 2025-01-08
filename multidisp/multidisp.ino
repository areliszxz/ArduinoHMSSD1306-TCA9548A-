#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include "vars.h"
#include "tft_init.h"
#define LED 2


//|20.4|80.9|26.6|26.6|||8C|||8G0.25TB0.25TBmacOS-15.20.00
void setup() {
  cont_act=0;
  setc_C=WHITE;
  Wire.begin();
  //arranque de multiplexor
  for(int cont=0;cont<=Scr_num;cont++) {mplex_init(cont);}
  //
  Serial.begin(115200); //ingress data 
  //thermistor pin
  analogReadResolution(10);
  //thermistor pin
  pinMode(4,INPUT);
  pinMode(13,INPUT);
  //thermistor pin end
  pinMode(LED,OUTPUT);
  //sin datos
  digitalWrite(LED,HIGH);
  display91.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
}

void loop() {
    Serial.println(Serial.available());
    if (Serial.available() > 0) { 
      serial_res();
      draw_CPUstat(0);
      draw_RAMstat(1);
      draw_HD1stat(2);
      get_analog_temp(3);
      OS_inf(4);
      digitalWrite(LED,LOW);
      cont_act=0;
      Serial.println("Con datos");
    }else if (cont_act==0 and Serial.available() == 0){
      /*draw_CPUstat(0);
      draw_RAMstat(1);
      draw_HD1stat(2);
      get_analog_temp(3);
      OS_inf(4);*/
      Serial.println("Sin datos");
      digitalWrite(LED,HIGH);
      //comentar linia siguiente para modificar gui sin ejecutar el enviador
      for(int cont=0;cont<=4;cont++) {w_time(cont);}
    }
      delay(500); 
}

void draw_CPUstat(int screen) { /*CPU SEC*/
  TCA9548A(screen);
  display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setTextWrap(false);
      display.setFont(&muMatrix8ptRegular);
    //Icon CPU
      int porcent=CPUstat.toInt();
      if (porcent<=40){display.drawBitmap(55,20,procx24,24,24,setc_C);}
      if (porcent>=41 and porcent <=80){display.drawBitmap(60,22,bulb_icon16x16,16,16,setc_C);}
      if (porcent>=81){display.drawBitmap(60,22,bulb_on_icon16x16,16,16,setc_C);}
    //Graph
      int grapH=(porcent*maxgrapH)/100;
      display.drawRect(3, (maxgrapH+1)-grapH, 46, grapH, SSD1306_WHITE);
    //
  //linea1
    display.drawLine(1, firstRow-10, 55, firstRow-10, setc_C);//----  
    display.drawLine(55, firstRow-10, 60, firstRow+5, setc_C); //.  "\"
    display.drawLine(60, firstRow+5, 75, firstRow+5, setc_C); //.      ---
  //
 //CPUStats
    display.setCursor(65, firstRow+3);
    display.println(F("%"));
    display.setCursor(4, firstRow+20); 
    display.println(CPUstat);  
    display.setTextSize(2);
    display.setCursor(10, firstRow+45); 
    display.println(F("Use"));                   
  //
  //Lineab
    display.drawLine(60, firstRow+35, 75, firstRow+35, setc_C); // ---
    display.drawLine(75, firstRow+35, 85, firstRow-10, setc_C); // "/"
    display.drawLine(85, firstRow-10, width, firstRow-10, setc_C);
  //
  //CPU Cores
    display.setTextSize(2);
    display.fillRoundRect(108, 3 , (CPUstat.toInt()*80)/100, 15, 0, BLACK);
    display.setCursor(85, firstRow+45);      
    display.println(CPUcores); 
    display.setTextSize(2);
    display.setCursor(90, firstRow+10); 
    display.println("CrN"); 
  //
//END CPU
  display.display();
}

void draw_RAMstat(int screen) { //RAM
  TCA9548A(screen);
  display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setTextWrap(false);
      display.setFont(&muMatrix8ptRegular);
    //Icon
      int porcent=RAMstat.toInt();
      if (porcent<=40){display.drawBitmap(55,20,Ramv2_24,24,24,setc_C);}
      if (porcent>=41 and porcent <=80){display.drawBitmap(60,22,bulb_icon16x16,16,16,setc_C);}
      if (porcent>=81){display.drawBitmap(60,22,bulb_on_icon16x16,16,16,setc_C);}
    //
      //Graph
      int grapH=(porcent*maxgrapH)/100;
      display.drawRect(3, (maxgrapH+1)-grapH, 46, grapH, SSD1306_WHITE);
    //
  //linea1
    display.drawLine(1, firstRow-10, 55, firstRow-10, setc_C);//----  
    display.drawLine(55, firstRow-10, 60, firstRow+5, setc_C); //.  "\"
    display.drawLine(60, firstRow+5, 75, firstRow+5, setc_C); //.      ---
  //
 //RAMStats
    display.setCursor(65, firstRow+3);
    display.println(F("%"));
    display.setCursor(4, firstRow+20); 
    display.println(RAMstat);  
    display.setTextSize(2);
    display.setCursor(10, firstRow+45); 
    display.println("Use");                   
  //
  //Lineab
    display.drawLine(60, firstRow+35, 75, firstRow+35, setc_C); // ---
    display.drawLine(75, firstRow+35, 85, firstRow-10, setc_C); // "/"
    display.drawLine(85, firstRow-10, width, firstRow-10, setc_C);
  //
  //Ram Total
    display.setTextSize(2);
    display.fillRoundRect(108, 3 , (RAMstat.toInt()*80)/100, 15, 0, BLACK);
    display.setCursor(85, firstRow+45);      
    display.println(RAMtotal); 
    display.setTextSize(2);
    display.setCursor(90, firstRow+20); 
    display.println("RAM"); 
  //
//END RAM
  display.display();
}

void draw_HD1stat(int screen) { //HDD1
TCA9548A(screen);
  display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setTextWrap(false);
      display.setFont(&muMatrix8ptRegular);
    //Icon
      int porcent=SSDspace.toInt();
      if (porcent<=40){display.drawBitmap(55,20,hdd24,24,24,setc_C);}
      if (porcent>=41 and porcent <=80){display.drawBitmap(60,22,bulb_icon16x16,16,16,setc_C);}
      if (porcent>=81){display.drawBitmap(60,22,bulb_on_icon16x16,16,16,setc_C);}
    //
    //Graph
      int grapH=(porcent*maxgrapH)/100;
      display.drawRect(3, (maxgrapH+1)-grapH, 46, grapH, SSD1306_WHITE);
    //
  //linea1
    display.drawLine(1, firstRow-10, 55, firstRow-10, setc_C);//----  
    display.drawLine(55, firstRow-10, 60, firstRow+5, setc_C); //.  "\"
    display.drawLine(60, firstRow+5, 75, firstRow+5, setc_C); //.      ---
  //
 //HDDStat
    display.setCursor(65, firstRow+3);
    display.println(F("%"));
    display.setCursor(4, firstRow+20); 
    display.println(SSDspace);  
    display.setFont(&muHeavy8ptBold);
    display.setTextSize(1);
    display.setCursor(5, firstRow+45); 
    display.println(DD1t);
    display.setFont(&muMatrix8ptRegular); 
    display.setTextSize(2);                  
  //
  //Lineab
    display.drawLine(60, firstRow+35, 75, firstRow+35, setc_C); // ---
    display.drawLine(75, firstRow+35, 85, firstRow-10, setc_C); // "/"
    display.drawLine(85, firstRow-10, width, firstRow-10, setc_C);
  //
  //HDD2 Space
   //HDDStat
    //Graph
      int porcent2=HDDspace.toInt();      
      int grapH2=(porcent2*maxgrapH)/100;
      display.drawRect(87, (maxgrapH+1)-grapH2, 41, grapH2, SSD1306_WHITE);
    //
    display.setCursor(85, firstRow+20); 
    display.println(HDDspace);  
    display.setFont(&muHeavy8ptBold);
    display.setTextSize(1);
    display.setCursor(85, firstRow+45); 
    display.println(DD2t);
    display.setFont(&muMatrix8ptRegular); 
    //
//END HDDs
  display.display();
}

void OS_inf(int screen) { //OS inf
TCA9548A(screen);
//osinf="windows-15.2";
  display91.clearDisplay();
      display91.setTextSize(1);
      display91.setTextColor(WHITE);
      display91.setTextWrap(false);
      display91.setFont(&FreeSans9pt7b);
  //Logos
    if (osinf.indexOf("mac")!=-1){display91.drawBitmap(2,1,applev232,32,32,WHITE); osinfsho="Apple OS";}
    if (osinf.indexOf("win")!=-1 or osinf.indexOf("Win")!=-1){display91.drawBitmap(2,1,win323,32,32,WHITE);osinfsho="Windows";}
 //HDDStat
    display91.setCursor(36, firstRow+5); 
    display91.println(osinfsho);
    display91.setFont(&muHeavy8ptBold);
    display91.setCursor(36, firstRow+17); 
    display91.println(osinf);
  //
//END OSinf
  display91.display();
}

void get_analog_temp(int screen){    //temperature
TCA9548A(screen);

  cputmp=get_temp(4)+comp_therm;
  float porcent=cputmp;
  display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setTextWrap(false);
      display.setFont(&muMatrix8ptRegular);
    //Icon   
      if (porcent<=40){display.drawBitmap(60,22,temp16,16,16, setc_C);}
      if (porcent>=41 and porcent <=80){display.drawBitmap(60,22,bulb_icon16x16,16,16,setc_C);}
      if (porcent>=81){display.drawBitmap(60,22,bulb_on_icon16x16,16,16,setc_C);}
    //
  //linea1
    display.drawLine(1, firstRow-10, 55, firstRow-10, setc_C);//----  
    display.drawLine(55, firstRow-10, 60, firstRow+5, setc_C); //.  "\"
    display.drawLine(60, firstRow+5, 75, firstRow+5, setc_C); //.      ---
  //
    display.setCursor(68, firstRow+3);
    display.drawCircle (62, firstRow-8 ,3, WHITE);
    display.println("C"); 
 //CPU Temp
    display.setCursor(15, firstRow+20); 
    display.println(int(cputmp));  
    display.setCursor(15, firstRow+45); 
    display.println("CPU");    

  //
  //Lineab
    display.drawLine(60, firstRow+35, 75, firstRow+35, setc_C); // ---
    display.drawLine(75, firstRow+35, 85, firstRow-10, setc_C); // "/"
    display.drawLine(85, firstRow-10, width, firstRow-10, setc_C);
  //
  //GPU Temp
    gputmp=get_temp(13)+comp_therm;
    porcent=gputmp;
    display.setCursor(90, firstRow+20); 
    display.println(int(gputmp)); 
    display.setCursor(90, firstRow+45);      
    display.println("GPU"); 
  //
//END get temp
  display.display();
}

void mplex_init(int s_num){
  // Init OLED display on bus number 2
  TCA9548A(s_num);
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 
  // Clear the buffer
  display.clearDisplay();
}

void serial_res(){
    serialReceive = Serial.readString(); 
    Serial.print("Obteniendo datos"+serialReceive);
    CPUstat = serialReceive.substring(0, 5);  
    CPUstat.replace("|"," ");
    RAMstat = serialReceive.substring(5, 10);
    RAMstat.replace("|"," ");
    HDDspace = serialReceive.substring(10, 15);
    HDDspace.replace("|"," ");
    SSDspace = serialReceive.substring(15, 20);
    SSDspace.replace("|"," ");
    CPUcores = serialReceive.substring(20, 25);
    CPUcores.replace("|"," ");
    RAMtotal = serialReceive.substring(25, 30);
    RAMtotal.replace("|"," ");
    DD1t = serialReceive.substring(30, 36);
    DD1t.replace("|"," ");
    DD2t = serialReceive.substring(36, 42);
    DD2t.replace("|"," ");  
    osinf = serialReceive.substring(42, 52);
    //cputmp = serialReceive.substring(52, 56);
    Serial.print("Obteniendo datos");
}
void w_time(int s_num){
  cont_act=1;
  TCA9548A(s_num);
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.drawBitmap(50,0,wait64,64,64,WHITE);
    display.setFont(&muMatrix8ptRegular);
    display.setCursor(2, 10);       
    display.println("En espera.");
    display.display();
    Serial.println("Pantalla " + String(s_num)  +" en espera");
}

float get_temp(uint8_t pinan){ 
  int analogValue = analogRead(pinan);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  return celsius;
}
