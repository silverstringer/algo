#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;



typedef std::map<char, int> T;
struct Counter
{
    std::map<char, int> wordCount;
    void operator()(const char & item) { ++wordCount[item]; }
    operator std::map<char, int>() { return wordCount; }

};
int anagrams(const T &t1, const T &t2){return (t1==t2)?1:0;}

int main ()
{
    string s1, s2;
    cin>>s1>>s2;
    std::map<char , int> wordCount = std::for_each(s1.begin(), s1.end(), Counter());
    std::map<char , int> wordCount1 = std::for_each(s2.begin(), s2.end(), Counter());
    cout<<anagrams(wordCount,wordCount1);
    return 0;
}

