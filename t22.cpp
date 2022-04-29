#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;
set<string> dict;//string集合
//set小練習
int main(){
    string s,buf;
    while(cin>>s){
        for(int i=0;i<s.length();i++) //isalpha檢查字母的套件 tolower轉換為小寫字母
            if(isalpha(s[i])) s[i]=tolower(s[i]); else s[i]= ' ';
        stringstream ss(s); //將int轉換為string型態
        while(ss >> buf) dict.insert(buf);
    }
    //迴圈遍歷set 使用iterator迭代
    for(set<string> :: iterator it=dict.begin();it != dict.end();++it)
        cout << *it << "\n";
    return 0;
}