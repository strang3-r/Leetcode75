class Solution {
public:
    bool isHappy(int n) {
        int tmp = 0;
        set<int> visited;
        
        while(true){
            tmp = 0;
            while(n > 0){
                tmp += pow((n%10), 2);
                n/=10;
            }
            n = tmp;
            if(n == 1){
                break;
            }else if(visited.find(n)!=visited.end()){
                return false;
            }
            visited.insert(n);
        }
        return true;
    }
};
