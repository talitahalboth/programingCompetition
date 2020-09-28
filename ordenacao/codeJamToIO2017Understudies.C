#include <bits/stdc++.h>

using namespace std;

vector <double> probs;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for (int index = 0; index < t; ++index)
	{
		probs.clear();
		cout << "Case #"<< index+1 << ": ";
		int n;
		cin >> n;
		for (int i = 0; i < 2*n; ++i)
		{
			double x;
			cin >> x;
			probs.push_back(x);
		}
		sort(probs.begin(),probs.end());

		double ans = 1;
		for (int i = 0; i < n; ++i)
		{
			double x = probs[i]*probs[2*n-i-1];
			//printf("%lf %lf\n", probs[i],probs[2*n-i-1]);
			x = 1-x;
			ans*=x;
		}
		printf("%lf\n",ans );

	}
	return 0;
}