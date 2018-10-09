#include "Define.h"

void Speed_Display(int _time) { // Ham DEMO cho nguoi dung xem thu voi chu TRY
  timeCount = 0;
  while (timeCount < (_time * 3) + 5) // Bao nhieu chu thi * bay nhieu so 
  {
    if ((NutGiua == 0) || (NutDau == 0) || (NutKeCuoi == 0) || (NutCuoi == 0))
      break;
    timeCount += 1;
    if (timeCount < _time) {
      drawScreen(T);
    } else if (timeCount < _time * 2) {
      drawScreen(R);
    } else if (timeCount < _time * 3) {
      drawScreen(Y);
    }
  }
}
void ADDWORD(int _word, int _time) {
  timeCount = 0;
  while (timeCount < _time) {
    if ((NutGiua == 0) || (NutDau == 0) || (NutKeCuoi == 0) || (NutCuoi == 0))
      break;
    timeCount += 1;
    SELECT(_word);
  }
}
void Behon30() {
  timeCount = 0;
  while (timeCount < 125) {
    if ((NutGiua == 0) || (NutDau == 0) || (NutKeCuoi == 0)) 
      break;
    timeCount += 1;
    if (timeCount < 20) {
      drawScreen(Behon3);
    } else if (timeCount < 40) {
      drawScreen(Behon0);
    } else if (timeCount < 60) {
      drawScreen(Behon3);
    } else if (timeCount < 80) {
      drawScreen(Behon0);
    } else if (timeCount < 100) {
      drawScreen(Behon3);
    } else if (timeCount < 120) {
      drawScreen(Behon0);
    }
  }
}
void Mode_Nut_Dau(int _time) {      
  timeCount = 0;
  while (timeCount < (_time * 8) + 5) // Bao nhieu chu thi * bay nhieu so 
  {  
    if ((NutGiua == 0) || (NutDau == 0) || (NutKeCuoi == 0) || (NutCuoi == 0))
      break;
    timeCount += 1;
    if (timeCount < _time) {
      drawScreen(TIM1);
    } else if (timeCount < _time * 2) {
      drawScreen(TIM2);
    } else if (timeCount < _time * 3) {
      drawScreen(TIM3);
    } else if (timeCount < _time * 4) {
      drawScreen(TIM4);
    } else if (timeCount < _time * 5) {
      drawScreen(TIM5);
    } else if (timeCount < _time * 6) {
      drawScreen(TIM6);
    } else if (timeCount < _time * 7) {
      drawScreen(TIM7);
    } else if (timeCount < _time * 8) {
      drawScreen(TIM8);
    }
  }
}
void Nut_Nut_Dau(int _time) {
  while (1) {
    Mode_Nut_Dau(_time);
    if ((NutGiua == Push) || (NutCuoi == Push) || (NutKeCuoi == Push)) 
    break;
  }
}
void Mode_Nut_Giua(int _time) {
  timeCount = 0;
  while (timeCount < (_time * 4) + 10) //Bao nhieu chu thi * bay nhieu so 
  { 
    if ((NutGiua == 0) || (NutDau == 0) || (NutKeCuoi == 0) || (NutCuoi == 0))
      break;
    timeCount += 1;
    if (timeCount < _time) {
      drawScreen(C);
    } else if (timeCount < _time * 2) {
      drawScreen(E);
    } else if (timeCount < (_time * 2)+5) {
      drawScreen(Clear);
    } else if (timeCount < _time * 3) {
      drawScreen(E);
    } else if (timeCount < _time * 4) {
      drawScreen(C);
    } 
  }
}
void Nut_Nut_Giua(int _time) {
  while (1) {
    Mode_Nut_Giua(_time);
    if ((NutDau == Push) || (NutCuoi == Push) || (NutKeCuoi == Push)) 
    break;
  }
}
void Mode_Nut_Ke_Cuoi(int _time) {
  timeCount = 0;
  while (timeCount < (_time * 3) + 5)  //Bao nhieu chu thi * bay nhieu so 
  {
    if ((NutGiua == 0) || (NutDau == 0) || (NutKeCuoi == 0) || (NutCuoi == 0))
      break;
    timeCount += 1;
    if (timeCount < (_time)) {
      drawScreen(U);
    } else if (timeCount < (_time * 2)) {
      drawScreen(I);
    } else if (timeCount < (_time * 3)) {
      drawScreen(T);
    }
  }
}
void Nut_Nut_Ke_Cuoi(int _time) {
  while (1) {
    Mode_Nut_Ke_Cuoi(_time);
    if ((NutDau == Push) || (NutGiua == Push) || (NutCuoi == Push) || (NutKeCuoi == Push)) 
    break;
  }
}
void Mode_Nut_Cuoi(int _time) {
  timeCount = 0;
  while (timeCount < (_time * 11) + 15) // Bao nhieu chu thi * bay nhieu so 
  {
    if ((NutGiua == 0) || (NutDau == 0) || (NutKeCuoi == 0) || (NutCuoi == 0))
      break;
    timeCount += 1;
    if (timeCount < _time) {
      drawScreen(C);
    } else if (timeCount < _time * 2) {
      drawScreen(H);
    } else if (timeCount < _time * 3) {
      drawScreen(A);
    } else if (timeCount < _time * 4) {
      drawScreen(O);
    } else if (timeCount < _time * 5) {
      drawScreen(T);
    } else if (timeCount < _time * 6) {
      drawScreen(S);
    } else if (timeCount < _time * 7) {
      drawScreen(V);
    } else if (timeCount < _time * 8) { 
      drawScreen(K);
    } else if (timeCount < _time * 9) {
      drawScreen(One);
    } else if (timeCount < _time * 10) {
      drawScreen(Three);
    } else if (timeCount < _time * 11) {
      drawScreen(Bacham);
    }
  }
}
void Nut_Nut_Cuoi(int _time) {
  while (1) {
    Mode_Nut_Cuoi(_time);
    if ((NutDau == Push) || (NutGiua == Push) || (NutCuoi == Push) || (NutKeCuoi == Push)) 
    break;
  }
}
