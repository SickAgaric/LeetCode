#include<iostream>
#include<string>

using namespace std;

int main()
{
	string cmd, cmd1;
	int len;
	getline(cin, cmd);
		for (int i = 0; i < cmd.size(); ++i)
		{
			if (cmd[i] != '"')
			{
				while (i++)
				{
					if (cmd[i] == ' ')
					{
						++i;
						cout << cmd1 << endl;
						cmd1 = "";
						break;
					}
					cmd1.push_back(cmd[i]);
				}
			}
			else if (cmd[i] == '"')
			{
				cmd1.push_back(cmd[i]);
				++i;
				while (i++)
				{
					if (cmd[i] == '"')
					{
						++i;
						cout << cmd1 << endl;
						cmd1 = "";
						break;
					}
					cmd1.push_back(cmd[i]);
				}
			}
		}


	return 0;
}