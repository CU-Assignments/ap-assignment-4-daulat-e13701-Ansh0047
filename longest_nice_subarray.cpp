#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestNiceSubstring(string s) {
        // brute generate all substrings
        int n = s.size();
        vector<string>store;

        for(int i=0;i<n;i++){
            string temp = "";
            for(int j=i;j<n;j++){
                temp += s[j];
                store.push_back(temp);
            }
        }

        // int maxLen = 0;
        string ans = "";
        for(auto str:store){
            vector<int>up(26,0),low(26,0);
            for(char c:str){
                if(c>='a' && c<='z') low[c-'a']++;
                if(c>='A' && c<='Z') up[c-'A']++;
            }

            bool flag = true;
            for(int i=0;i<26;i++){
                if(up[i] == 0 && low[i] != 0) flag = false;
                if(up[i] != 0 && low[i] == 0) flag = false;

                if(!flag) break;
            }

            if(flag){
                if(str.size()>ans.size()){
                    ans = str;
                }
            }
        }

        return ans;
    }
};