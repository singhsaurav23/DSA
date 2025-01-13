//hard implemenatation -> map of set<ll> -> which is indices of keys 1,2,3-> which is in array
//question->sde-1 oa test
/*given coins of size n reprsenting denomination of each coin eg: n=7, coins=[3,4,1,2,2,1,1]
the process involved exchanging coins to reduce overall count,
- count the number of coins with each denomination and write the denomination on paper
- remove all denomination from the paper that have less than two coins
- if there is at least one value written on paper,find the smallest denomination in the paper let it be x.
- find two leftmost coins with denomination x and let their positions be i and j
- pick up two coins and remove them for one coin with a denomination of y=2*x and put that coin at position j(the position of the second coin picked)
the user wants to know the final value of all denominations answer-> 3,8,2,1.*/
//pick smallest denomination gretaer than 2,  reduce indices left most i, j-> no i and j=j*2 at that positon
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll i, n;
	cin >> n;
	vector<ll> v(n);
	map<ll, set<ll>> mp;
	for (i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]].insert(i);
	}

	for (auto it : mp) {

		if (it.second.size() == 1) continue;
		else {
			if (it.second.size() % 2 == 0) {
				if (it.second.size() == 2) {
					auto itt = it.second.begin();
					v[*itt] = -1;
					itt++;
					v[*itt] = it.first * 2;
					mp[it.first * 2].insert(*itt);
				}
				else {
					auto itt = it.second.begin();
					v[*itt] = -1;
					itt++;
					v[*itt] = -1;
					itt = it.second.end();
					itt--;
					v[*itt] = it.first * 2;
					mp[it.first * 2].insert(*itt);
					itt--;
					v[*itt] = it.first * 2;
					mp[it.first * 2].insert(*itt);

					if (it.second.size() > 4) {
						auto ittt = it.second.begin();
						ittt++; ittt++;
						while (ittt != itt) {
							v[*ittt] = it.first * 2;
							mp[it.first * 2].insert(*ittt);
							ittt++;
							v[*ittt] = -1;
							ittt++;
						}
					}
				}
			}
			else {
				auto ittt = it.second.begin();
				auto en = it.second.end();
				en--;
				while (ittt != en) {

					v[*ittt] = -1;
					ittt++;

					v[*ittt] = it.first * 2;
					mp[it.first * 2].insert(*ittt);

					ittt++;
				}
			}
		}
	}

	for (i = 0; i < n; i++) {
		if (v[i] != -1) cout << v[i] << " ";
	}
	return 0;
}