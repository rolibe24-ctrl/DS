#include <iostream>
using namespace std;

int main()
{
        char str1[100], str2[100];
        char result[200];

        cout << "Enter first string: ";
        cin >> str1;
        cout << "Enter second string: ";
        cin >> str2;

        int i = 0, j = 0;
        while (str1[i] != '\0')
        {
                result[i] = str1[i];
                i++;
        }

        while (str2[j] != '\0')
        {
                result[i] = str2[j];
                i++;
                j++;
        }

        result[i] = '\0';
        cout << "Concatenated String: " << result << endl;

        return 0;
}
