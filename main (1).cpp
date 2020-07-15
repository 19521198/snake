#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include "source.h"
#include "snake.h"
#include <fstream>
using namespace std;

bool Play();

int main()
{
    srand(time(NULL));

    while (Play());

    system("pause");
    return 0;
}

bool Play()
{

    string name;
	gotoXY(0, 0);
	cout << "Enter your name: ";
	cin >> name;

    system("cls");




    SNAKE* s;
    s = new SNAKE;
	s->setname(name);
    char t;
    int Huongdi = 0;
	

    while (1)
    {
        if (_kbhit())
        {
            t = _getch();
            switch (t)
            {
                //phím mũi tên
            case (-32):
            {
                t = _getch();
                switch (t)
                {
                case (72):if (Huongdi != 1)
                {

					Huongdi = 3;
                    s->SetHuong(Huongdi);
                } break;
                case (80):if (Huongdi != 3)
                {

					Huongdi = 1;
                    s->SetHuong(Huongdi);
                } break;
                case (75):if (Huongdi != 0)
                {

					Huongdi = 2;
                    s->SetHuong(Huongdi);
                } break;
                case (77):if (Huongdi != 2)
                {

					Huongdi = 0;
                    s->SetHuong(Huongdi);
                } break;
                }
            }break;


            }
        }
		
        s->DiChuyen();

        s->AnQua();
        if (s->CheckClassic() == true || s->CheckCanDuoi())
        {
			changColor(3);
			system("cls");
            gotoXY(25, 15);
			
            cout << "YOU LOSE! (T_T)"; break;
        }
        s->Ve();
        Sleep(200);
    }
    delete s;
    return 0;
}
