#include "snake.h"

using namespace std;


SNAKE::SNAKE()
{
	setname(name);
    //Vẽ khung viền
    gotoXY(consox1, consoy1);//vien tren
    for (int i = consox1; i <= consox2; i++)
        cout << "-";
    gotoXY(consox1, consoy2);//vien duoi
    for (int i = consox1; i <= consox2; i++)
        cout << "-";
    for (int i = consoy1 + 1; i < consoy2; i++)//vien trai
    {
        gotoXY(consox1, i); cout << "|";
    }
    for (int i = consoy1 + 1; i < consoy2; i++)//vien phai
    {
        gotoXY(consox2, i); cout << "|";
    }
    gotoXY(consox2 /2, consoy2+1); cout <<getname()<< "  SCORE:    0";

    score = 0;
    Leng = 10;
    for (int i = 0; i < Leng; i++)
    {
        A.push_back(temp);
        A[i].x = 10 + Leng - i - 1; A[i].y = 10;
    }
    A.push_back(temp);


    for (int i = Leng - 1; i > 0; i--)
    {
        gotoXY(A[i].x, A[i].y);

        cout << "x";//tao hinh snake
    }
    gotoXY(A[0].x, A[0].y);
    cout << "+";

    //Tạo và vẽ quả
    TaoQua();
    VeQua();
}


int SNAKE::GetConsox2()
{
    return consox2;
}

void SNAKE::SetHuong(int a)
{
    Huong = a;
}

void SNAKE::SetScore(int x)
{
    score = x;
}
int SNAKE::GetScore()
{
    return score;
}

void SNAKE::DiChuyen()
{
    for (int i = Leng; i > 0; i--) A[i] = A[i - 1];
    if (Huong == 0) A[0].x = A[1].x + 1;
    if (Huong == 1) A[0].y = A[1].y + 1;
    if (Huong == 2) A[0].x = A[1].x - 1;
    if (Huong == 3) A[0].y = A[1].y - 1;
}
//Vẽ con rắn, một bước di chuyển sẽ vẽ thêm đầu và xoá phần đuôi
void SNAKE::Ve()
{
    gotoXY(A[Leng].x, A[Leng].y); cout << " ";

    gotoXY(A[1].x, A[1].y); cout << "x";

    gotoXY(A[0].x, A[0].y); cout << "+";

}
//Tạo quả và vẽ quả, ko cần refresh khung hình
void SNAKE::TaoQua()
{
    int x, y;
    bool checkxfail = true, checkyfail = true;

    while (checkxfail || checkyfail)
    {
        x = consox1 + 1 + rand() % (consox2 - consox1 - 1);
        y = consoy1 + 1 + rand() % (consoy2 - consoy1 - 1);
        if (x == qua.x && y == qua.y) continue;//tao qua false
        int i;
        for (i = 0; i < Leng; i++)
        {
            if (x == A[i].x && y == A[i].y)//tao qua trung voi snake - false
            {
                i = -1;
                break;
            }
        }
        if (i == Leng) break;//tao qua success
    }
    qua.x = x;
    qua.y = y;
}
void SNAKE::VeQua()
{
    gotoXY(qua.x, qua.y);
    cout << "*";
}
//Kiểm tra có ăn quả sau mỗi lần di chuyển, nếu có tạo mới quả
void SNAKE::AnQua()
{
    if (A[0].x == qua.x && A[0].y == qua.y)
    {
        score += 10;
		gotoXY(consox2 / 2+2, consoy2); cout <<"PLAYER: "<< getname();
        gotoXY(consox2 / 2 + 8, consoy2 + 1);// diem
        cout << setw(6) << score;
        temp.x = A[Leng].x;
        temp.y = A[Leng].y;
        Leng++;
        A.push_back(temp);
        TaoQua();
        VeQua();
    }
}
//Kiểm tra có cắn phải đuôi sau mỗi lần di chuyển
bool SNAKE::CheckCanDuoi()
{
    for (int i = 1; i < Leng; i++)
    {
        if (A[0].x == A[i].x && A[0].y == A[i].y)
        {
            return true;
        }
    }
    return false;
}
//Kiểm tra có đập đầu vào tường trong chế độ classic
bool SNAKE::CheckClassic()
{
    if (A[0].x == consox1 || A[0].x == consox2 || A[0].y == consoy1 || A[0].y == consoy2)
        return true;
    return false;
}