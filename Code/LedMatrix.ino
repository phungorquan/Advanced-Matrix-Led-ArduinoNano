#include "Function.h"

void setup() {
  // Serial.begin(9600);
  for (byte i = 4; i <= 13; i++)
  pinMode(i, OUTPUT);
  
  for (byte i = 0; i < 4; i++)
  pinMode(i, INPUT_PULLUP);
  
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
 
  drawScreen(TEST);
  drawScreen(TEST);
}

void loop() {
  if (NutDau == Push) {           //Neu Nhan Nut Dau se nhay vao mode Nut Dau
    while (NutDau == Push);
    id = 1;
    Nut_Nut_Dau(default_time);
  } 
  
  else if (NutGiua == Push) {      //Neu Nhan Nut Giua se nhay vao mode Nut Giua
    while (NutGiua == Push);
    id = 0;
    Nut_Nut_Giua(default_time);
  } 
  
  else if (NutKeCuoi == Push) {      //Neu Nhan Nut Ke Cuoi khong giu qua 3s se nhay vao mode Nut Ke Cuoi
    while (NutKeCuoi == Push) {      //Neu Nhan va Giu Nut Ke Cuoi qua 3s se nhay vao Mode Set Time
      if (Check_Nhan_Giu_Nut == 6)                    //LUU Y KHI SET TIME VOI CHU MAC DINH SE CO NUT !!!! BACKKKKK !!!!!
        break;
      Check_Nhan_Giu_Nut++;
      delay(100);
    }
    while (NutKeCuoi == Push && Check_Nhan_Giu_Nut == 6) { 
      drawScreen(TimeMenu);
      Checkback = 5;
    }
    while (Check_Nhan_Giu_Nut > 5) {               
      drawScreen(TimeMenu);         //Hien thi ba muc Time mac dinh cho nguoi dung chon
      if (NutDau == Push) {         //Neu nhan NutDau se la muc nhanh nhat
        while (NutDau == Push);     
        _time = fast;                 //30 la muc nhanh nhat co the thay doi
        Speed_Display(_time);       //DEMO cho nguoi dung xem thu voi chu TRY
        Checkback = 1;
      } 
      
      else if (NutGiua == Push) {   //Neu nhan NutGiua se la muc trung binh
        while (NutGiua == Push);    
        _time = mid;                 //50 la muc trung binh co the thay doi
        Speed_Display(_time);       //DEMO cho nguoi dung xem thu voi chu TRY
        Checkback = 0;
      } 
      
      else if (NutKeCuoi == Push) { //Neu nhan NutGiua se la muc cham nhat
        while (NutKeCuoi == Push);
        _time = low;                 //70 la muc cham nhat co the thay doi
        Speed_Display(_time);       //DEMO cho nguoi dung xem thu voi chu TRY
        Checkback = 2;
      } 
      
      else if (NutCuoi == Push) {   //Luc nay neu khong chon thoi gian thi NutCuoi la nut BACK or ACCEPT thoi gian da chon
        while (NutCuoi == Push);  
        if (Checkback != 5) {       //Check neu DUNG se ACCEPT thoi gian da chon
          if (_time == fast)     {ADDWORD(40, 40);} // Hien cho nguoi dung biet da set loai thoi gian nao
          else if (_time == mid) {ADDWORD(41, 40);} // Hien cho nguoi dung biet da set loai thoi gian nao
          else if (_time == low) {ADDWORD(42, 40);} // Hien cho nguoi dung biet da set loai thoi gian nao
          
          if (id == 1) {Nut_Nut_Dau(_time);} 
          else if (id == 0) {Nut_Nut_Giua(_time);}
          else if (id == 2) {Nut_Nut_Ke_Cuoi(_time);}
          else if (id == 3) {Nut_Nut_Cuoi(_time);}
          else if (id == 4) {}                        // Set lai thoi gian cho cai truong hop ADDWORD
          
          Check_Nhan_Giu_Nut--;
        } 
        
        else {                      // Neu SAI se quay ve trang thai truoc do
          if (id == 1) {
            ADDWORD(37, 40);               // Mat SAD voi time = 40
            Nut_Nut_Dau(default_time);     // Trang thai truoc do
          } 
          
          else if (id == 0) {
            ADDWORD(27, 40);               // Mat SAD voi time = 40
            Nut_Nut_Giua(default_time);    // Trang thai truoc do
          } 
          
          else if (id == 2) { 
            ADDWORD(37, 40);               // Mat SAD voi time = 40
            Nut_Nut_Ke_Cuoi(default_time); // Trang thai truoc do
          } 
          
          else if (id == 3) {
            ADDWORD(37, 40);               // Mat SAD voi time = 40
            Nut_Nut_Cuoi(default_time);    // Trang thai truoc do
          }
          Check_Nhan_Giu_Nut--;
        }
      }
    }
    
    while (Check_Nhan_Giu_Nut < 5) {
      id = 2;
      Nut_Nut_Ke_Cuoi(default_time);
      if ((NutDau == Push) || (NutGiua == Push) || (NutKeCuoi == Push) || (NutCuoi == Push))
        break;
    }
    Check_Nhan_Giu_Nut = 0;
  } 
  
          //LUU Y KHI SET TIME VOI CHU DUOC NHAP VAO SE !!!! KKHONGGGG !!!!! CO NUT BACKKKKK nhung van Set lai thoi gian cho chuc nang ADDWORD duoc
          
  else if (NutCuoi == Push) {     //Neu Nhan Nut Cuoi khong giu qua 3s se nhay vao mode Nut Cuoi
    int _Select = 0;              // Bien nay dung de di chuyen den vi tri cac chu cai khi xai mode ADD WORD
    Buffer = 1;
    while (NutCuoi == Push) {      //Neu Nhan va Giu Nut Cuoi qua 3s se nhay vao Mode ADD WORD
      Check_Nhan_Giu_Nut++;
      delay(100);
      if (Check_Nhan_Giu_Nut == 5)
        break;
    }
    if (Check_Nhan_Giu_Nut == 5) {
      while (NutCuoi == Push)
        Behon30();                  // Neu da vao duoc Mode ADD WORD se hien thi thong bao nhap vao ky tu <30
      Check_Nhan_Giu_Nut++;
    }
    while (Check_Nhan_Giu_Nut > 5) {
      SELECT(_Select);              //Hien thi cac chu cai
      if (NutDau == Push)           //DOWN
      {
        delay(150);
        _Select--;
        if(_Select < 0 )
        _Select = 1;
      } 
      
      else if (NutGiua == Push) {   //UP
        delay(150);
        _Select++;
        if(_Select > 36 )
        _Select = 36;
      } 
      
      else if (NutCuoi == Push) {   //Sau khi di chuyen den chu can chon , nut nay se co chuc nang ACCEPT
        while (NutCuoi == Push) {
          drawScreen(Alert_Add_Word_OK);  //Thong bao thanh cong (chop nhanh 1 cai 4 goc)
        }
        if(_Select == 0)                 //Neu dang trong chuc nang ADD WORD ma k muon chon chu nua thi NutCuoi la BACK
        {
          Check_Nhan_Giu_Nut -= 2;
          ADDWORD(37, 40);               // Mat SAD voi time = 40
        }           
        
        if (Buffer <= 30 && Buffer > 0) {     // Neu nhap vao lon hon 30 ky tu se thong bao va be hon 0 se thong bao
          Array[Buffer] = _Select;
          Buffer++;
        }else Behon30();                      // Neu nhap vao lon hon 30 ky tu se thong bao 
      
      } 
      
      else if (NutKeCuoi == Push) { // Khi thuc hien xong ADD WORD , nut nay se co chuc nang Set Time
        while (NutKeCuoi == Push);
        while (Check_Nhan_Giu_Nut > 5 && Buffer > 1) { //_Seclect = 0 tranh tinh trang chua chon chu ma da SetTime
          drawScreen(TimeMenu);          //Hien thi ba muc Time mac dinh cho nguoi dung chon
          
          if (NutDau == Push) {          //Neu nhan NutDau se la muc nhanh nhat
            while (NutDau == Push);
            _time = fast;                  //30 la muc nhanh nhat co the thay doi
            Speed_Display(_time);        //DEMO cho nguoi dung xem thu voi chu TRY
          } 
          
          else if (NutGiua == Push) {    //Neu nhan NutGiua se la muc trung binh
            while (NutGiua == Push);
            _time = mid;                  //50 la muc trung binh co the thay doi
            Speed_Display(_time);        //DEMO cho nguoi dung xem thu voi chu TRY
          } 
          
          else if (NutKeCuoi == Push) {  //Neu nhan NutCuoi se la muc cham nhat
            while (NutKeCuoi == Push);    
            _time = low;                  //70 la muc cham nhat co the thay doi
            Speed_Display(_time);        //DEMO cho nguoi dung xem thu voi chu TRY
          } 
          
          else if (NutCuoi == Push) {     // Xong viec ADD WORD va Set Time , thi NutCuoi co chuc nang ACCEPT
            while (NutCuoi == Push);
             if (_time == fast)     {ADDWORD(40, 40);}  // Hien cho nguoi dung biet da set loai thoi gian nao
             else if (_time == mid) {ADDWORD(41, 40);}  // Hien cho nguoi dung biet da set loai thoi gian nao
             else if (_time == low) {ADDWORD(42, 40);}  // Hien cho nguoi dung biet da set loai thoi gian nao
             else _time = default_time;
             id = 4;
            Check_Nhan_Giu_Nut--;
          }
        }
        if(Buffer < 2 && _Select > 0)
         ADDWORD(38, 40);               // Hien mui ten huong dan bam SET WORD
      }
    }
    
    while (Check_Nhan_Giu_Nut < 5) {
      id = 3;
      Nut_Nut_Cuoi(default_time);
      if ((NutDau == Push) || (NutGiua == Push) || (NutKeCuoi == Push) || (NutCuoi == Push))
        break;
    }
    Check_Nhan_Giu_Nut = 0;
  }

  
  for (int i = 1; i < Buffer; i++)
    ADDWORD(Array[i], _time);    // HIEN THI CHU DA NHAP

    
}
