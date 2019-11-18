#include <iostream>
#include <string>
using namespace std;

bool judgeCircle(string moves)
{
    if(moves.empty())
        return true;

	int x=0, y=0;	//for the x and y directions LR and UD respectively
	for(char c : moves)
	{
		switch(c)
		{
		case 'L': x++; break;
		case 'R': x--; break;
		case 'U': y++; break;
		case 'D': y--; break;
		default: return false;
		}
	}
	if(x==0 && y==0)
		return true;
	return false;
}

int main()
{
	string s = "LRUDDRUL";
	cout << judgeCircle(s);

	cout << "\nLa Fin!!";
}
