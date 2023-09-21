#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> alf = { 

'B', 'O', 'R', 'O', 'T', 'A' };

int check(string a){
    /*if(a[7] != '0' && a[7] != '5'){
      

  return 0;
    }
    if(a[0] == '0'){
        return 0;
    }*/
    
    /*for(int i = 0; i < 

a.size(); ++i){
        for(int t = i + 1; t < a.size(); ++t){
            if(a[i] == a[t] || 

(a[i] == 'A' && a[t] == 'I') || (a[i] == 'I' && a[t] == 'A')){
                return 0;
       

     }
        }
    }*/
    
    for(int i = 0; i < a.size() - 1; ++i){
        if((a[i] == 'O' 

&& a[i + 1] == 'A') || (a[i] == 'A' && a[i + 1] == 'O') || (a[i] == 'O' && a[i + 1] == 'O')){
 

           return 0;
        }
    }
    
    return 1;
}

string str;

int permut(){
    if(str.size() == alf.size()) {
        string toc;
        for(auto &i : str){
            toc.push_back(alf

[i]);
        }
        return check(toc);
    }
    
    int res = 0;
    
    for(int i = 0; i < 

alf.size(); ++i){
        
        for(auto t : str){
            if(i == (int)t){
               

 goto n_i;
            }
        }
        
        str.push_back(char(i));
        res += permut

();
        str.pop_back();
        
        n_i:;
    }
}

int silly(){
    if(str.size() == 6) 

return check(str);
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
    cout<<permut();

    

return 0;
}
