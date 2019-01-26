#include <LiquidCrystal.h>
#include <Keypad.h>

bool ledState = 0;
long prevMillis = 0;
long led_delay = 250;
char key;
unsigned long currentMillis =0;
unsigned long startMillis = 0;
int period = 1000;
int temps = 0;
 int minu;
 int sec;
const byte ROWS = 4; //nombre de lignes
const byte COLS = 3; //nombre de colonnes

char keys[ROWS][COLS] = 
{
{'1', '2', '3'},
{'4', '5', '6'},
{'7', '8', '9'},
{'*', '0', '#'}
};
byte rowPins[ROWS] = {30,31,32,33}; //initialisation des numeros de lignes
byte colPins[COLS] ={34,35,36}; //initialisation des numeros de colonnes

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );



LiquidCrystal lcd(12,11,5,4,3,2);
int redPin = 24;
int greenPin = 25;
int bluePin = 22;

void actualisationTemps(){
         tone(53, 3000);
         lcd.setCursor(6,1);
         lcd.print(minu);
         lcd.print(" : ");
         lcd.print(sec);                          // affiche le temps 
         setColor(255,0,0);
         noTone(53);
         sec--;
         if(sec == 0){
          minu--;
          sec = 59;
         }
         key = keypad.getKey();
}

void setup()
{

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(53, OUTPUT);
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  
 
    
}
 
void loop()
{
 
 key = keypad.getKey();

 

 int r=0;
 int g=0;
 int b=0;
 int mdp = 0;
 int i = 1;
 int pu = 1000;
 int pu2 = 10;
 int nbr_sai = 0;
 int nbr;
 

 int Vf;
 int pu3 = 1000;
 int t;


while(key != '#'){
   if (millis() - prevMillis > led_delay){
      ledState =! ledState;
      digitalWrite(greenPin, ledState);
      prevMillis = millis();
      lcd.setCursor(4,0);
      lcd.print("appuyer sur #");
      lcd.setCursor(3,1);
      lcd.print("Pour commencer");
   } 
   key = keypad.getKey();  
 }

 lcd.clear();
 setColor(0,0,0);
 lcd.setCursor(0,0);
 lcd.print("Saisir un code : ");
 delay(1500);
 lcd.clear();
         
         for (i=1;i<=4;i++)
          {    
           do
            {
             nbr_sai= keypad.getKey(); 
            } 
            while (nbr_sai == NO_KEY);
                  
           nbr_sai=nbr_sai-48;
           nbr_sai=nbr_sai*pu;
           mdp=nbr_sai+mdp;
           lcd.clear();
           lcd.print(mdp);
           pu=pu/10;
         }
    
    lcd.clear();
    lcd.print("Votre code est :");
    lcd.setCursor(0,1);
    lcd.print(mdp);
    delay(3000);
    lcd.clear();

   lcd.setCursor(0,0);
   lcd.print("choisir temps : ");
   delay(1500);
   lcd.clear();
  

         for (i=1;i<=2;i++)
           {
             do
              {
               nbr = keypad.getKey(); 
              } 
             while (nbr == NO_KEY);
            
             nbr=nbr-48;
             nbr=nbr*pu2;
             temps = nbr+temps;
             minu = temps-1;
             sec = 59;
             lcd.clear();
             lcd.print(temps);
             pu2 = pu2/10;
             
           }

            lcd.clear();
            lcd.print("votre temps : ");
            lcd.print(temps);
            lcd.setCursor(17,0);
            lcd.print("min");
            delay(3000);
            lcd.clear();

            

      currentMillis = millis();
      startMillis = millis();
      actualisationTemps(); //intialisation pour calcul millis

      
      while(1){
       currentMillis = millis();
       if(key == '*')
        {

              lcd.clear();
              noTone(53);
              setColor(0,0,0);
              lcd.print("CODE : "); 
              delay(1000);
              lcd.clear();
              
              for (i=1;i<=4;i++)
              {    
                 do
                 {
                   nbr_sai= keypad.getKey(); 
                 } 
               while (nbr_sai == NO_KEY);
                  
               nbr_sai=nbr_sai-48;
               nbr_sai=nbr_sai*pu3;
               Vf=nbr_sai+Vf;
               lcd.clear(); 
               lcd.print(Vf);
               pu3=pu3/10;     
              }

              
              lcd.clear();

              
            if (Vf == mdp)
             {
               lcd.setCursor(6,1);
               lcd.print("CODE BON");
               delay(50);
               tone(53, 2000);
               delay(250);
               tone(53, 3000);
               delay(150);
               noTone(53);
               delay(3000);
               lcd.clear();
               goto fin;       
             }
           else
             {
               lcd.setCursor(4,1);
               lcd.print("CODE MAUVAIS");
               tone(53, 2000);
               delay(250);
               noTone(53);
               tone(53, 2000);
               delay(250);
               noTone(53);
               tone(53, 2000);
               delay(250);
               noTone(53);
               tone(53, 2000);
               delay(250);
               noTone(53);
               delay(3000);
               lcd.clear();
               pu3=1000;
               Vf=0; 
               key = ' '; 
             }  
        }
        if(currentMillis - startMillis >= period){
          actualisationTemps();
          startMillis = currentMillis;
        }
        
        
      }
                
      
////////////////////////////////////////////////////////////////////////////////////////////
            
          delay(500);
          setColor(0,0,0);
          noTone(53);
          delay(500);
          lcd.clear();
      
   
 lcd.setCursor(8,1);
lcd.print("BOOM");
for (t=3000;t>=0;t--)
  {
    tone(53, t);
    
  }
for (t=0;t<=3000;t++)
  {
    tone(53, t);
    
  }
for (t=3000;t>=0;t--)
  {
    tone(53, t);
    
  }
for (t=0;t<=3000;t++)
  {
    tone(53, t);
    
  }
for (t=3000;t>=0;t--)
  {
    tone(53, t);
    
  }
for (t=0;t<=3000;t++)
  {
    tone(53, t);
    
  }
for (t=3000;t>=0;t--)
  {
    tone(53, t);
    
  }
for (t=0;t<=3000;t++)
  {
    tone(53, t);
    
  }  


noTone(53);        
lcd.clear(); 

fin:;
  
}   
    
      

 

 
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
