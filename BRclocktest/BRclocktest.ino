
//Output pins
const int TM_OFF = 2;
const int TR_OFF = 3;
const int BR_OFF = 4;
const int BM_OFF = 5;
const int TM_ON = 6;
const int TR_ON = 7;
const int BR_ON = 8;

const int BM_ON = 2;
const int BL_ON = 3;
const int TL_ON = 4;
const int M_ON = 5;
const int BL_OFF = 6;
const int TL_OFF = 7;
const int M_OFF = 8;

const int D0 = 2;
const int D1 = 3; 
const int D2 = 4;
const int D3 = 5;
const int D4 = 6;
const int D5 = 7;

const int L0 = 9;
const int L1 = 10;
const int L2 = 11;

int hours =0 ;
int mins = 0 ;
int seconds =0;


void setPins(int* firstBlock,  int size1, int* secondBlock, int size2)
{
  digitalWrite(L0,HIGH);
  for (int i = 0; i<size1; i++)
  {
    digitalWrite(i+2,firstBlock[i]);
  }
  digitalWrite(L0,LOW);

  digitalWrite(L1,HIGH);
  for (int i = 0; i<size2; i++)
  {
    digitalWrite(i+2,secondBlock[i]);
  }
  digitalWrite(L1,LOW);

}


void  tick(){

  seconds++;
  if(seconds>59)
    {
      seconds=0;
      mins++;
      if(mins>59)
      {
        mins=0;
        hours++;

        if(hours>23)
        hours=0;
      }
    }
  
}

void setDigit(int digit, int val){
  // possibly some diff code here to save work. 

  Serial.print(digit);
  Serial.print(" ");
  Serial.print(val);
  Serial.print("\n");
  digitalWrite(L2,HIGH);       
  digitalWrite(digit,HIGH); 
  digitalWrite(L2,LOW);       
      

     if (val==0){
      int p1[] = {0,0,0,0,1,1,1};
      int p2[] = {1,1,1,0,0,0,1};
      setPins(p1,7,p2,7);
     }
     else if (val==1) {
      int p1[] = {1,0,0,1,0,1,1};
      int p2[] = {0,0,0,0,1,1,1};
      setPins(p1,7,p2,7);
     }

     else if (val==2) {
      int p1[] = {0,0,1,0,1,1,0};
      int p2[] = {1,0,1,1,1,0,0};
      setPins(p1,7,p2,7);
     }

     else if (val==3) {
      int p1[] = {0,0,0,0,1,1,1};
      int p2[] = {1,0,0,1,1,1,0};
      setPins(p1,7,p2,7);
     }

     else if (val==4) {
      int p1[] = {1,0,0,1,0,1,1};
      int p2[] = {0,0,1,1,1,0,0};
      setPins(p1,7,p2,7);
     }

     else if (val==5) {
      int p1[] = {0,1,0,0,1,0,1};
      int p2[] = {1,0,1,1,1,0,0};
      setPins(p1,7,p2,7);
     }

     else if (val==6) {
      int p1[] = {0,1,0,0,1,0,1};
      int p2[] = {1,1,1,1,0,0,0};
      setPins(p1,7,p2,7);
     }

     else if (val==7) {
      int p1[] = {0,0,0,1,1,1,1};
      int p2[] = {0,0,0,0,1,1,1};
      setPins(p1,7,p2,7);
     }

     else if (val==8) {
      int p1[] = {0,0,0,0,1,1,1};
      int p2[] = {1,1,1,1,0,0,0};
      setPins(p1,7,p2,7);
      
     }
     else if (val==9) {
      int p1[] = {0,0,0,1,1,1,1};
      int p2[] = {0,0,1,1,1,0,0};
      setPins(p1,7,p2,7);
      
     }
 
      delay(100);
      digitalWrite(L2,HIGH);       
      digitalWrite(digit,LOW); 
      digitalWrite(L2,LOW);}

void setSeconds()
{
  int units = seconds % 10;
  int tens = seconds / 10;

  setDigit(D4,tens);
  setDigit(D5,units);
  
}

