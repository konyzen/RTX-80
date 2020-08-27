
#include "images.h"
#include "SSD1306Wire.h" 
#include "OLEDDisplayUi.h"

void menu();
void DistrictCM(int OB_PC,int DR_PC,int TI_PC,long VL_PC,int XI_PC,int ZI_PC,int XF_PC,int ZF_PC,int OPGL_PC);
void District_EGLG();

/*========================================*/
               /*menu_PR*/
/*========================================*/
byte data_PRIC[40];
unsigned long delayCPU = 0; 
unsigned long anima = 0; 
byte olhoN =1;
byte bocaN=1;
byte PM;
String fala;
byte DT;

/*========================================*/
               /*configuraçao*/
/*========================================*/
#define vecao "0.01"

/*========================================*/
               /*motor grafico*/
/*========================================*/
#define NUM_OB 5

long CLZ[20];
long CLX[20];
long VL_DATA[20];
int OPGL[20];

long XI_DATA[20];
long ZI_DATA[20];
long XF_DATA[20];
long ZF_DATA[20];
long unsigned delayGRAZ[20]; 
long unsigned delayGRAX[20]; 
long unsigned cors[20]; 

int OB_DATA[20];
boolean ocupadoGR[20];

SSD1306Wire  display(0x3c, D2, D1);
 /*========================================*/
               /*clok da cpu*/
/*========================================*/
long clokCPU;
unsigned long CLCPU = 0; 

