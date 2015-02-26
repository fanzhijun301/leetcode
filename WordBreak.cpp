#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak_1(string s, unordered_set<string> &dict) {
        vector<int> split_pos_vec;
        split_pos_vec.push_back(0);
        vector<int>::iterator it_vec;
    	for (int i = 1; i <= s.length(); i++) {
    		
    		for (it_vec = split_pos_vec.begin(); it_vec != split_pos_vec.end(); it_vec++) {
    			int begin_index = *it_vec;
    			string substr = s.substr(begin_index, i - begin_index);
    			unordered_set<string>::iterator it_dict = dict.find(substr);
    			if (it_dict != dict.end()) {
    				split_pos_vec.push_back(i);
    				begin_index = i;
    				cout << substr << ", " << i << endl;
    				break;
    			}
    		}
    	}
        int end_split_pos = split_pos_vec.at(split_pos_vec.size() - 1);
        if (end_split_pos == s.length()) return true;
        else return false;
    }
    
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<int> > pos_vec_vec;
        int len = s.length();
        for (int i = 0; i < len; i++) {
        	vector<int> pos_vec;
        	pos_vec_vec.push_back(pos_vec);
        }
    	vector<int> split_pos_vec;
        split_pos_vec.push_back(0);
        vector<int>::iterator it_vec;
    	for (int i = 1; i <= s.length(); i++) {
    		bool is_valid = false;
    		for (it_vec = split_pos_vec.begin(); it_vec != split_pos_vec.end(); it_vec++) {
    			int begin_index = *it_vec;
    			string substr = s.substr(begin_index, i - begin_index);
    			unordered_set<string>::iterator it_dict = dict.find(substr);
    			if (it_dict != dict.end()) {
    				vector<int> &pos_vec = pos_vec_vec.at(begin_index);
    				pos_vec.push_back(i);
//    				pos_x.push_back(begin_index);
//    				pos_y.push_back(i);
//    				cout << begin_index << "\t" << i << endl;
    				is_valid = true;
    			}
    		}
    		if (is_valid) split_pos_vec.push_back(i);
    	}
    	cout << "======================" << endl;
    	for (int i = 0; i < len; i++) {
    		cout << i;
    		vector<int> &pos_vec = pos_vec_vec.at(i);
    		for (int j = 0; j < pos_vec.size(); j++) {
    			cout << "\t" << pos_vec.at(j);
    		}
    		cout << endl;
    	}
    	
        int end_split_pos = split_pos_vec.at(split_pos_vec.size() - 1);
        if (end_split_pos == s.length()) return true;
        else return false;
    }
    
    void recur_pos_vec(int pos, vector<vector<int> > &pos_vec_vec, int level, int len) {
    	
    	vector<int> &pos_vec = pos_vec_vec.at(pos);
    	for (int i = 0; i < pos_vec.size(); i++) {
    		int next_pos = pos_vec.at(i);
    		cout << "\tlevel:" << level;
    		cout << " " << next_pos;
    		if (next_pos < len) {
    			level += 1;
    			recur_pos_vec(next_pos, pos_vec_vec, level, len);
    		} else {
    			cout << endl;
    		}
    	}
    }
};

