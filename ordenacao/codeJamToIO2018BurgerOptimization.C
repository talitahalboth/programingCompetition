#include <bits/stdc++.h>
/*
time complexity:
sort: O n(log n)

*/

using namespace std;


vector<int> ingredientes;
vector<int> ordenado;
vector<int> ordenado2;


int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for (int index = 0; index < t; ++index)
	{
		cout << "Case #"<< index+1 << ": ";
		ingredientes.clear();
		ordenado.clear();
		int k;
		cin >> k;
		for (int i = 0; i < k; ++i)
		{
			int tmp;
			cin >> tmp;
			ingredientes.push_back(tmp);
			ordenado.push_back(0);
			ordenado2.push_back(0);
		}
		if (k > 0)
			sort(ingredientes.begin(), ingredientes.end());

		for (int i = 0; i < k; ++i)
		{
			if (i%2==0)
				ordenado[i/2] = ingredientes[i];
			else
				ordenado2[i/2]= ingredientes[i];
		}
		int erro = 0;
		for (int i = 0; i < k; ++i)
		{
			//printf("%d %d %d\n",i/2, ordenado[i/2],ordenado2[i/2] );
			if (i%2 == 0)
				erro += (ordenado[i/2]-i/2)*(ordenado[i/2]-i/2);
			else
				erro += (ordenado2[i/2]-i/2)*(ordenado2[i/2]-i/2);
		}
		printf("%d\n",erro );
	}
	
	return 0;
}