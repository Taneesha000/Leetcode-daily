#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;

        for (int num : nums) {
            st.push(num);
            bool flag = true;
            while (st.size() >= 2 && flag) {
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();

                if (coprime(first, second)) {
                    st.push(lcm(first, second));
                } else {
                    flag = false;
                    st.push(second);
                    st.push(first);
                }
            }
        }

        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

private:
    bool coprime(int a, int b) {
        return gcd(a, b) > 1;
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(int a, int b) {
        return 1LL * a * b / gcd(a, b);
    }
};