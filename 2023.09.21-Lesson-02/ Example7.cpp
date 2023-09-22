#include <iostream>

int main(int argc, char* argv[]) {
    int a = 0;
    int f = 0;
    int s = 0;
    int t  = 0;
    
    std::cin >> a;
    
    f = a % 10;
    a = a / 10;
    s = a % 10;
    a = a / 10;
    t = a % 10;
    a = a / 10;
    
    if (t == 1) {
        std::cout << "C" << std::endl;
    }

    switch(s) {
        case 1:
            std::cout << "X";
            break;
        case 2:
            std::cout << "XX";
            break;
        case 3:
            std::cout << "XXX";
            break;
        case 4:
            std::cout << "XL";
            break;
        case 5:
            std::cout << "L";
            break;
        case 6:
            std::cout << "LX";
            break;
        case 7:
            std::cout << "LXX";
            break;
        case 8:
            std::cout << "LXXX";
            break;
        case 9:
            std::cout << "XC";
            break;
        default:
            std::cout << "";
            break;
    }

    switch(f) {
        case 1:
            std::cout << "I" << std::endl;
            break;
        case 2:
            std::cout << "II" << std::endl;
            break;
        case 3:
            std::cout << "III" << std::endl;
            break;
        case 4:
            std::cout << "IV" << std::endl;
            break;
        case 5:
            std::cout << "V" << std::endl;
            break;
        case 6:
            std::cout << "VI" << std::endl;
            break;
        case 7:
            std::cout << "VII" << std::endl;
            break;
        case 8:
            std::cout << "VIII" << std::endl;
            break;
        case 9:
            std::cout << "IX" << std::endl;
            break;
        default:
            std::cout << "" << std::endl;
            break;
    }
    return EXIT_SUCCESS;
}