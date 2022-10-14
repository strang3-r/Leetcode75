class TextEditor {
public:
    std::list<char> v;
    std::list<char>::iterator itr;
    TextEditor() {
        v.clear();
        v.insert(v.begin(), '#');
        itr = v.end();
    }
    void showme()
    {        
        for (auto &i : v)
            cout << i;
        cout << endl;
    }
    void addText(string text) {
        for (auto &i : text)
            v.insert(itr, i);
    }
    
    int deleteText(int k) {
        int res = 0;
        while (k-- and itr != v.begin())
            itr--, res++;
        if (itr == v.begin())
            itr++, res--;
        k = res;
        while (res-- and itr != v.end())
            itr = v.erase(itr);
        return k;
    }
    
    string cursorLeft(int k) {
        while (k-- and itr != v.begin())
            itr--;
        if (itr == v.begin())
        {
            itr++;
            return "";
        }
        auto it = itr;
        k = 10;
        string ans = "";
        while (it != v.begin() and k--)
        {
            it--;
            ans += *it;
        }
        if (it == v.begin())
        {
            ans.pop_back();
            it++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string cursorRight(int k) {
        while (k-- and itr != v.end())
            itr++;
        auto it = itr;
        k = 10;
        string ans = "";
        while (it != v.begin() and k--)
        {
            it--;
            ans += *it;
        }
        if (it == v.begin())
        {
            ans.pop_back();
            it++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
