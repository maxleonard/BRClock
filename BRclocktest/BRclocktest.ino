
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

const int D0 = 6;
const int D1 = 4; 
const int D2 = 2;
const int D3 = 3;
const int D4 = 5;
const int D5 = 7;

const int L0 = 9;
const int L1 = 10;
const int L2 = 11;

int hours =0 ;
int mins = 0 ;
int seconds =0;

int ticks;
boolean ffprev = false;

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

void setPins(int* firstBlock,  int size1, int* secondBlock, int size2)
{
  digitalWrite(L0,HIGH);
  for (int i = 0; i<size1; i++)
  {
    digitalWrite(i+2,firstBlock[i]);
    //Serial.print("blk1:");
    //Serial.print(i+2);
    //Serial.print(" ");
    //Serial.print(firstBlock[i]);
  }
  digitalWrite(L0,LOW);

  digitalWrite(L1,HIGH);
  for (int i = 0; i<size2; i++)
  {
    //Serial.print(" blk2:");
    //Serial.print(i+2);
    //Serial.print(" ");
    //Serial.print(secondBlock[i]);
    
    digitalWrite(i+2,secondBlock[i]);
  }
  digitalWrite(L1,LOW);

  //switch all residual pins off
  for (int i = 0; i<size2; i++)
  {
   digitalWrite(i+2,LOW);
  }


}


void setDigit(int digit, int val){
  // possibly some diff code here to save work. 
   
     
     if (val==0){
      int p1[] = {0,0,0,0,1,1,1};
      int p2[] = {1,1,1,0,0,0,1};
      setPins(p1,7,p2,7);
     }
     else if (val==1) {
      int p1[] = {1,0,0,1,0,0,0};
      int p2[] = {0,0,0,0,1,1,0};
      setPins(p1,7,p2,7);
     }

     else if (val==2) {
      int p1[] = {0,0,1,0,1,1,0};
      int p2[] = {1,1,0,1,0,0,0};
      setPins(p1,7,p2,7);
     }

     else if (val==3) {
      int p1[] = {0,0,0,0,0,0,1};
      int p2[] = {0,0,0,0,1,1,0};
      setPins(p1,7,p2,7);
     }

     else if (val==4) {
      int p1[] = {1,0,0,1,0,1,0};
      int p2[] = {0,0,1,1,0,0,0};
      setPins(p1,7,p2,7);
     }

     else if (val==5) {
      int p1[] = {0,1,0,0,1,0,1};
      int p2[] = {1,0,1,1,1,0,0};
      setPins(p1,7,p2,7);
     }

     else if (val==6) {
      int p1[] = {0,0,0,0,0,0,0};
      int p2[] = {0,1,0,0,0,0,0};
      setPins(p1,7,p2,7);
     }

     else if (val==7) {
      int p1[] = {0,0,0,1,1,1,1};
      int p2[] = {0,0,0,0,1,1,1};
      setPins(p1,7,p2,7);
     }

     else if (val==8) {
      int p1[] = {0,0,0,0,0,0,0};
      int p2[] = {1,1,1,1,0,0,0};
      setPins(p1,7,p2,7);
      
     }
     else if (val==9) {
      int p1[] = {0,0,0,1,1,1,1};
      int p2[] = {0,0,0,0,1,0,0};
      setPins(p1,7,p2,7);
      
     }

     int d=220;
     if(digit==D4 || digit == D5)
      d=130;
    
     digitalWrite(L2, HIGH);
     digitalWrite(digit,HIGH);
     delay(d);
     digitalWrite(digit,LOW);
     digitalWrite(L2, LOW);


  }

void setSeconds()
{
  int units = seconds % 10;
  int tens = seconds / 10;

  if(units == 0)
  {setDigit(D4,tens);}
  
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
  
    for(int j=2; j<12; j++)
      {pinMode(j, OUTPUT);}


    for (int i=9; i<12; i++)
          {digitalWrite(i, HIGH);
            for(int j=2; j<9; j++)
            {
              digitalWrite(j, LOW);
            }
            digitalWrite(i, LOW);
          }

           setDigit(D0,0);
            setDigit(D1,0);
             setDigit(D2,0);
              setDigit(D3,0);
               setDigit(D4,0);
                setDigit(D5,0);
    
    Serial.begin(9600);      // open the serial port at 9600 bps:    

    
}




void loop() { 

  // read inputs
  int speedpot = analogRead(0);
  boolean ffbutton = false;


  //1024 == full  == 2
  // 0 = quickest == 50

  float decimator = (((float)speedpot /1024.0) * 500.0);

  //speed
  //tick++
  //mental / not


  if(analogRead(1) > 1000) 
    { ffbutton = true;}
  
  if(ffbutton == true && ffprev == false)
    {
      ticks-= 10000;
    }

    ffprev = ffbutton;


  delay(1);
  ticks=ticks-(int)decimator;
  Serial.print(decimator);
    Serial.print(" ");
          Serial.print(ticks);


Serial.print("\n");

  if(ticks<=0)
    {   tick();

    Serial.print("\n TICK:");

      Serial.print(ticks);
          Serial.print("\n:");

      setSeconds();
      setMins();
      setHours();
      ticks=10000;
    }



   for (int i=9; i<12; i++)
          {digitalWrite(i, HIGH);
            for(int j=2; j<9; j++)
            {
              digitalWrite(j, LOW);
            }
            digitalWrite(i, LOW);
          }

}


