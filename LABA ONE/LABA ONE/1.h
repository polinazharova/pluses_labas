#include <iostream>
#include <string>


int line_sorting(std::string str) {

    for (int i{ 0 }; i < str.size(); i++) {
        if (!((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 122))) {
            str.erase(i, 1);
            i--;
        }
    }

    int start = 0;
    int finish = str.size() - 2;
    int dop1 = 0;
    int dop2 = str.size() - 1;

    char temp;

    while (finish >= start) {
        for (int i = start; i < dop2; i++) {
            if (str[i] > str[i + 1]) {
                temp = str[i];
                str[i] = str[i + 1];
                str[i + 1] = temp;
            }
        }
        for (int j = finish; j > dop1; j--) {
            if (str[j] < str[j - 1]) {
                temp = str[j];
                str[j] = str[j - 1];
                str[j - 1] = temp;
            }
        }
        start++;
        finish--;
        dop1++;
        dop2--;
    }
    std::cout << str << std::endl;
    return 0;
}

