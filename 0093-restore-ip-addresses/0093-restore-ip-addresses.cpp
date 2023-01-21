class Solution {
public:
    vector<string> ans;
    bool help(string& d){
        return d.length() <= 3 && stoi(d) >= 0 && stoi(d) <= 255 && (d == to_string(stoi(d)));
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                for(int k = j + 1; k < n - 1; k++){
                    string a = s.substr(0, i + 1);
                    string b = s.substr(i+1, j - i);
                    string c = s.substr(j+1, k - j);
                    string d = s.substr(k+1);
                    if(help(a) && help(b) && help(c) && help(d)){
                        string tmp = a + "." + b + "." + c + "." + d;
                        ans.push_back(tmp);
                    }
                    //cout << tmp << endl;
                }
            }
        }
        return ans;
    }
};