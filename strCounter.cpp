#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Char{
    char in;
    int type;
};

vector<Char> alf = { {'A', 1}, {'M', 0}, {'F', 0}, {'I', 1}, {'B', 0}, {'R', 0}, {'A', 2}, {'X', 0}, {'I', 2}, {'i', 0} };
vector<Char> dbug = { {'I', 1}, {'A', 1}, {'I', 2}, {'A', 2}, {'M', 0}, {'F', 0}, {'B', 0}, {'R', 0}, {'X', 0}, {'i', 0} };

int check(vector<Char> a){
    /*if(a[7] != '0' && a[7] != '5'){
        return 0;
    }*/
    
    /*if(a[0] == '0'){
        return 0;
    }*/
    
    for(int i = 0; i < a.size(); ++i){
        for(int t = i + 1; t < a.size(); ++t){
            if(a[i].in == a[t].in && a[i].type > a[t].type && a[t].type > 0){
                return 0;
            }
        }
    }
    
    
    int q_p = 0;
    
    for(int i = 0; i < a.size() - 1; ++i){
        if(a[i].type > 0 && a[i + 1].type > 0){
            ++q_p;
        }
    }
    if(q_p == 0) return 0;
    
    
    /*if(a[0].in == 'F' || a.back().in == 'F') return 0;
    
    for(int i = 1; i < a.size() - 1; ++i){
        if(a[i].in == 'F'){
            if(a[i - 1].in != a[i + 1].in || )
        }
    }*/
    
    
    
    return 1;
}

vector<Char> str;
vector<int> perm;

int permut(){
    if(perm.size() == 10) {
        str.clear();
        for(auto i : perm){
            str.push_back(alf[i]);
        }
        return check(str);
    }
    
    int res = 0;
    
    for(int i = 0; i < alf.size(); ++i){
        
        for(auto t : perm){
            if(i == t){
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

int silly(){
    if(str.size() == 5) return check(str);
    int res = 0;
    
    for(auto i : alf){
        str.push_back(i);
        res += silly();
        str.pop_back();
    }
    return res;
}

int main()
{
    cout << permut();

    return 0;
}
