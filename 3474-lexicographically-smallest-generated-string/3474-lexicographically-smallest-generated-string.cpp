class Solution {
public:
bool isSame(string& word, string& str2, int i, int m){
    for(int j = 0; j < m; j++){
        if(word[i + j] != str2[j]) return false;
    }
    return true;
}
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        int N = n + m - 1;
        string word(N, '$');
        vector<bool> canChanged(N,false);

        for(int i = 0; i < n; i++){
            if(str1[i] == 'T'){
                int i_ = i;
                for(int j = 0; j < m; j++){
                    if(word[i_] != '$' && word[i_] != str2[j]) return "";
                    word[i_] = str2[j];
                    i_++;
                }
            }
        }

        for(int i = 0; i < N; i++){
            if(word[i] == '$'){
                word[i] = 'a';
                canChanged[i] = true;
            }
        }

        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){

                if(isSame(word,str2,i,m)){
                    bool changed = false;

                    for(int k = i + m - 1; k >= i; k--){
                        if(canChanged[k] == true){
                           for(char c = 'a'; c <= 'z'; c++){
                                if(c != str2[k - i]){
                                    word[k] = c;
                                    changed = true;
                                    break;
                                }
                            }
                        }
                        if(changed) break;
                    }
                    if(changed == false) return "";
                }
            }
        }
        return word;   
    }
};