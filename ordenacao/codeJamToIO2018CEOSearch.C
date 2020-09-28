#include <bits/stdc++.h>
using namespace std;

/*
time complexity:
sort: O n(log n)

*/

vector <pair<long long, long long>> employees;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for (int index = 0; index < t; ++index)
	{		
		employees.clear(); 
		cout << "Case #"<< index+1 << ": ";
		long long l; 
		cin >> l;
		for (long long i = 0; i < l; ++i)
		{
			long long n, e;
			cin >> n >> e;
			employees.push_back(make_pair(e,n));
			
		}
		//ordena pela experiencia hopefully
		sort(employees.begin(), employees.end());
		long long orphans = employees[0].second;

		for (long long i = 1; i < employees.size(); ++i)
		{
			long long tmp = employees[i].first * employees[i].second - orphans;
			tmp = tmp > 0 ? 0 : -tmp;
			orphans =  tmp + employees[i].second;

		}
		if (orphans <= employees[l-1].first)
			cout << employees[l-1].first+1 <<endl;
		else
			cout << orphans << endl;;

	}
	return 0;
}