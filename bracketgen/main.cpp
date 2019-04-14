//
// Created by silverstringer on 06.05.19.
//


#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<string> res;

bool test_sequency(const char *str) {
    stack<int> stack;
    while (*str) {
        if (*str == '(') {
            stack.push(0);
        } else {
            if (*str == ')') {
                if (stack.empty())
                    return false;
                else
                    stack.pop();
            }
        }
        ++str;
    }
    return stack.empty();
}
void gen_resurc_sequen(const char* pIn, int N, int K)
{
    if(K == 0){
        return;
    }
    char* pOut = new char[K + 1];
    pOut[K] = 0;
    K--;
    int *stack = new int[K * 2],
            *pTop = stack,
            k = 0,
            n = 0,
            j = 0;
    for (;;)
    {
        while(n < N) {
            pOut[k] = pIn[n++];
            if (k == K) {
                if (test_sequency(pOut))
                    res.push_back(pOut);
            }
            else
            {
                if (n < N)
                {
                    *pTop++ = k;
                    *pTop++ = n;
                }
                k++;
                n = 0;
            }
        }
        if (pTop == stack)
            break;

        n = *(--pTop);
        k = *(--pTop);
    }
    delete[] pOut;
    delete[] stack;
    return;
}
int main()
{
    int n;
    cin >> n;
    const char *s="()";
//    clock_t start = clock();
    gen_resurc_sequen(s,2,2*n);
//    clock_t end = clock();
//    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
//    cout<<"The time: seconds\n"<<seconds;

    for (int i = 0; i < res.size(); i++)
        std::cout << res[i] << "\n";
    return 0;
}

