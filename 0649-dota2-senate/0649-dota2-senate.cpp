class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q;
        for(char c : senate) q.push(c);
        char to_del = ' ';
        int cnt = 0;
        while(!q.empty() && cnt != q.size()){
            char curr = q.front();
            q.pop();
            if(cnt > 0 && to_del == curr){
                cnt--;
            }
            else{
                q.push(curr);
                cnt++;
                to_del = (curr == 'R') ? 'D' : 'R';
            }
        }
        if(q.front() == 'R') return "Radiant";
        return "Dire";
    }
};