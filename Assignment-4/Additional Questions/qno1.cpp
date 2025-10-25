#include <iostream>
#include <queue>
using namespace std;

vector<string> generateBinary(int n)
{
        vector<string> res;
        queue<string> q;

        // Enqueue the first binary number
        q.push("1");
        while (n--)
        {

                string s1 = q.front();
                q.pop();
                res.push_back(s1);

                string s2 = s1;

                if (q.size() < n)
                {

                        // Append "0" to s2 and enqueue it.
                        q.push(s1.append("0"));

                        // Append "1" to s2 and enqueue it.
                        q.push(s2.append("1"));
                }
        }
        return res;
}

int main()
{
        int n = 6;

        vector<string> res = generateBinary(n);

        for (auto i : res)
        {
                cout << i << " ";
        }

        cout << "\n";
        return 0;
}