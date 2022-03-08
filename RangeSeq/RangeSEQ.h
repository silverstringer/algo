
#ifndef ALGO_RANGESEQ_H
#define ALGO_RANGESEQ_H

#include <iostream>
#include <memory>
#include <future>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
#include <list>

template <typename T = std::vector<int>>
class RangeSeq {
public:

    /**
     * @brief sum_iter сумма последовательности чисел в диапазоне
     * @param container контейнер
     * @param index_start начало диапазона
     * @param index_end   конец диапазона
     * @return
     */
    int sum_seq(T &container, int index_start, int index_end);

    /**
     * @brief make_range_seq диапазон для чисел, сумма которых в диапазоне sum_bande
     * @param seq контайнер
     * @param sum_bande сумма чисел
     * @return диапазон чисел в контейнере
     * @note сумма всех элементов в контейнере должна быть больше sum_bande
     * @todo возможно переделать с учетов замечания выше[ в случае когда меньше ]
     */

    std::map <int,int > make_range_seq(T &seq, int sum_bande);
};


template <typename T >
int RangeSeq<T>::sum_seq(T &container, int index_start, int index_end)
{
    auto sum_vec_range = std::accumulate(std::next(container.begin(), index_start), std::next(container.begin(), index_end), 0);
    return sum_vec_range;
}


template<typename T>
std::map<int, int> RangeSeq <T>::make_range_seq(T &seq, int sum_bande) {

    auto size_container = seq.size();

    std::map<int, int > range;

    if(!std::is_arithmetic<T>::value)
        return range;


    if(! ((std::is_same <T, std::vector <std::is_arithmetic<T>>>::value) || (std::is_same <T, std::list <std::is_arithmetic<T>>>::value)))
        return range;

    for(auto i = 0; i <= seq.size(); i++) {
        for(auto j = i + 1; j <= size_container; ++j) {
            auto sum = sum_seq(seq, i, j);
            if(sum < sum_bande) {
                auto inner_sum = sum + sum_seq(seq, i, j);
            }
            else {
                auto value = j - 2;
                if(range.size() == 0) {
                    range.insert({i, value});
                }
                else
                {
                    auto key = std::prev(range.end())->second;
                    if(i == key || i == key + 1)
                        range.insert({i, value});

                }
            };
        }
    }

    auto last_index_range = std::prev(range.end())->second;


    if((last_index_range + 1 ) != size_container)
        range.insert({last_index_range + 1, size_container });


    auto first_value = std::prev(range.begin())->second;

    for(auto it = range.begin();
        it != range.end(); ++it)
    {

        auto iter = std::next(it);
        if(iter->first == it->second) {
            range.erase(iter);
        }

    }

    return range;
}

template <>
std::map<int, int> RangeSeq <std::map<int, int>>::make_range_seq(std::map<int, int> &seq, int sum_bande);







#endif //ALGO_RANGESEQ_H
