class Solution {
public:
    string interpret(string command) {
        
        string result;
        for(int i=0;i<command.size();i++)
        {
            if(command[i] == 'G')
            {
                result.push_back('G');
            }
             else if(command[i]=='(' && command[i+1] == ')')
            {
                result.push_back('o'),i++;
            }
            else
            {
                result.push_back('a');
                result.push_back('l'),i+=3;
            }
            
        }
       return result;
    }  
    
};
