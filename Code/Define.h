#define ROW_1 7   //2 
#define ROW_2 10  //3
#define ROW_3 5   //4 
#define ROW_4 11  //5 
#define ROW_5 A2  //6 
#define ROW_6 4   //7
#define ROW_7 A0  //8 
#define ROW_8 A5  //9 

#define COL_1 A1  //10 
#define COL_2 9   //11
#define COL_3 8   //12 
#define COL_4 A4  //13 
#define COL_5 6   //A0 
#define COL_6 A3  //A1 
#define COL_7 13  //A2 
#define COL_8 12  //A3 

#define NutDau digitalRead(1)
#define NutGiua digitalRead(0)
#define NutKeCuoi digitalRead(2)
#define NutCuoi digitalRead(3)
#define Push 0

#define default_time  20
#define fast 5
#define mid 25
#define low 40

float timeCount = 0;

int Check_Nhan_Giu_Nut = 0;   // Bien kiem tra co an giu nut qua 3s hay k
int Checkback;                        // Bien Check de co the BACK khi dang trong mode SET TIME cho cac chu mac dinh
int Array[30];                // Mot cai mang chua 30 ki tu
int Buffer = 1;               // Ta su dung phan tu cua mang tu phan tu thu 2 ( tuc la = 1)
int _time = 0;                // Bien set time
int id;                       // Bien Id tuong ung voi tung chan cua tung nut : Dau(1) Giua(0) Ke(2) Cuoi(3)


const byte rows[] = {
    ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};

// The display buffer
// It's prefilled with a smiling face (1 = ON, 0 = OFF)
byte TEST[] = {B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};

byte TIM1[] = {B00101000,B01010100,B01000100,B00101000,B00010000,B00000000,B00000000,B00000000};
byte TIM2[] = {B00000000,B01010000,B10101000,B10001000,B01010000,B00100000,B00000000,B00000000};
byte TIM3[] = {B00000000,B00000000,B01010000,B10101000,B10001000,B01010000,B00100000,B00000000};
byte TIM4[] = {B00000000,B00000000,B00000000,B00101000,B01010100,B01000100,B00101000,B00010000};
byte TIM5[] = {B00000000,B00000000,B00000000,B00010100,B00101010,B00100010,B00010100,B00001000};
byte TIM6[] = {B00000000,B00000000,B00001010,B00010101,B00010001,B00001010,B00000100,B00000000};
byte TIM7[] = {B00000000,B00001010,B00010101,B00010001,B00001010,B00000100,B00000000,B00000000};
byte TIM8[] = {B00010100,B00101010,B00100010,B00010100,B00001000,B00000000,B00000000,B00000000};

byte SAD[] = {B00000000,B01100110,B01100110,B00000000,B00011000,B00100100,B01000010,B00000000};
byte Chamthan[] = {B00000000,B01010100,B01010100,B01010100,B01010100,B00000000,B01010100,B00000000};
byte Bacham[] = {B00000000,B00000010,B00000010,B00000010,B00000010,B00000000,B01111010,B00000000};
byte Alert_Add_Word_OK[] = {B10000001,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10000001};
byte GuidePushDown[] = {B00000000,B00000000,B00100000,B01000000,B11111111,B01000000,B00100000,B00000000};
byte GuidePushSetWord[]={B00000000,B00000000,B00000000,B00000000,B00010000,B10100000,B11000000,B11100000};
byte Clear[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};

