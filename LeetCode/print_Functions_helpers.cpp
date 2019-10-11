void print(vector<int> vec)
{
	for(unsigned int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

void print2Dvec(vector<vector<int>> vec)
{
	for(unsigned int i=0; i<vec.size(); i++)
	{
		for(unsigned int j=0; j<vec[i].size(); j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}