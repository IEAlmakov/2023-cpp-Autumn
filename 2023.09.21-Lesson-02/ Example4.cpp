#include <iostream>

int main(int argc, char* argv[]) {
    int n;
    std::cin >> n;

    int ticket_1 = 15;
    int ticket_5 = 70;
    int ticket_10 = 125;
    int ticket_20 = 230;
    int ticket_60 = 440;

    int ans_1 = 0;
    int ans_5 = 0;
    int ans_10 = 0;
    int ans_20 = 0;
    int ans_60 = 0;   

    int count_20 = 0;
    int count_10 = 0;
    int count_5 = 0;
    int count_1 = 0;

    int rem_of_div = 0;
    int count = 0;
    
    if (n / 60 > 0) {
        ans_60 = n / 60;
        n = n % 60;
    }

    if (n <= 5) {
        if (ticket_1 * n < ticket_5) {
            ans_1 = n;
        } 
        else {
            ans_5 = 1;
        }
    } 
    else if (n <= 10) {
        count = n / 5;
        rem_of_div = n % 5;
        if (ticket_5 * count + rem_of_div * ticket_1 < ticket_10) {
            ans_5 += 1;
            ans_1 += rem_of_div;
        } 
        else {
            ans_10 += 1;
        }
    } 
    else if (n <= 20) {
        count_10 = n / 10;
        count_5 = (n - count_10 * 10) / 5;
        count_1 = n % 5;
        if (ticket_10 * count_10 + ticket_5 * count_5 + ticket_1 * count_1 < ticket_20) {
            ans_10 = count_10;
            ans_5 = count_5;
            ans_1 = count_1;
        } 
        else {
            ans_20 += 1;
        }
    } 
    else {
        count_20 = n / 20;
        count_10 = (n - count_20 * 20) / 10;
        count_5 = (n - count_20 * 20 - count_10 * 10) / 5;
        count_1 = n % 5;
        if(count_20 * ticket_20 + count_10 * ticket_10 + count_5 * ticket_5 + count_1 * ticket_1 < ticket_60) {
            ans_20 = count_20;
            if(ticket_10 * count_10 + ticket_5 * count_5 + ticket_1 * count_1 < ticket_20) {
                ans_10 = count_10;
                if(ticket_5 * count_5 + ticket_1 * count_1 < ticket_10) {
                    ans_5 = count_5;
                    ans_1 = count_1;
                } 
                else {
                    ans_10 += 1;
                }
            } 
            else {
                ans_20 += 1;
            }
        } 
        else {
            ans_60 += 1;
        }
    }

    std::cout << ans_1 << " " << ans_5 << " " << ans_10 << " " << ans_20 << " " << ans_60 << std::endl;
    
    return 0;
}