#include<vector>
#include<stdlib.h>
#include<limits.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0;
        int right = num.size() - 1;
        if (num.at(left) < num.at(right)) return num.at(left);
        int middle = (left + right) / 2;
        while (left < right) 
        {   
            middle = (left + right) / 2;
            if (num.at(middle) >= num.at(left) && num.at(middle) >= num.at(right)) 
            {   
                left = middle + 1;
            }   
            else if (num.at(middle) <= num.at(right)) 
            {   
                right = middle - 1;
                if (num.at(middle) < num.at(right)) break;
            }   
        }   
        int min_value = INT_MAX;
        int min_index = middle - 3;
        if (min_index < 0) min_index = 0;
        int max_index = middle + 3;
        if (max_index > num.size() - 1) max_index = num.size() - 1;
        
        for (int i = min_index; i <= max_index; i++) 
        {   
            if (num.at(i) < min_value) min_value = num.at(i);
        }   
        return min_value;
    } 
};

int main(int argc, char **argv) {
	
}
