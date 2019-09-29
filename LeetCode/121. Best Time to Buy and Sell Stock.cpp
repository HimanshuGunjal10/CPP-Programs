#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxProfit(vector<int>& prices)
{
	int min_price = INT_MAX;
	int max_profit = 0;

	for(unsigned int i=0; i< prices.size(); i++)
	{
		if(prices[i] < min_price)
			min_price = prices[i];
		else if((prices[i] - min_price) > max_profit)
			max_profit = prices[i] - min_price;
	}

	return max_profit;
}


void print(vector<int> vec)
{
	for(unsigned int i=0; i<vec.size(); i++)
		cout << vec[i];
	cout << endl;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(8);
    v.push_back(1);
    v.push_back(4);
    v.push_back(6);
    v.push_back(9);


    print(v);

    cout << "Max Profit: " << maxProfit(v) << endl;

    cout << "La Fin";
    return 0;
}
