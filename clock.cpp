#include <iostream>

namespace {
const int kStartMorning{5};
const int kStartDay{12};
const int kStartEvening{18};
const int kStartNight{23};

const int kMidDay{12};
const int kMidNight{0};

const int kHigtLimitHour{23};
const int kLowLimitValue{0};
const int kHightLimitMinut{59};

const int kFindLastOne{10};

const int kExceptionsStart{11};
const int kExceptionsEnd{14};

const int kEndingForSingle{1};
const int kEndingForFew{2};
const int kEndingForMany{4};
}  // namespace

int main() {
    int hours{0};
    int minutes{0};
    std::cout << "Введите часы и минуты: ";
    std::cin >> hours >> minutes;

    if (hours < kLowLimitValue || hours > kHigtLimitHour || minutes < kLowLimitValue || minutes > kHightLimitMinut) {
        std::cout << "введены недопустимые данные" << std::endl;
        return 1;
    }

    if (hours == kMidNight && minutes == kLowLimitValue) {
        std::cout << "полночь" << std::endl;
        return 0;
    }
    if (hours == kMidDay && minutes == kLowLimitValue) {
        std::cout << "полдень" << std::endl;
        return 0;
    }

    int coutHours = hours % kMidDay;
    if (coutHours == kMidNight) {
        coutHours = kMidDay;
    }

    std::cout << coutHours;

    if (coutHours == kEndingForSingle) {
        std::cout << " час";
    } else if (coutHours >= kEndingForFew && coutHours <= kEndingForMany) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    if (minutes != kLowLimitValue) {
        std::cout << " " << minutes;

        int lastOneMinutes = minutes % kFindLastOne;

        if (minutes >= kExceptionsStart && minutes <= kExceptionsEnd) {
            std::cout << " минут";
        } else if (lastOneMinutes == kEndingForSingle) {
            std::cout << " минута";
        } else if (lastOneMinutes >= kEndingForFew && lastOneMinutes <= kEndingForMany) {
            std::cout << " минуты";
        } else {
            std::cout << " минут";
        }
    }

    if (hours >= kStartMorning && hours < kStartDay) {
        std::cout << " утра";
    } else if (hours >= kStartDay && hours < kStartEvening) {
        std::cout << " дня";
    } else if (hours >= kStartEvening && hours <= kStartNight) {
        std::cout << " вечера";
    } else {
        std::cout << " ночи";
    }

    if (minutes == kLowLimitValue) {
        std::cout << " ровно";
    }

    std::cout << std::endl;
    return 0;
}
