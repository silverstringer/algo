//
// Created silverstringer on 12.05.19.
//


#include <iostream>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct Consecutive {
    std::map<int, int> elem;

    void operator()(int N) {

        int result = 0;
        int counter = 0;
        bool pop_bit;
        int temp = N;
        while (N) {
            pop_bit = N & 1;
            N >>= 1;

            if (pop_bit) {
                counter++;
            } else {
                result = std::max(result, counter);
                counter = 0;

            }
            result = std::max(result, counter);

        }
        cout << temp << ":" << result << ":" << std::bitset<16>(temp).to_string() << "\n";
        elem.insert(std::make_pair(temp, result));
    }

    operator std::map<int, int>() { return elem; }
};


int main() {
    std::vector<int> number;
    int num, numbers;
    cin >> num;
    for (auto i = 0; i < num; i++) {
        cin >> numbers;
        number.push_back(abs(numbers));
    }

    Consecutive s;
    std::map<int, int> x = std::for_each(number.begin(), number.end(), s);

//   example: std::map<int,int> x = { { 678,2 },{ 111,4 },{34,1},{56,3},{567,3} };


    auto max = std::max_element(x.begin(), x.end(),
                                [](const pair<int, int> &p1, const pair<int, int> &p2) {
                                    return p1.second < p2.second;
                                });

    std::cout << max->second;

    return 0;

}
