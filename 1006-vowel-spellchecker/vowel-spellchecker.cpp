class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> original(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;

        auto changeVowel = [&](string s) {
            for (char &c : s) {
                if (string("aeiou").find(c) != string::npos) c = '*';
            }
            return s;
        };

        for (auto &w : wordlist) {
            string lower = w;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if (!caseMap.count(lower)) caseMap[lower] = w;
            string cv = changeVowel(lower);
            if (!vowelMap.count(cv)) vowelMap[cv] = w;
        }

        vector<string> res;
        for (auto &q : queries) {
            if (original.count(q)) {
                res.push_back(q);
                continue;
            }
            string lower = q;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            string cv = changeVowel(lower);

            if (caseMap.count(lower)) res.push_back(caseMap[lower]);
            else if (vowelMap.count(cv)) res.push_back(vowelMap[cv]);
            else res.push_back("");
        }
        return res;
    }
};