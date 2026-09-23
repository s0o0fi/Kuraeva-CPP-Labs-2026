#include <iostream>

namespace {
const int kStartMorning{5};
const int kStartDay{12};
const int kStartEvening{18};
const int kEndEvening{23};

const int kMidday{12};
const int kMidnight{0};

const int kHighLimitHour{23};
const int kLowLimitValue{0};
const int kHighLimitMinute{59};

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

    if (hours < kLowLimitValue || hours > kHighLimitHour || minutes < kLowLimitValue || minutes > kHighLimitMinute) {
        std::cout << "введены недопустимые данные" << std::endl;
        return 1;
    }

    if (hours == kMidnight && minutes == kLowLimitValue) {
        std::cout << "полночь" << std::endl;
        return 0;
    }
    if (hours == kMidday && minutes == kLowLimitValue) {
        std::cout << "полдень" << std::endl;
        return 0;
    }

    int coutHours = hours % kMidday;
    if (coutHours == kMidnight) {
        coutHours = kMidday;
    }

    std::cout << coutHours;

    if (coutHours == kEndingForSingle) {
        std::cout << " час";
    } else if (coutHours >= kEndingForFew && coutHours <= kEndingForMany) {
        std::cout << " часа";
    } else if (coutHours >= kStartMorning && coutHours <= kMidday) {
        std::cout << " часов";
    }

    if (minutes != kLowLimitValue) {
        std::cout << " " << minutes;

        int lastOneMinutes = minutes % kFindLastOne;

        if (lastOneMinutes == kEndingForSingle && minutes != kExceptionsStart) {
            std::cout << " минута";
        } else if (lastOneMinutes >= kEndingForFew && lastOneMinutes <= kEndingForMany && (minutes < kExceptionsStart || minutes > kExceptionsEnd)) {
            std::cout << " минуты";
        } else if (lastOneMinutes == kLowLimitValue || lastOneMinutes >= kStartMorning ||
                   (minutes >= kExceptionsStart && minutes <= kExceptionsEnd)) {
            std::cout << " минут";
        }
    }

    if (hours >= kStartMorning && hours < kStartDay) {
        std::cout << " утра";
    } else if (hours >= kStartDay && hours < kStartEvening) {
        std::cout << " дня";
    } else if (hours >= kStartEvening && hours <= kEndEvening) {
        std::cout << " вечера";
    } else if (hours >= kMidnight && hours < kStartMorning) {
        std::cout << " ночи";
    }

    if (minutes == kLowLimitValue) {
        std::cout << " ровно";
    }

    std::cout << std::endl;
    return 0;
}
