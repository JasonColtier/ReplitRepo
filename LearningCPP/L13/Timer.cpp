//
// Created by User on 22/07/2023.
//
#include <iostream>
#include <chrono>



class Timer {

private:
    using Clock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double,std::ratio<1>>;

    std::chrono::time_point<Clock> m_beg {Clock::now()};

public:
    void reset(){
        m_beg = Clock::now();
    }
    double elapsed() const{
        return std::chrono::duration_cast<Second>(Clock::now()-m_beg).count();
    }
    void printTimeElapsed(){
        std::cout<<"time elasped : "<<elapsed()<<"\n";
    }
};

int main(){
    Timer timer;

    for(int i {0}; i< 1000000;i++){
        int* tmp = new int[10000000];
        delete[] tmp;
    }

    timer.printTimeElapsed();

    return 0;
};