int main(int argc, char **argv) {
	Solution solution;
	unordered_set<string> dict = {"kfomka","hecagbngambii","anobmnikj","c","nnkmfelneemfgcl","ah","bgomgohl","lcbjbg","ebjfoiddndih","hjknoamjbfhckb","eioldlijmmla","nbekmcnakif","fgahmihodolmhbi","gnjfe","hk","b","jbfgm","ecojceoaejkkoed","cemodhmbcmgl","j","gdcnjj","kolaijoicbc","liibjjcini","lmbenj","eklingemgdjncaa","m","hkh","fblb","fk","nnfkfanaga","eldjml","iejn","gbmjfdooeeko","jafogijka","ngnfggojmhclkjd","bfagnfclg","imkeobcdidiifbm","ogeo","gicjog","cjnibenelm","ogoloc","edciifkaff","kbeeg","nebn","jdd","aeojhclmdn","dilbhl","dkk","bgmck","ohgkefkadonafg","labem","fheoglj","gkcanacfjfhogjc","eglkcddd","lelelihakeh","hhjijfiodfi","enehbibnhfjd","gkm","ggj","ag","hhhjogk","lllicdhihn","goakjjnk","lhbn","fhheedadamlnedh","bin","cl","ggjljjjf","fdcdaobhlhgj","nijlf","i","gaemagobjfc","dg","g","jhlelodgeekj","hcimohlni","fdoiohikhacgb","k","doiaigclm","bdfaoncbhfkdbjd","f","jaikbciac","cjgadmfoodmba","molokllh","gfkngeebnggo","lahd","n","ehfngoc","lejfcee","kofhmoh","cgda","de","kljnicikjeh","edomdbibhif","jehdkgmmofihdi","hifcjkloebel","gcghgbemjege","kobhhefbbb","aaikgaolhllhlm","akg","kmmikgkhnn","dnamfhaf","mjhj","ifadcgmgjaa","acnjehgkflgkd","bjj","maihjn","ojakklhl","ign","jhd","kndkhbebgh","amljjfeahcdlfdg","fnboolobch","gcclgcoaojc","kfokbbkllmcd","fec","dljma","noa","cfjie","fohhemkka","bfaldajf","nbk","kmbnjoalnhki","ccieabbnlhbjmj","nmacelialookal","hdlefnbmgklo","bfbblofk","doohocnadd","klmed","e","hkkcmbljlojkghm","jjiadlgf","ogadjhambjikce","bglghjndlk","gackokkbhj","oofohdogb","leiolllnjj","edekdnibja","gjhglilocif","ccfnfjalchc","gl","ihee","cfgccdmecem","mdmcdgjelhgk","laboglchdhbk","ajmiim","cebhalkngloae","hgohednmkahdi","ddiecjnkmgbbei","ajaengmcdlbk","kgg","ndchkjdn","heklaamafiomea","ehg","imelcifnhkae","hcgadilb","elndjcodnhcc","nkjd","gjnfkogkjeobo","eolega","lm","jddfkfbbbhia","cddmfeckheeo","bfnmaalmjdb","fbcg","ko","mojfj","kk","bbljjnnikdhg","l","calbc","mkekn","ejlhdk","hkebdiebecf","emhelbbda","mlba","ckjmih","odfacclfl","lgfjjbgookmnoe","begnkogf","gakojeblk","bfflcmdko","cfdclljcg","ho","fo","acmi","oemknmffgcio","mlkhk","kfhkndmdojhidg","ckfcibmnikn","dgoecamdliaeeoa","ocealkbbec","kbmmihb","ncikad","hi","nccjbnldneijc","hgiccigeehmdl","dlfmjhmioa","kmff","gfhkd","okiamg","ekdbamm","fc","neg","cfmo","ccgahikbbl","khhoc","elbg","cbghbacjbfm","jkagbmfgemjfg","ijceidhhajmja","imibemhdg","ja","idkfd","ndogdkjjkf","fhic","ooajkki","fdnjhh","ba","jdlnidngkfffbmi","jddjfnnjoidcnm","kghljjikbacd","idllbbn","d","mgkajbnjedeiee","fbllleanknmoomb","lom","kofjmmjm","mcdlbglonin","gcnboanh","fggii","fdkbmic","bbiln","cdjcjhonjgiagkb","kooenbeoongcle","cecnlfbaanckdkj","fejlmog","fanekdneoaammb","maojbcegdamn","bcmanmjdeabdo","amloj","adgoej","jh","fhf","cogdljlgek","o","joeiajlioggj","oncal","lbgg","elainnbffk","hbdi","femcanllndoh","ke","hmib","nagfahhljh","ibifdlfeechcbal","knec","oegfcghlgalcnno","abiefmjldmln","mlfglgni","jkofhjeb","ifjbneblfldjel","nahhcimkjhjgb","cdgkbn","nnklfbeecgedie","gmllmjbodhgllc","hogollongjo","fmoinacebll","fkngbganmh","jgdblmhlmfij","fkkdjknahamcfb","aieakdokibj","hddlcdiailhd","iajhmg","jenocgo","embdib","dghbmljjogka","bahcggjgmlf","fb","jldkcfom","mfi","kdkke","odhbl","jin","kcjmkggcmnami","kofig","bid","ohnohi","fcbojdgoaoa","dj","ifkbmbod","dhdedohlghk","nmkeakohicfdjf","ahbifnnoaldgbj","egldeibiinoac","iehfhjjjmil","bmeimi","ombngooicknel","lfdkngobmik","ifjcjkfnmgjcnmi","fmf","aoeaa","an","ffgddcjblehhggo","hijfdcchdilcl","hacbaamkhblnkk","najefebghcbkjfl","hcnnlogjfmmjcma","njgcogemlnohl","ihejh","ej","ofn","ggcklj","omah","hg","obk","giig","cklna","lihaiollfnem","ionlnlhjckf","cfdlijnmgjoebl","dloehimen","acggkacahfhkdne","iecd","gn","odgbnalk","ahfhcd","dghlag","bchfe","dldblmnbifnmlo","cffhbijal","dbddifnojfibha","mhh","cjjol","fed","bhcnf","ciiibbedklnnk","ikniooicmm","ejf","ammeennkcdgbjco","jmhmd","cek","bjbhcmda","kfjmhbf","chjmmnea","ifccifn","naedmco","iohchafbega","kjejfhbco","anlhhhhg"};
	string s = "fohhemkkaecojceoaejkkoedkofhmohkcjmkggcmnami";
	bool can_split = solution.wordBreak(s, dict);
	cout << "result:" << can_split << endl;
	unordered_set<string>::iterator it_dict = dict.find("o");
	if (it_dict != dict.end()) cout << "find" << endl;
	else cout << "not find " << endl;
	
	cout << "====++++=======" << endl;
	
	vector<int> pos_vec_0; pos_vec_0.push_back(1); pos_vec_0.push_back(2); pos_vec_0.push_back(3);
	vector<int> pos_vec_1; pos_vec_1.push_back(3); pos_vec_1.push_back(4);
	vector<int> pos_vec_2; pos_vec_2.push_back(4);
	vector<int> pos_vec_3; pos_vec_3.push_back(4);
	
	vector<vector<int> > pos_vec_vec;
	pos_vec_vec.push_back(pos_vec_0);
	pos_vec_vec.push_back(pos_vec_1);
	pos_vec_vec.push_back(pos_vec_2);
	pos_vec_vec.push_back(pos_vec_3);
	
	solution.recur_pos_vec(0, pos_vec_vec, 0, pos_vec_vec.size());
//	for (int i = 0; i < pos_vec_vec.size(); i++) {
//		cout << i;.
//		vector<int> &pos_vec = pos_vec_vec.at(i);
//		for (int j = 0; j < pos_vec.size(); j++) {
//			cout << "\t" << pos_vec.at(j);
//		}
//		cout << endl;
//	}
}
