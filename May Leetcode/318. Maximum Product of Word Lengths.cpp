class Solution {
public:
    int maxProduct(vector<string>& words) {
	int n = size(words), ans = 0;
	vector<int> mask(n);
	for(int i = 0; i < n; i++) {
		for(auto& ch : words[i])           
			mask[i] |= 1 << (ch - 'a');     // hash the word
		for(int j = 0; j < i; j++)
			if((mask[i] & mask[j]) == 0)    // no common set bit in the hash of words[i] and words[j]
				ans = max(ans, int(size(words[i]) * size(words[j])));
	}   
	return ans;
}
};

/* For eg. 
Consider word1 = "abex", word2 = "acdx"
hash1 = (11001000000000000000000100) in binary
hash2 = (10110000000000000000000100) in binary
       ------------------------------------
	   & 10000000000000000000000100    ==>   common letters are present
	   
Consider word1 = "abex", word2 = "dfgmn"
hash1 = (11001000000000000000000100) in binary
hash2 = (00010110000011000000000000) in binary
       ------------------------------------
	   & 00000000000000000000000000   ==>    no common letter present
	   
So, we can just do (hash1 & hash2) and if its 0, that denotes that hash1 and hash2 didn't have any common set bit */
