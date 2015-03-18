#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
		int len_needle = strlen(needle);
		int len_haystack = strlen(haystack);
		if (len_needle == 0) return 0;
        if (len_needle > len_haystack) return -1;
		char *pi = haystack;
		int i = 0;
		while (*pi != '\0') {
			if (len_needle > len_haystack-i) break;
			if (*pi != *(needle)) {pi++;i++;}
			else {
				char *pik=pi+1,*pjk=needle+1;
				while (*pik != '\0' && *pjk != '\0') {
					if (*pik != *pjk) break;
					pik++; pjk++;
				}
				if (*pjk=='\0') return i;
				pi++;
				i++;
			}
		}
		return -1;
    }
};

void implementstrStr_test_case1() {
	char haystack[] = "abcddef";
	char needle[] = "dde";
	Solution solution;
	int pos = solution.strStr(haystack, needle);
	cout << pos << endl;
}

int main_implementstrStr(int argc, char **argv) {
	implementstrStr_test_case1();
	return 0;
}