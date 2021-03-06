#include <iostream>
#include <string>
#include<iterator>
#include<unordered_map>

using namespace std;

template<> struct hash<pair<string, string>> {
	size_t operator() (const pair<string, string> & arg) const {
		size_t h1 = hash<string>{}(arg.first);
		size_t h2 = hash<string>{}(arg.second);

		return h1 ^ (h2 >> 1) ^ (h2 << (sizeof(size_t)*CHAR_BIT - 1));
	}
};

int main()
{
	string str;
	unordered_map<pair<string, string>, size_t, hash<pair<string, string>>> graf;
	string temp, temp1;
	size_t numberOfWords;
	cin >> numberOfWords;
	for (size_t i = 0; i < numberOfWords; i++)
	{
		cin >> str;
		for (auto i = str.begin(); i != str.end() - 3; i++)
		{
			std::copy_n(i, 3, std::back_inserter(temp));
			std::copy_n(i + 1, 3, std::back_inserter(temp1));

			++graf[make_pair(temp, temp1)];
			temp.clear();
			temp1.clear();
		}
	}
	cout << graf.size()<<endl;
	for (auto i : graf) {
		cout << i.first.first << " " << i.first.second<<" "<<i.second<<endl;
	}
	cout << endl;
	system("pause");
	return 0;
}