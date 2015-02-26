#include<iostream>
#include<stdlib.h>
#include<sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
    	string s = "";
        for (int i = 0; i < n; i++) {
        	if (i == 0) s = "1";
        	else s = say_str(s);
        }
        return s;
    }
    
    string say_str(string src_str) {
    	char last_char;
    	int count_char = 0;
    	string result_s = "";
    	for (int i = 0; i < src_str.size(); i++) {
    		char a = src_str.at(i);
    		if (i == 0) {
    			last_char = a;
    			count_char = 1;
    		} else {
    			if (a == last_char) count_char += 1;
    			else {
    				stringstream ss;
    				ss << result_s << count_char << last_char;
    				result_s = ss.str();
    				last_char = a;
    				count_char = 1;
    			}
    		}
    	}
    	stringstream ss;
    	ss << result_s << count_char << last_char;
    	result_s = ss.str();
    	return result_s;
    }
};

int main(int argc, char **argv) {
	string src_str = "11";
	Solution solution;
	
	string r = solution.countAndSay(100);
	cout << r << endl;
} 
