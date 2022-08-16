var Trie = function() {
 	this.children = {};
};

/** 
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
    var cur = this;
    for(var i = 0; i < word.length; i++) {
    	var c = word[i];
    	if(!cur.children[c]) {
    		cur.children[c] = new Trie();
    	}

    	cur = cur.children[c];
    }

    cur.isWord = true;
};

/** 
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word) {
  	var cur = this;
  	for(var i = 0; i < word.length; i++) {
  		var c = word[i];
  		if(!cur.children[c]) {
  			return false;
  		}

  		cur = cur.children[c];
  	}   

  	return cur.isWord === true;
};

/** 
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function(prefix) {
    var cur = this;

    for(var i = 0; i < prefix.length; i++) {
    	var c = prefix[i];
    	if(!cur.children[c]) {
    		return false;
    	}

    	cur = cur.children[c];
    }

    return true;
};


 // * Your Trie object will be instantiated and called as such:
  var obj = new Trie()
  obj.insert(word)
  var param_2 = obj.search(word)
  var param_3 = obj.startsWith(prefix)
 