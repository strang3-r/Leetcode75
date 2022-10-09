class Solution {
    vector<char> my_stack;
public:
    bool isValid(string s) {
		if (s.size() % 2 != 0)
            return false;
        if (s.size() == 0)
            return true;
        for (int i = 0; i < s.size(); i++)
        {
                my_stack.push_back(s[i]);
                if (my_stack[my_stack.size() - 1] == '}')
                {
                    if (my_stack.size() > 1){
                    if(my_stack[my_stack.size() - 2] == '{')
                    {
                        my_stack.pop_back();
                        my_stack.pop_back();
                    }
                    }
                }
                else if (my_stack[my_stack.size() - 1] == ')')
                {
                    if (my_stack.size() > 1){
                    if(my_stack[my_stack.size() - 2] == '(')
                    {
                        my_stack.pop_back();
                        my_stack.pop_back();
                    }
                    }
                }
                else if (my_stack[my_stack.size() - 1] == ']')
                {
                    if (my_stack.size() > 1){
                    if(my_stack[my_stack.size() - 2] == '[')
                    {
                        my_stack.pop_back();
                        my_stack.pop_back();
                    }
                    }
                }  
        }
        if (!my_stack.empty())
            return false;
        return true;
    }
};