void setMins()
{
  int units = mins % 10;
  int tens = mins / 10;

  if(seconds==0)
  { setDigit(D2,tens);
    setDigit(D3,units);
  }
  
  
}


void setHours()
{
  int units = hours % 10;
  int tens = hours / 10;

  if(mins==0 && seconds==0)
  {setDigit(D0,tens);
  setDigit(D1,units);
  }
  
}


void setup() {
    // turn everything off first.

    for (int i=L0; i<L2+1; i++)
          {digitalWrite(i, HIGH);}

    
    for(int i=2; i<L0; i++)
    {
      pinMode(i, OUTPUT);
      digitalWrite(i, LOW);
    }

    for (int i=L0; i<L2+1; i++)
          {digitalWrite(i, LOW);}

    //

    Serial.begin(9600);      // open the serial port at 9600 bps:    
}




void loop() { 

  tick();
  Serial.print(seconds);
  Serial.print(mins);
  Serial.print(hours);
  Serial.print("\n\n");

  setSeconds();
  setMins();
  setHours();

  delay(900);

}

/*

 digitalWrite(L0,HIGH);
      digitalWrite(TM_OFF,LOW);
      digitalWrite(TR_OFF,LOW);
      digitalWrite(BR_OFF,LOW);
      digitalWrite(BM_OFF,LOW);
      digitalWrite(TM_ON,LOW);
      digitalWrite(TR_ON,LOW);
      digitalWrite(BR_ON,LOW);
      digitalWrite(L0,LOW);

      digitalWrite(L1,HIGH);
      digitalWrite(BM_ON,LOW);
      digitalWrite(BL_ON,LOW);
      digitalWrite(TL_ON,LOW);
      digitalWrite(M_ON,LOW);
      digitalWrite(BL_OFF,LOW);
      digitalWrite(TL_OFF,LOW);
      digitalWrite(M_OFF,LOW);
      digitalWrite(L1,LOW);*/

/*
digitalWrite(L0,HIGH);
      digitalWrite(TM_OFF,LOW);
      digitalWrite(TR_OFF,LOW);
      digitalWrite(BR_OFF,LOW);
      digitalWrite(BM_OFF,LOW);
      digitalWrite(TM_ON,HIGH);
      digitalWrite(TR_ON,HIGH);
      digitalWrite(BR_ON,HIGH);
      digitalWrite(L0,LOW);

      digitalWrite(L1,HIGH);
      digitalWrite(BM_ON,LOW);
      digitalWrite(BL_ON,HIGH);
      digitalWrite(TL_ON,HIGH);
      digitalWrite(M_ON,HIGH);
      digitalWrite(BL_OFF,LOW);
      digitalWrite(TL_OFF,LOW);
      digitalWrite(M_OFF,LOW);
      digitalWrite(L1,LOW);

*/










/* switch(val)
  {
    case 0:
     // int p1[] = {0,0,0,0,1,1,1};
   //   int p2[] = {0,0,0,0,1,1,1};
   //   setPins(p1,7,p2,7);
      break;
    case 1:
      setPins([1,0,0,1,0,1,1],7,[0,0,0,0,1,1,1],7);
      break;
    case 2:
          setPins([0,0,1,0,1,1,0],7,[1,0,1,1,1,0,0],7);
          break;
    case 3:
          setPins([0,0,0,0,1,1,1],7,[1,0,0,1,1,1,0],7);
          break;
    case 4:
          setPins([1,0,0,1,0,1,1],7,[0,0,1,1,1,0,0],7);
          break;
    case 5:
          setPins([0,1,0,0,1,0,1],7,[1,0,1,1,1,0,0],7);
          break;
    case 6:
          setPins([0,1,0,0,1,0,1],7,[1,1,1,1,0,0,0],7);
          break;
    case 7:
          setPins([0,0,0,1,1,1,1],7,[0,0,0,0,1,1,1],7);
          break;
    case 8:
          setPins([0,0,0,0,1,1,1],7,[1,1,1,1,0,0,0],7);
          break;
    case 9:
          setPins([0,0,0,1,1,1,1],7,[0,0,1,1,1,0,0],7);
          break;
       */

