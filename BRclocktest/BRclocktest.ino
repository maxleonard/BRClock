
//Output pins
const TM_OFF = 2;
const TR_OFF = 3;
const BR_OFF = 4;
const BM_OFF = 5;
const TM_ON = 6;
const TR_ON = 7;
const BR_ON = 8;
const BM_ON = 2
const BL_ON = 3;
const TL_ON = 4;
const M_ON = 5;
const BL_OFF = 6;
const TL_OFF = 7;
const M_OFF = 8;

const D0 = 2;
const D1 = 3; 
const D2 = 4;
const D3 = 5;
const D4 = 6;
const D5 = 7;

const L0 = 9
const L1 = 10
const L2 = 11

int hours =0 ;
int mins = 0 ;
int seconds =0;


void setPins(int firstBlock[],int secondBlock[], int size1, int size2)
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

void setDigit(digit,val){
  // possibly some diff code here to save work. 
  
  digitalWrite(digit,HIGH);

  switch(val)
  {
    case: 0 
      setPins([0,0,0,0,1,1,1],7,[0,1,1,1,0,0,0],7);
      break;
    case: 1
      setPins([1,0,0,1,0,1,1],7,[0,0,0,0,1,1,1],7);
      break;
    case: 2
          setPins([0,0,1,0,1,1,0],7,[1,0,1,1,1,0,0],7);
          break;
    case: 3
          setPins([0,0,0,0,1,1,1],7,[1,0,0,1,1,1,0],7);
          break;
    case: 4
          setPins([1,0,0,1,0,1,1],7,[0,0,1,1,1,0,0],7);
          break;
    case: 5
          setPins([0,1,0,0,1,0,1],7,[1,0,1,1,1,0,0],7);
          break;
    case: 6
          setPins([0,1,0,0,1,0,1],7,[1,1,1,1,0,0,0],7);
          break;
    case: 7
          setPins([0,0,0,1,1,1,1],7,[0,0,0,0,1,1,1],7);
          break;
    case: 8
          setPins([0,0,0,0,1,1,1],7,[1,1,1,1,0,0,0],7);
          break;
    case: 9
          setPins([0,0,0,1,1,1,1],7,[0,0,1,1,1,0,0],7);
          break;
     default:
      break;

      delay(100);
      digitalWrite(digit,LOW);
   
  }
  
}

void setSeconds()
{
  int units = seconds % 10;
  int tens = seconds / 10;

  setDigit(D4,tens);
  setDigit(D3,units);
  
}

void setMins()
{
  
}


void setHours()
{
  
}


void setup() {
    // turn everything off first.
    for(int i=2; i<11; i++)
    {
      pinMode(i, OUTPUT);
      digitalWrite(i, LOW);
    }
}




void loop() { 

  tick();
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


