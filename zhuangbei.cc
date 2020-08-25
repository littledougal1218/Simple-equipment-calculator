#include <iostream>
#include <vector>
using namespace std;

int consider(vector<int> prices, vector<int> levels, vector<int> count, int coins, int amount){
	int max_level = 0;
	if (amount == 0){
		return 0;
	}
	int level = 0;
	int i = 0;
	for (auto &a: prices){
		if (a <= coins && count.at(i) != 1){
			count.at(i) = 1;
			level = levels.at(i) + consider(prices, levels, count, coins - a, amount - 1);
			if (level > max_level){
				max_level = level;
			}
		}
		i ++;
	}
	return max_level;
}

int main(){
	int coins;
	cin >> coins;
	int amount;
	cin >> amount;
	vector<int> prices;
	vector<int> levels;
	vector<int> count;
	int a;
	int b;
	while(cin >> a){
		cin >> b;
		prices.emplace_back(a);
		levels.emplace_back(b);
		count.emplace_back(0);
	}	

	int best = consider(prices, levels, count, coins, amount);
	cout << best << endl;
}
