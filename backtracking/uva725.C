#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
	int n;
	cin >> n;
	int printed =0;
	int comeco=0;
	while (n != 0)
	{
		vector <pair <int,int>> saida;
		saida.clear();
		printed=0;
		if (comeco) printf("\n");
		comeco=1;
		for (int i = 1234; i <= 98765/n; ++i)
		{
			// printf("%d\n",i );
			int abcde = i*n;
			if (abcde < 100000)
			{
				int used[10];
				int usados=0;
				memset(used,0,sizeof(used));
				int tmp = i;
				if ( i < 10000)
				{
					usados++;
					used[0]=1;
				}

				while (tmp)
				{
					if (!used[tmp%10])
						usados++;
					used[tmp%10]=1;
					tmp/=10;
				}
				tmp = abcde;
				if ( abcde < 10000)
				{
					if (!used[0])
						usados++;
					used[0]=1;
				}
				while (tmp)
				{

					if (!used[tmp%10])
						usados++;
					used[tmp%10]=1;
					tmp/=10;
				}
				// printf("%d %d %d\n",abcde,i,usados );

				if (usados == 10)
				{
					saida.push_back(make_pair(abcde, i));
				}
			}
		}
		if (saida.size() > 0)
		{
			sort (saida.begin(), saida.end());
			for (int i = 0; i < saida.size(); ++i)
			{
				if (saida[i].first < 10000) printf("0");
				printf("%d / ",saida[i].first );
				if (saida[i].second < 10000) printf("0");
				printf("%d = %d\n",saida[i].second , n);

				// printf("%d %d\n",saida[i].first,saida[i].second );
				// printf("%c%d / %c%d = %d\n",saida[i].first < 10000 ? '0':'',saida[i].first,saida[i].second < 10000 ? '0':'', saida[i].second,n );
			}
		}
		else
			printf("There are no solutions for %d.\n",n );
		cin >> n;
	}
	
}