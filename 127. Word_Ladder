class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string,vector<string>> mp;
        unordered_map<string,bool> bank,visited;
        vector<string> mywordList;
        
        mywordList.push_back(beginWord);
        bank[beginWord]=true;
        for(auto it:wordList){
            bank[it]=true;
            mywordList.push_back(it);
        }
        
        for(int i=0;i<mywordList.size();i++)
        {
            int n=mywordList[i].length();
            for(int j=0;j<n;j++){
                for(char k='a';k<='z';k++)
                {
                    string s=mywordList[i].substr(0,j)+k+mywordList[i].substr(j+1);
                    if(bank.find(s)!=bank.end())
                        mp[mywordList[i]].push_back(s);
                }
            }
        }
        
        queue<string> q;
        q.push(beginWord);
        visited[beginWord]=true;
        int level=2;
        
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto p=q.front();
                q.pop();
                for(auto it:mp[p])
                {
                    if(!visited[it]){
                      if(it==endWord)
                          return level;
                      q.push(it);
                      visited[it]=true;
                    }
                }
            }
            level++;
        }
        
      return 0;  
    }
};
