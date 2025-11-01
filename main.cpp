#include "funcs.hpp"
#include <iostream>
using namespace WorkWithTime;

TimePoint* InputTime() {
    int h, m, s;
    std::cout << "Input time (hours, min, sec)" << std::endl;
    std::cin >> h >> m >> s;
    if (!correcttime(h, m, s)) {
        std::cout << "Invalid Input" << std::endl;
        return nullptr;
    }
    return newTime(h, m, s);
}

void printTime(TimePoint* t) {
    TimePoint& timeRef = *t;
    std::cout << timeRef.hours << ":" << timeRef.min << ":" << timeRef.sec << std::endl;
}

void menu() {
    std::cout << "1. Create new time" << std::endl;
    std::cout << "2. Sum time" << std::endl;
    std::cout << "3. Difference time" << std::endl;
    std::cout << "4. Check for correct input" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Select operation: ";
}

int main() {
    /*int* pz;
pz = new int;
char* pc = (char*)pz;
delete pc;*/
    TimePoint* time1 = nullptr;
    TimePoint* time2 = nullptr;
    TimePoint* result = nullptr;
    int choice;

    do {
        menu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            if (time1 != nullptr) deleteTime(time1);
            time1 = InputTime();
            if (time1 != nullptr) {
                std::cout << "Time is created: ";
                printTime(time1);
            }
            break;
        }
        case 2: {
            if (time1 == nullptr) {
                std::cout << "You didn't create any time" << std::endl;
                break;
            }
            std::cout << "First time: ";
            printTime(time1);
            std::cout << "Input second time:" << std::endl;
            if (time2 != nullptr) deleteTime(time2);
            time2 = InputTime();
            if (time2 != nullptr) {
                if (result != nullptr) deleteTime(result);
                result = summtime(time1, time2);
                std::cout << "Sum result: ";
                printTime(result);
            }
            break;
        }
        case 3: {
            if (time1 == nullptr) {
                std::cout << "You didn't create any time" << std::endl;
                break;
            }
            std::cout << "First time: ";
            printTime(time1);
            std::cout << "Input second time:" << std::endl;
            if (time2 != nullptr) deleteTime(time2);
            time2 = InputTime();
            if (time2 != nullptr) {
                int diff;
                difftime(time1, time2, &diff);
                std::cout << "Difference: " << diff << " seconds" << std::endl;
            }
            break;
        }
        case 4: {
            int h, m, s;
            std::cout << "Input time to check (hours, min, sec): " << std::endl;
            std::cin >> h >> m >> s;
            bool correct = correcttime(h, m, s);
            if (correct) {
                std::cout << "Time " << h << ":" << m << ":" << s << " - Correct" << std::endl;
            }
            else {
                std::cout << "Time " << h << ":" << m << ":" << s << " - Incorrect" << std::endl;
            }
            break;
        }
        case 5:
            break;
        default:
            std::cout << "Incorrect choice" << std::endl;
        }
    } while (choice != 5);

    if (time1 != nullptr) deleteTime(time1);
    if (time2 != nullptr) deleteTime(time2);
    if (result != nullptr) deleteTime(result);
    
    return 0;

}

//int x = 42;
//char* char_ptr = reinterpret_cast<char*>(&x);
//
//// Можем прочитать отдельные байты:
//std::cout << (int)char_ptr[0] << " "; // Первый байт: 42
//std::cout << (int)char_ptr[1] << " "; // Второй байт: 0  
//std::cout << (int)char_ptr[2] << " "; // Третий байт: 0
//std::cout << (int)char_ptr[3] << " "; // Четвертый байт: 0
