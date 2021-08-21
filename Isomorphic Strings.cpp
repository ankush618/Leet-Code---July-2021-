class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int a1[256] = {0};
        int a2[256] = {0};
        for(int i=0;i<s.length();i++){
            char ch1 = s[i];
            char ch2 = t[i];
            if(a1[ch1]!=a2[ch2]) return false;
            a1[ch1] = i+1;
            a2[ch2] = i+1;
            
        }
        return true;
    }
};
