#include <iostream>

namespace{
    const int startMorning = 5;
    const int startDay = 12;
    const int startEvening = 18;
    const int startNight = 23;

    const int midDay = 12;
    const int midNight = 0;

    const int maxHour = 23;
    const int minValue = 0;
    const int maxMinut = 59;

    const int findLastOne = 10;

    const int exceptionsStart = 11;
    const int exceptionsEnd = 14;

    const int endsWithOne = 1;
    const int endsWithTwo = 2;
    const int endsWithFour = 4;
}

int main(){
    int hours, minutes;
    std::cout << "Введите часы и минуты: ";
    std::cin >> hours >> minutes;

    if (hours < minValue || hours > maxHour ||  minutes < minValue || minutes > maxMinut){
        std::cout << "введены недопустимые данные" << std::endl;
        return 1;
    }




    if (hours == midNight && minutes == minValue){
        std::cout << "полночь" << std::endl;
        return 0;
    }
    if (hours == midDay && minutes == minValue){
        std::cout << "полдень" << std::endl;
        return 0;
    }



    int coutHours = hours % midDay;
    if (coutHours == midNight){
        coutHours = midDay;
    }

    std::cout << coutHours;


    if(coutHours == endsWithOne){
        std::cout << " час";
    } else if (coutHours >= endsWithTwo && coutHours <= endsWithFour){
        std::cout << " часа";
    }else {
        std::cout << " часов";
    }




    if (minutes != minValue){
        std::cout << " " << minutes;

        int lastOneMinutes = minutes % findLastOne;

        if (minutes >= exceptionsStart && minutes <= exceptionsEnd) {
            std::cout << " минут";
        } else if (lastOneMinutes == endsWithOne) {
            std::cout << " минута";
        } else if (lastOneMinutes >= endsWithTwo && lastOneMinutes <= endsWithFour) {
            std::cout << " минуты";
        } else {
            std::cout << " минут";
        }
}



    if (hours >= startMorning && hours < startDay) {
        std::cout << " утра";
    } else if (hours >= startDay && hours < startEvening) {
        std::cout << " дня";
    } else if (hours >= startEvening && hours <= startNight) {
        std::cout << " вечера";
    } else {
        std::cout << " ночи";
    }


    if (minutes == minValue){
        std::cout << " ровно";
    }

    std::cout << std::endl;
    return 0;

}
