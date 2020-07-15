#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <string.h>
#include <windows.h>
#include<fstream>

#include "source.h"

#pragma comment(lib, "winmm.lib")

using namespace std;

struct _POINT {
    int x, y;
};

class SNAKE {
private:
    vector <_POINT> A;

    _POINT temp;
    _POINT qua;

    int Leng = 10;
    int Huong = 0;
    int score = 0;

    //Các tham số giới hạn 4 cạnh của khung trò chơi
    int consox1 = 0; int consox2 = 50; int consoy1 = 0; int consoy2 = 25;
public:
    //Thiết đặt mặc định
    SNAKE();

    //Các hàm Setter và Getter
    int GetConsox2();
    void SetHuong(int a);

    void SetScore(int x);
    int GetScore();


    //Di chuyển con rắn
    void DiChuyen();
    //Vẽ con rắn, một bước di chuyển sẽ vẽ thêm đầu và xoá phần đuôi
    void Ve();
    //Tạo quả và vẽ quả, ko cần refresh khung hình
    void TaoQua();
    void VeQua();
    //Kiểm tra có ăn quả sau mỗi lần di chuyển, nếu có tạo mới quả
    void AnQua();
    //Kiểm tra có cắn phải đuôi sau mỗi lần di chuyển
    bool CheckCanDuoi();
    //Kiểm tra có đập đầu vào tường trong chế độ classic
    bool CheckClassic();

};


