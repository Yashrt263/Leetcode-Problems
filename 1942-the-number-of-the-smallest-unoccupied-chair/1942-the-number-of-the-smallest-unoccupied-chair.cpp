class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        long n = times.size();
        map<long, long> ma;
        map<long, long> chair;
        multimap<long, long> md;// arrival - index
        for(long i = 0; i < n; i++){
            ma[times[i][0]] = i;
        }
        for(long i = 0; i < n; i++){
            md.insert(make_pair(times[i][1], i));
        }
        //sort(ma.begin(), ma.end());
        //sort(md.begin(), md.end());
        priority_queue<long> pq;
        long curr_chair = 0;
        map<long, long>::iterator it = ma.begin();
        multimap<long, long>::iterator jt = md.begin();
        while(it != ma.end()){
            while(jt != md.end() && it->first >= jt->first){
                //cout << "fa";
                pq.push(-1 * chair[jt->second]);
                jt++;
            }
            if(pq.empty()){
                //cout << "h\n";
                chair[it->second] = curr_chair;
                ++curr_chair;
                //pq.push(-1*curr_chair);
            }
            else{
                chair[it->second] = -1 * pq.top();
                pq.pop();
            }
            //cout << it->second << " - " << chair[it->second] << endl;
            it++;
        }
        return chair[targetFriend];
    }
};