byte TimeMenu[] = {B11100000,B11111100,B11111111,B00000000,B00010000,B10100000,B11000000,B11100000};
byte _FAST[] = {B11100000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
byte _MID[] = {B00000000,B11111100,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
byte _LOW[] = {B00000000,B00000000,B11111111,B00000000,B00000000,B00000000,B00000000,B00000000};

byte Behon3[] = {B00010110,B00100001,B01000001,B10000110,B01000001,B00100001,B00010110,B00000000};
byte Behon0[] = {B00010010,B00100101,B01000101,B10000101,B01000101,B00100101,B00010010,B00000000};

byte ModeX1[] = {B10000001,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10000001};
byte ModeX2[] = {B10000001,B01000010,B00000000,B00000000,B00000000,B00000000,B01000010,B10000001};
byte ModeX3[] = {B10000001,B01000010,B00100100,B00000000,B00000000,B00100100,B01000010,B10000001};
byte ModeX4[] = {B10000001,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B10000001};

byte A[] = {B00011000,B00111100,B01100110,B01100110,B01111110,B01111110,B01100110,B01100110};
byte B[] = {B01111100,B01100110,B01100110,B01111100,B01111110,B01100110,B01100110,B01111100};
byte C[] = {B00111110,B01111110,B01100000,B01100000,B01100000,B01100000,B01111110,B00111110};
byte D[] = {B01111000,B01111100,B01100110,B01100110,B01100110,B01100110,B01111100,B01111000};
byte E[] = {B01111110,B01111110,B01100000,B01111110,B01111110,B01100000,B01111110,B01111110};
byte F[] = {B01111110,B01111110,B01100000,B01111100,B01111100,B01100000,B01100000,B01100000};
byte G[] = {B00111000,B01111100,B01100100,B01100000,B01101110,B01100100,B01111100,B00111000};
byte H[] = {B01100110,B01100110,B01100110,B01111110,B01111110,B01100110,B01100110,B01100110};
byte I[] = {B01111110,B01111110,B00011000,B00011000,B00011000,B00011000,B01111110,B01111110};
byte J[] = {B01111110,B01111110,B00011000,B00011000,B00011000,B00011000,B01111000,B01110000};
byte K[] = {B01100110,B01101100,B01111000,B01110000,B01110000,B01111000,B01101100,B01100110};
byte L[] = {B01100000,B01100000,B01100000,B01100000,B01100000,B01100000,B01111110,B01111110};
byte M[] = {B01000010,B01100110,B01111110,B01011010,B01000010,B01000010,B01000010,B01000010};
byte N[] = {B01000110,B01100110,B01100110,B01110110,B01111110,B01101110,B01100110,B01100110};
byte O[] = {B00111100,B01111110,B01100110,B01100110,B01100110,B01100110,B01111110,B00111100};
byte P[] = {B01111000,B01111100,B01100110,B01100110,B01111100,B01111000,B01100000,B01100000};
byte Q[] = {B00111100,B01000010,B01000010,B01000010,B01000010,B01001010,B00111100,B00000010};
byte R[] = {B01111100,B01100110,B01100110,B01101100,B01111000,B01111000,B01101100,B01100110};
byte S[] = {B00111100,B01111110,B01100000,B01111100,B00111110,B00000110,B01111110,B00111100};//{B00111000,B01111100,B01100000,B00110000,B00011000,B00001100,B00111100,B01111000};
byte T[] = {B01111110,B01111110,B00011000,B00011000,B00011000,B00011000,B00011000,B00011000};
byte U[] = {B01100110,B01100110,B01100110,B01100110,B01100110,B01100110,B01111110,B00111100};
byte V[] = {B01100110,B01100110,B01100110,B01100110,B01100110,B01100110,B00111100,B00011000};
byte W[] = {B01000010,B01000010,B01000010,B01000010,B01000010,B01011010,B01011010,B00100100};
byte X[] = {B01100110,B01100110,B01100110,B00111100,B00011000,B00111100,B01100110,B01100110};
byte Y[] = {B01100110,B01100110,B01100110,B01111110,B00111100,B00011000,B00011000,B00011000};
byte Z[] = {B01111110,B01111110,B00000110,B00001100,B00011000,B00110000,B01111110,B01111110};


byte Zero[]   = {B00111100,B01111110,B01100110,B01100110,B01100110,B01100110,B01111110,B00111100}; // Giong chu O
byte One[]    = {B00011000,B00111000,B01111000,B00011000,B00011000,B00011000,B01111110,B01111110}; 
byte Two[]    = {B00111100,B01111110,B01000110,B00001100,B00011000,B00110000,B01111110,B01111110};
byte Three[]  = {B01111100,B01111110,B00000110,B00111110,B00111110,B00000110,B01111110,B01111100};
byte Four[]   = {B00001100,B00011100,B00111100,B01101100,B01111110,B01111110,B00001100,B00001100};
byte Five[]   = {B01111110,B01111110,B01100000,B01111100,B00111110,B00000110,B01111110,B01111100};
byte Six[]    = {B00001100,B00011000,B00110000,B01111100,B01111110,B01100110,B01100110,B00111100};
byte Seven[]  = {B01111110,B01111110,B00000110,B00000110,B00001100,B00011000,B00110000,B01100000}; 
byte Eight[]  = {B00111100,B01100110,B01100110,B00111100,B01111110,B01100110,B01100110,B00111100}; 
byte Nine[]   = {B00111100,B01100110,B01100110,B01111110,B00111110,B00001100,B00011000,B00110000}; 


void setColumns(byte b) {
    digitalWrite(COL_1, (~b >> 0) & 0x01); // Get the 1st bit: 10000000
    digitalWrite(COL_2, (~b >> 1) & 0x01); // Get the 2nd bit: 01000000
    digitalWrite(COL_3, (~b >> 2) & 0x01); // Get the 3rd bit: 00100000
    digitalWrite(COL_4, (~b >> 3) & 0x01); // Get the 4th bit: 00010000
    digitalWrite(COL_5, (~b >> 4) & 0x01); // Get the 5th bit: 00001000
    digitalWrite(COL_6, (~b >> 5) & 0x01); // Get the 6th bit: 00000100
    digitalWrite(COL_7, (~b >> 6) & 0x01); // Get the 7th bit: 00000010
    digitalWrite(COL_8, (~b >> 7) & 0x01); // Get the 8th bit: 00000001
    
    // If the polarity of your matrix is the opposite of mine
    // remove all the '~' above.
}

void  drawScreen(byte buffer2[]){
  // Turn on each row in series
    for (byte i = 0; i < 8; i++) {
    setColumns(buffer2[i]); // Set columns for this specific row
          
        digitalWrite(rows[i], HIGH);
        delay(2); // Set this to 50 or 100 if you want to see the multiplexing effect!
        digitalWrite(rows[i], LOW);
        
    }
}

void SELECT(int _Select) // Co the them truong hop o cuoi
{
    switch (_Select)
        {
          case 0: {
            drawScreen(GuidePushDown);
            break;
          }
          
          case 1: {
           drawScreen(A);
           break; }
           
          case 2: {
           drawScreen(B);
           break; }
           
          case 3: {
           drawScreen(C);
           break; }
           
          case 4: {
           drawScreen(D);
           break; }
           
          case 5: {
           drawScreen(E);
           break; }
           
          case 6: {
           drawScreen(F);
           break; }
           
          case 7: {
           drawScreen(G);
           break; }
           
          case 8: {
           drawScreen(H);
           break; }
           
          case 9: {
           drawScreen(I);
           break; }
           
          case 10: {
           drawScreen(J);
           break; }
           
          case 11: {
           drawScreen(K);
           break; }
           
          case 12: {
           drawScreen(L);
           break; }
           
          case 13: {
           drawScreen(M);
           break; }
           
          case 14: {
           drawScreen(N);
           break; }

            case 15:{
           drawScreen(O);
           break; }

            case 16: {
           drawScreen(P);
           break; }

            case 17: {
           drawScreen(Q);
           break; }

            case 18: {
           drawScreen(R);
           break; }

            case 19: {
           drawScreen(S);
           break; }

            case 20: {
           drawScreen(T);
           break; }

            case 21: {
           drawScreen(U);
           break; }

            case 22: {
           drawScreen(V);
           break; }

            case 23: {
           drawScreen(W);
           break; }

            case 24:{
           drawScreen(X);
           break; }

            case 25:{
           drawScreen(Y);
           break; }
           
            case 26:{
           drawScreen(Z);
           break; }

            case 27:{
           drawScreen(Zero);            //SAD
           break; }

            case 28:{
           drawScreen(One);          //GuidePushSetWord
           break; }                          

            case 29:{
           drawScreen(Two);
           break; }
                  
            case 30:{
           drawScreen(Three);
           break; }

           case 31:{
           drawScreen(Four);
           break; }

           case 32:{
           drawScreen(Five);
           break; }

           case 33:{
           drawScreen(Six);
           break; }

           case 34:{
           drawScreen(Seven);
           break; }

           case 35:{
           drawScreen(Eight);
           break; }

           case 36:{
           drawScreen(Nine);
           break; }

           case 37:{
           drawScreen(SAD);
           break; }

           case 38:{
           drawScreen(GuidePushSetWord);
           break; }

           case 39:{
           drawScreen(Bacham);
           break; }
                    
            case 40:{
           drawScreen(_FAST);
           break; }

            case 41:{
           drawScreen(_MID);
           break; }

            case 42:{
           drawScreen(_LOW);
           break; }

          default:break;
        }
  }

