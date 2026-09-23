#include <iostream>

namespace {
const int startMorning{5};
const int startDay = 12;
const int startEvening = 18;
const int startNight = 23;

const int midDay = 12;
const int midNight = 0;

const int hightLimitHour = 23;
const int lowLimitValue = 0;
const int hightLimitMinut = 59;

const int findLastOne = 10;

const int exceptionsStart = 11;
const int exceptionsEnd = 14;

const int endingForSingle = 1;
const int endingForFew = 2;
const int endingForMany = 4;
}  // namespace

int main() {
    int hours;
    int minutes;
    std::cout << "Введите часы и минуты: ";
    std::cin >> hours >> minutes;

    if (hours < lowLimitValue || hours > hightLimitHour || minutes < lowLimitValue || minutes > hightLimitMinut) {
        std::cout << "введены недопустимые данные" << std::endl;
        return 1;
    }

    if (hours == midNight && minutes == lowLimitValue) {
        std::cout << "полночь" << std::endl;
        return 0;
    }
    if (hours == midDay && minutes == lowLimitValue) {
        std::cout << "полдень" << std::endl;
        return 0;
    }

    int coutHours = hours % midDay;
    if (coutHours == midNight) {
        coutHours = midDay;
    }

    std::cout << coutHours;

    if (coutHours == endingForSingle) {
        std::cout << " час";
    } else if (coutHours >= endingForFew && coutHours <= endingForMany) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    if (minutes != lowLimitValue) {
        std::cout << " " << minutes;

        int lastOneMinutes = minutes % findLastOne;

        if (minutes >= exceptionsStart && minutes <= exceptionsEnd) {
            std::cout << " минут";
        } else if (lastOneMinutes == endingForSingle) {
            std::cout << " минута";
        } else if (lastOneMinutes >= endingForFew && lastOneMinutes <= endingForMany) {
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

    if (minutes == lowLimitValue) {
        std::cout << " ровно";
    }

    std::cout << std::endl;
    return 0;
}
