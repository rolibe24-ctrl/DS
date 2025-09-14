// 4) Write a program to find first non-repeating character in a string using Queue. Sample I/P: a a
// b c Sample O/P: a -1 b b


#include <iostream>
#include <queue>
#include <string>
using namespace std;

void firstNonRepeating(string str)
{
        queue<char> q;
        int freq[256] = {0};

        for (int i = 0; i < str.length(); i++)
        {
                char ch = str[i];

                if (ch == ' ')
                        continue;

                freq[ch]++;

                q.push(ch);

                while (!q.empty() && freq[q.front()] > 1)
                {
                        q.pop();
                }

                if (q.empty())
                {
                        cout << -1 << " ";
                }
                else
                {
                        cout << q.front() << " ";
                }
        }
        cout << endl;
}

int main()
{
        string input = "aabc";
        cout << "Input: " << input << endl;
        cout << "Output: ";
        firstNonRepeating(input);
        return 0;
}
