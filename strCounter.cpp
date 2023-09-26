#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

struct Char {
	char in;
	int type;
	bool operator< (const Char& an) const {
		return in < an.in;
	}
};

const int WORD_SIZE = 5;

vector<Char> alf = { {'0', 1}, {'1', 1}, {'2', 0}, {'3', 1}, {'4', 0}, {'5', 1}, {'6', 0}, {'7', 1}, {'8', 0} };
vector<Char> dbug = { {'I', 1}, {'A', 1}, {'I', 2}, {'A', 2}, {'M', 0}, {'F', 0}, {'B', 0}, {'R', 0}, {'X', 0}, {'i', 0} };

int check(vector<Char> a) {

	if(a[0].type == 1 || a.back().in == '1' || a.back().in == '8'){
		return 0;
	}

	/*multiset<Char> cont;
	set<Char> there;
	for (auto i : a) {
		cont.insert(i);
		there.insert(i);
	}
	if (cont.count({ '*', 0 }) != 1) return 0;
	/*int qnc = 0;
	for (auto i : there) {
		if (cont.count(i) % 2 == 1) {
			++qnc;
		}
	}
	if (qnc >= 2) return 0;*/
	


	for (int i = 0; i < a.size(); ++i) {
		for (int t = i + 1; t < a.size(); ++t) {
			if (a[i].in == a[t].in && a[i].in == '3') {
				return 0;
			}
		}
	}


	/*for (int i = 0; i < a.size(); ++i) {

	}*/

	/*for(int i = 0; i < a.size() - 1; ++i){
		int di = 0;
		while (a[i + di].in == need[di]) ++di;
		if (di == 10) good = true;
	}*/
	

	return 1;
}

vector<Char> str;
vector<int> perm;

int permut() {
	if (perm.size() == WORD_SIZE) {
		str.clear();
		for (auto i : perm) {
			str.push_back(alf[i]);
		}
		return check(str);
	}

	int res = 0;

	for (int i = 0; i < alf.size(); ++i) {

		for (auto t : perm) {
			if (i == t) {
				goto n_i;
			}
		}

		perm.push_back(i);
		res += permut();
		perm.pop_back();

	n_i:;
	}

	return res;
}

int silly() {
	if (str.size() == WORD_SIZE) return check(str);
	int res = 0;

	for (auto i : alf) {
		str.push_back(i);
		res += silly();
		str.pop_back();
	}
	return res;
}

int main()
{
	cout << silly();

	return 0;
}
