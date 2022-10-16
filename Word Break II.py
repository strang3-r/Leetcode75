# https://leetcode.com/problems/word-break-ii/description/

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        
        def recur(idx, str_):
            if idx >= len(s):
                recur.res.append(str_.strip())
                return
            
            for i in range(idx, len(s)):
                if s[idx:i+1] in wordDict:
                    temp = str_
                    str_ += s[idx:i+1] + ' '
                    recur(i+1, str_)
                    str_ = temp
                    
            return
        
        recur.res = []
        
        recur(0, '')
        return recur.res