void setup() {
 Serial.begin(9600);
 Serial.println(F("tudo ok"));
 display.init();
 display.flipScreenVertically(); 
 DistrictCM(2,0,0,2000,0,-128,0,0,-1);  
 //delayCPU = millis();
 anima = millis();
 
//recomendo usa o ESP a 160MHZ
//DistrictCM(1,2,3,4,5,6,7,8,9);//comando para manipular o LCD.
//1 eo ID da imagem, tudo explicado perto do final.
//2 nada ainda, a ideia era seleciona o FPS.
//3 e comando, ser colocar 1 a tela atualiza.
//4 en quantos millis segundo e para terminar animaçao.
//5 onde image/string começa no eixo X.
//6 onde image/string começa no eixo Z.
//7 onde image/string termina no eixo X.
//8 onde image/string termina no eixo Z.
//9 quando voce seleciona a imagem ID ficar ocupando a memoria, 
//para porder tira a imagen na memoria e sor colocar o numero dela negativo,
//o maximo de objetos independente na tela e 19 

//feito por konyzen
}
void loop() {
  District_EGLG();
  
 if((millis() - anima) > 2000){
     if(data_PRIC[2]== false){
         data_PRIC[2] = true;
         delayCPU = millis();
         PM = true;
        }
    }
 if((millis() - anima) > 4000){
     if(data_PRIC[3]== false){
         data_PRIC[3] = true;
         olhoN=3;
        }
    }
 if((millis() - anima) > 4500){
     if(data_PRIC[4]== false){
         data_PRIC[4] = true;
         olhoN =1;
        }
    }
 if((millis() - anima) > 4700){
     if(data_PRIC[5]== false){
         data_PRIC[5] = true;
         olhoN =3;
        }
    }
 if((millis() - anima) > 5000){
     if(data_PRIC[6]== false){
         data_PRIC[6] = true;
         fala = "oi";
         DT = 90;
         bocaN=3;
        }
    }
 if((millis() - anima) > 5300){
     if(data_PRIC[7]== false){
         data_PRIC[7] = true;
         bocaN=1;
        }
    }
 if((millis() - anima) > 6700){
     if(data_PRIC[8]== false){
         data_PRIC[8] = true;
         olhoN=2;
         bocaN=3;
         fala = "e so um";
        }
    }
 if((millis() - anima) > 7000){
     if(data_PRIC[9]== false){
         data_PRIC[9] = true;
         bocaN=1;
        }
    }
 if((millis() - anima) > 8000){
     if(data_PRIC[10]== false){
         data_PRIC[10] = true;
         bocaN=3;
         fala = "TESTE";
        }
    }
 if((millis() - anima) > 8300){
     if(data_PRIC[11]== false){
         data_PRIC[11] = true;
         bocaN=1;
        }
    }
 if((millis() - anima) > 11000){
     if(data_PRIC[12]== false){
         data_PRIC[12] = true;
         fala = "fui";
         olhoN =3;
         bocaN=3;
        }
    }
 if((millis() - anima) > 11300){
     if(data_PRIC[13]== false){
         data_PRIC[13] = true;
         bocaN=1;

        }
    }
 if((millis() - anima) > 12500){
     if(data_PRIC[14]== false){
         data_PRIC[14] = true;
         PM = false;
        }
    }
 if((millis() - anima) > 12500){
     if(data_PRIC[15]== false){
         data_PRIC[15] = true;
         fala = " ";
         DistrictCM(2,0,0,2000,0,0,0,-128,0);  
        } 
    }
 
if((PM == true)&&(millis() - delayCPU) < 500){
     if(data_PRIC[0]== false){
         data_PRIC[0] = true;
         DistrictCM(2,0,0,500,0,0,0,-5,-1);  
        }
    }
 
if((PM == true)&&(millis() - delayCPU) > 500){
     if(data_PRIC[1]== false){
         data_PRIC[1] = true;  
         DistrictCM(1,0,0,500,0,-5,0,0,-2); 
        }
    }
if((PM == true)&&(millis() - delayCPU) > 1000){
     delayCPU = millis();
     data_PRIC[0] = false;
     data_PRIC[1] = false;
 }


 
 clokCPU = millis()-CLCPU;
 CLCPU = millis(); 
 //Serial.println(" ");
}
/*=============================================================*/
void DistrictCM(int OB_PC,int DR_PC,int TI_PC,long VL_PC,int XI_PC,int ZI_PC,int XF_PC,int ZF_PC,int OPGL_PC){
/*=============================================================*/  
byte DATAG1;

for(DATAG1=1;DATAG1 <20;DATAG1=DATAG1 + 1){
     if(ocupadoGR[DATAG1] == false){
         delayGRAZ[DATAG1] = millis();
         delayGRAX[DATAG1] = millis();
         cors[DATAG1] = millis();
         OB_DATA[DATAG1] = OB_PC;
         VL_DATA[DATAG1] = VL_PC;
         XI_DATA[DATAG1] = XI_PC*1000;
         ZI_DATA[DATAG1] = ZI_PC*1000;
         XF_DATA[DATAG1] = XF_PC*1000;
         ZF_DATA[DATAG1] = ZF_PC*1000;
         OPGL[DATAG1] = OPGL_PC;
         ocupadoGR[DATAG1] = true;     
         //=============CL_Z=============///
         if((ZF_DATA[DATAG1]!=0)||(ZI_DATA[DATAG1]!=0)){
             int ZF_DATA_TP = ZF_DATA[DATAG1]/1000;
             int ZI_DATA_TP = ZI_DATA[DATAG1]/1000;
             if(ZI_DATA_TP < 0){
                 ZI_DATA_TP = -1*ZI_DATA_TP; 
                }
             if(ZF_DATA_TP < 0){
                 ZF_DATA_TP = -1*ZF_DATA_TP;
                }
             int Z_TMP_S;
             Z_TMP_S = ZI_DATA_TP + ZF_DATA_TP;
             CLZ[DATAG1] = VL_DATA[DATAG1]/Z_TMP_S;
            } 
         //=============CL_X=============// 
         if((XF_DATA[DATAG1]!=0)||(XI_DATA[DATAG1]!=0)){
             int XF_DATA_TP = XF_DATA[DATAG1]/1000;
             int XI_DATA_TP = XI_DATA[DATAG1]/1000;
             if(XI_DATA_TP < 0){
                 XI_DATA_TP = -1*XI_DATA_TP; 
                }
             if(XF_DATA_TP < 0){
                 XF_DATA_TP = -1*XF_DATA_TP;
                }
             int X_TMP_S;
             X_TMP_S = XI_DATA_TP + XF_DATA_TP; 
             CLX[DATAG1] = VL_DATA[DATAG1]/X_TMP_S; 
            }
         DATAG1=19;
        }
    }
}
/*=============================================================*/
void District_EGLG(){
static boolean Pcirc;
static boolean ATLP;
static byte LUP;

static int OPLCD_MST[20];
static int OBLCD_X1[20];
static int OBLCD_Z1[20];
static long LEG_Z;
static long LEG_X;
long velocidade_PIXX=0;
long velocidade_PIXZ=0;
 for(LUP = 1;LUP < 20;LUP=LUP+1){
     if(ocupadoGR[LUP] == true){ 
      
         if((CLZ[LUP]>1)&&(millis()-delayGRAZ[LUP] >= CLZ[LUP])){//CL-Z 
             LEG_Z=millis()-delayGRAZ[LUP];
             delayGRAZ[LUP]=millis();  
             float cltZ2;
             cltZ2=(float)LEG_Z/(float)CLZ[LUP];
             velocidade_PIXZ = cltZ2*1000;
             LEG_Z = 0;
             Pcirc=true;
       
             ATLP=true;
             if((ZI_DATA[LUP] < ZF_DATA[LUP])&&(ZI_DATA[LUP] != ZF_DATA[LUP])){
                 ZI_DATA[LUP] = ZI_DATA[LUP] + velocidade_PIXZ;
                 if(ZF_DATA[LUP] < ZI_DATA[LUP]){
                     ZI_DATA[LUP] = ZF_DATA[LUP];    
                    }
                } 
             if((ZI_DATA[LUP] > ZF_DATA[LUP])&&(ZI_DATA[LUP] != ZF_DATA[LUP])){
                 ZI_DATA[LUP] = ZI_DATA[LUP] - velocidade_PIXZ;
                 if(ZF_DATA[LUP] > ZI_DATA[LUP]){
                     ZI_DATA[LUP] = ZF_DATA[LUP];
                    } 
                }
             if(OB_DATA[LUP] != 0){
                 OPLCD_MST[OB_DATA[LUP]]= true;
                 OBLCD_X1[OB_DATA[LUP]] = XI_DATA[LUP]/1000;
                 OBLCD_Z1[OB_DATA[LUP]] = -1*ZI_DATA[LUP]/1000;
                }
  
            }
            
         if((CLX[LUP]>1)&&(millis()-delayGRAX[LUP]>=CLX[LUP])){//CL-X 
            LEG_X=millis()-delayGRAX[LUP];
             delayGRAX[LUP]=millis();      
             float cltX2;
             cltX2=(float)LEG_X/(float)CLX[LUP];
             velocidade_PIXX = cltX2*1000;
             LEG_X = 0; 
             Pcirc=true;
       
             ATLP=true;
             if((XI_DATA[LUP] < XF_DATA[LUP])&&(XI_DATA[LUP] != XF_DATA[LUP])){
                 XI_DATA[LUP] = XI_DATA[LUP] + velocidade_PIXX; 
                 if(XF_DATA[LUP] < XI_DATA[LUP]){
                     XI_DATA[LUP] = XF_DATA[LUP];
                    }
                }
             if((XI_DATA[LUP] > XF_DATA[LUP])&&(XI_DATA[LUP] != XF_DATA[LUP])){
             XI_DATA[LUP] = XI_DATA[LUP] - velocidade_PIXX;
                 if(XF_DATA[LUP] > XI_DATA[LUP]){
                     XI_DATA[LUP] = XF_DATA[LUP];
                    } 
                }
             if(OB_DATA[LUP] != 0){
                 OPLCD_MST[OB_DATA[LUP]]= true;
                 OBLCD_X1[OB_DATA[LUP]] = XI_DATA[LUP]/1000;
                 OBLCD_Z1[OB_DATA[LUP]] = -1*ZI_DATA[LUP]/1000;
                }
            }    
    
   
            
       
         if(Pcirc == true){     


             Pcirc=false;
             if((OPGL[LUP] > 0)&&(OPGL[LUP] &= 0)){//positivo  
                 OPLCD_MST[OPGL[LUP]] = true; 
                 OPGL[LUP]=0; 
                }else{//negativo  
                 OPLCD_MST[OPGL[LUP]*-1] = false;
                 OBLCD_X1[OPGL[LUP]*-1]=0;
                 OBLCD_Z1[OPGL[LUP]*-1]=0;
                 OPGL[LUP] = 0;
                } 
             //===========================//     
             /*
             OPLCD_MST[] é onde vai fica os objeto que vai se movimenta por igual.
       caso queira 2 ou mai imagem se movimentando de forma diferente
       vai ter que ser criado mais OPLCD_MST[] amais
       OPLCD_MST[1]
             OPLCD_MST[2]
       
       OBLCD_X1[] OBLCD_Z1[]  e a variável que vai ficar modificando ate a posição desejada.
             o numero entre os [] ten que ser o mesmo do OPLCD_MST[]
       
             */      
             if(OPLCD_MST[1] == true){
                 //Serial.println("1");
         
                 display.setColor(WHITE);
                 display.drawXbm(OBLCD_X1[1] + 0,OBLCD_Z1[1] + 0, 128, 64,Spooky1);
                 display.setFont(ArialMT_Plain_10);
                 display.drawString(OBLCD_X1[1]+DT,OBLCD_X1[1]+0,fala);
         
                 switch (olhoN) {
                     case 1:   
                         display.drawXbm(OBLCD_X1[1] + 42,OBLCD_Z1[1] + 20, 30, 4,olho1_3);
                     break;
                     case 2:   
                         display.drawXbm(OBLCD_X1[1] + 43,OBLCD_Z1[1] + 20, 30, 5,olho2_3);
                     break;
                     case 3:   
                         display.drawXbm(OBLCD_X1[1] + 44,OBLCD_Z1[1] + 17, 30, 9,olho3_3);
                     break;
                    }
                 switch (bocaN) {
                     case 1:   
                         display.drawXbm(OBLCD_X1[1] + 52,OBLCD_Z1[1] + 26, 9, 3,boca1_3);
                     break;
                     case 2:   
                         display.drawXbm(OBLCD_X1[1] + 51,OBLCD_Z1[1] + 26, 12, 5,boca2_3);
                     break;
                     case 3:   
                         display.drawXbm(OBLCD_X1[1] + 51,OBLCD_Z1[1] + 26, 12, 6,boca3_3);
                     break;
                    } 
                }
             //===========================//   
             if(OPLCD_MST[2] == true){
                 //Serial.println("2");
                 display.setColor(WHITE);
                 display.drawXbm(OBLCD_X1[2] + 0,OBLCD_Z1[2] + 0, 128, 64,Spooky2);
                 display.setFont(ArialMT_Plain_10);
                 display.drawString(OBLCD_X1[2]+DT,OBLCD_X1[2]+0,fala);
                 switch (olhoN) {
                     case 1:   
                         display.drawXbm(OBLCD_X1[2] + 42,OBLCD_Z1[2] + 20, 30, 4,olho1_3);
                     break;
                     case 2:   
                         display.drawXbm(OBLCD_X1[2] + 43,OBLCD_Z1[2] + 20, 30, 5,olho2_3);
                     break;
                     case 3:   
                         display.drawXbm(OBLCD_X1[2] + 44,OBLCD_Z1[2] + 17, 30, 9,olho3_3);
                     break;
                    }
                 switch (bocaN) {
                     case 1:   
                         display.drawXbm(OBLCD_X1[2] + 52,OBLCD_Z1[2] + 26, 9, 3,boca1_3);
                     break;
                     case 2:   
                         display.drawXbm(OBLCD_X1[2] + 51,OBLCD_Z1[2] + 26, 12, 5,boca2_3);
                     break;
                     case 3:   
                         display.drawXbm(OBLCD_X1[2] + 51,OBLCD_Z1[2] + 26, 12, 6,boca3_3);
                     break;
                    }                                                   
                }
             if((millis() - cors[LUP]) >= VL_DATA[LUP]){
                 ZI_DATA[LUP] = ZF_DATA[LUP];
                 XI_DATA[LUP] = XF_DATA[LUP];
                  ATLP=true;
                  //Serial.print("finalize agora ");
                  //Serial.println(millis() - cors[LUP]);
                }  
             if((ZI_DATA[LUP] == ZF_DATA[LUP])&&(XI_DATA[LUP] == XF_DATA[LUP])){
                 if(ocupadoGR[LUP] == 1){
                     //Serial.println("fin_MS");
                     ocupadoGR[LUP] = false;
                     OB_DATA[LUP] = 0;
                     VL_DATA[LUP] = 0;
                     XI_DATA[LUP] = 0;
                     ZI_DATA[LUP] = 0;
                     XF_DATA[LUP] = 0;
                     ZF_DATA[LUP] = 0;
                     //delayGRAZ[LUP] = 0;
                    }
                } 
            }       
        }
     if((LUP == 19)&&(ATLP == true)){
         ATLP=false;
         //Serial.println("atualiza");
         display.display();
         display.clear();
        }
    }
}
