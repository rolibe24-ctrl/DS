#include <iostream>
using namespace std;

bool isVowel(char ch)
{

        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

int main()
{
        char str[100], result[100];
        cout << "Enter a string: ";
        cin >> str;

        int i = 0, j = 0;

        while (str[i] != '\0')
        {
                if (!isVowel(str[i]))
                {
                        result[j] = str[i];
                        j++;
                }
                i++;
        }

        result[j] = '\0';
        cout << "String without vowels: " << result << endl;
        return 0;
}
