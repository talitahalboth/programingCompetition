#include <bits/stdc++.h>

using namespace std;

using ll=long long;
int melodia[112345];
int trecho[112345];
int melodiaDists[112345];
int trechoDists[112345];
int lps[112345];

int n;
int t;
int lpsArray()
{
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < t)
	{
		if (trechoDists[i] == trechoDists[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if (len != 0)
				len = lps[len-1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
int kmp()
{
	lpsArray();
	int i = 0;
	int j = 0;
	while (i < n)
	{
		if (trechoDists[j] == melodiaDists[i])
		{
			j++;
			i++;
		}
		if (j == t)
			return 1;
		else if (i < n && trechoDists[j] != melodiaDists[i])
		{
			if (j != 0)
				j = lps[j-1];
			else
				i = i+1;
		}
	}
	return 0;
}

ll mod(ll k, ll n) {
    return ((k %= n) < 0) ? k+n : k;
}

int main()
{
	map <string, int> notas;
	notas["Cb"]=0; //B
	notas["C"] = 1;
	notas["C#"] = 2;
	notas["Db"] = 2;
	notas["D"] = 3;
	notas["D#"] = 4;
	notas["Eb"] = 4; 
	notas["E"] = 5;
	notas["E#"] = 6; //F
	notas["Fb"] = 5; //E
	notas["F"] = 6;
	notas["F#"] = 7;
	notas["Gb"] = 7;
	notas["G"] = 8;
	notas["G#"] = 9;
	notas["Ab"] = 9;
	notas["A"] = 10;
	notas["A#"] = 11;
	notas["Bb"] = 11;
	notas["B"] = 0;
	notas["B#"] = 1; //C
	cin >> n >> t;
	while (n != 0 && t!= 0)
	{
		melodiaDists[0]=0;
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			melodia[i]=notas[s];
			if (i > 0)
				melodiaDists[i-1] = mod(melodia[i] - melodia[i-1],12);
		}

		trechoDists[0]=0;
		for (int i = 0; i < t; ++i)
		{
			string s;
			cin >> s;
			trecho[i]=notas[s];
			if (i > 0)
				trechoDists[i-1] = mod(trecho[i] - trecho[i-1],12);
		}
		n--;
		t--;
		printf("%s\n",kmp()?"S":"N" );
		cin >> n >> t;
	}
		
	
}