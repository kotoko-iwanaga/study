#include<vector>
#include<string>
#include<map>
#include <iostream>
#include <conio.h>
#include <locale>

using namespace std;

// прототипы для переменных алгоритма
string decode(const vector<int>&); 
vector<int> encode(const string& ori);
void getDictionary(const string);


int main() {
	setlocale(0, "");
	string test;
	cout << "Введите строку для закодирования: ";
	cin >> test;
	cout << "Исходная строка: " << test << endl;
	cout << "Закодированный вид: ";
	for (auto i : encode(test))
		std::cout << i << ' ';
	putchar('\n');
	cout << "Раскодированный вид: ";
	cout << decode(encode(test)) << endl;
	cout << "Используемый словарь: " << endl;
	getDictionary(test);
	cout << "Нажмите любую клавишу, чтобы выйти";
	_getch();
}


string decode(const vector<int>& v) {
	map<int, string> dict; // словарь
	int dictSize = 256; // размер словаря задаваемый

	for (int i = 0; i < dictSize; ++i)
		dict[i] = string(1, i);

	string s, entry, res; 
	s = res = dict[v[0]];

	for (size_t i = 1; i < v.size(); ++i) {
		int k = v[i];
		if (dict.count(k))
			entry = dict[k];
		else if (k == dictSize)
			entry = s + s[0];
		else throw "error";
		res += entry;
		dict[dictSize++] = s + entry[0];
		s = entry;
	}
	return res;
}


vector<int> encode(const string& original) {
	map<string, int> dict;
	int dictSize = 256;

	for (int i = 0; i < dictSize; ++i)
		dict[string(1, i)] = i;
	vector<int> res;
	string s;

	for (char z : original) { 
		if (dict.count(s + z)) s += z;
		else {
			res.emplace_back(dict[s]);
			dict[s + z] = dictSize++;
			s = z;
		}
	}
	if (s.size()) res.emplace_back(dict[s]);

	return res;
}

void getDictionary(const string inc) {
	map<string, int> dict;
	int dictSize = 256;

	for (int i = 0; i < dictSize; ++i)
		dict[string(1, i)] = i;
	vector<int> res;
	string s;

	for (char z : inc) {
		if (dict.count(s + z)) s += z;
		else {
			res.emplace_back(dict[s]);
			dict[s + z] = dictSize++;
			s = z;
		}
	}
	if (s.size()) res.emplace_back(dict[s]);

	map<string, int>::iterator it = dict.begin();
	while (it != dict.end()) {
		cout << "Key: " << it->first
			<< ", Value: " << it->second << endl;
		++it;
	}
}