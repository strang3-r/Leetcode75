/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length != t.length) return false;

    const count = {}

    const N = s.length
    for(let i = 0; i < N; i++) {
        if(!count[s[i]]) count[s[i]] = 0
        if(!count[t[i]]) count[t[i]] = 0

        count[s[i]]++
        count[t[i]]--
    }

    /*console.log(s, ":", sCount)
    console.log(t, ":", tCount)*/
    for(let ch in count) {
        if(count[ch] !== 0) return false;
    }
    return true;
}