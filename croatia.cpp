#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	char str[100];
	int len, cnt = 0;

	cin >> str;

	len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] == 'd') //dz=에 대해서
		{
			if (str[i + 1] == 'z' && str[i + 2] == '=')
			{
				cnt++;
				i += 2;
			}
			else if (str[i + 1] == '-')
			{
				cnt++;
				i++;
			}
			else
				cnt++;
		}
		else if (str[i] == 'c' || str[i] == 's' || str[i] == 'z')
		{
			if (str[i + 1] == '=')
			{
				cnt++;
				i++;
			}
			else if (str[i] == 'c' && str[i + 1] == '-')
			{
				cnt++;
				i++;
			}
			else
				cnt++;
		}
		else if (str[i] == 'l' || str[i] == 'n')
		{
			if (str[i + 1] == 'j')
			{
				cnt++;
				i++;
			}
			else
				cnt++;
		}
		else
			cnt++;
	}
	cout << cnt;
	return 0;
}
