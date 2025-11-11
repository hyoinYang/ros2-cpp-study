//
// Created by roni on 11/3/25.
//
// randwalk1.cpp -- Vector 클래스를 사용하고 파일에 기록한다
// vect.cpp 파일과 함께 컴파일한다

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>  // 1. 파일 입출력을 위해 헤더 추가
#include "vect.h"

int main() {
    using namespace std;
    using VECTOR :: Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    ofstream fout; // 2. 파일 출력 스트림 객체 선언

    cout << "목표 거리를 입력하십시오(끝내려면 q): ";
    while (cin >> target)
    {
        cout << "보폭을 입력하십시오 : ";
        if (!(cin >> dstep))
            break;

        // 3. 파일 열기 (각 시뮬레이션마다 새로 덮어씀)
        fout.open("randwalk_log.txt");

        // 4. 파일에 초기 조건 쓰기
        fout << "목표 거리: " << target << ", 보폭: " << dstep << endl;

        // 5. 파일에 0번째 걸음(시작 위치) 쓰기
        fout << steps << ": " << result << endl;

        while (result.magval() < target)
        {
            direction = rand() % 360;
            // ⭐️ [버그 수정] 'steps.reset'이 아니라 'step.reset'이어야 합니다.
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
            // 6. 파일에 매 걸음의 위치 쓰기
            fout << steps << ": " << result << endl;
        }

        // --- 7. 결과 요약 (콘솔 출력) ---
        cout << steps << " 걸음을 걸은 후 술고래의 현재 위치 : \n ";
        cout << result << endl; // result는 현재 RECT 모드
        result.polar_mode();
        cout << " 또는\n" << result << endl; // result는 이제 POL 모드
        cout << "걸음당 기둥에서 벗어난 평균 거리 = " << result.magval()/steps << endl;

        // --- 8. 결과 요약 (파일 출력) ---
        // 이미지의 요구사항에 맞게 파일에도 요약 정보를 씁니다.
        fout << steps << " 걸음 후 술고래가 서 있는 위치\n";

        result.rect_mode(); // (x,y) 출력을 위해 RECT 모드로 변경
        fout << result << endl;
        fout << "또는\n";
        result.polar_mode(); // (m,a) 출력을 위해 POL 모드로 변경
        fout << result << endl;
        fout << "걸음당 기둥에서 벗어난 평균 거리 = " << result.magval()/steps << endl;

        // 9. 파일 닫기
        fout.close();

        // 다음 시뮬레이션을 위해 리셋
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "목표 거리를 입력하십시오(끝내려면 q) : ";
    }
    cout << "프로그램을 종료합니다. \n ";
    cin.clear();

    while (cin.get() != '\n')
        continue;

    return 0;
}