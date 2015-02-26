#include<iostream>
#include<limits.h>
#include<deque>

using namespace std;

class MinStack {
	deque<int> *in_vec;
	int min_index;
public:
	MinStack() {
		in_vec = new deque<int>();
	}
	~MinStack() {
		delete in_vec;
	}
	
    void push(int x) {
        in_vec->push_back(x);
        if (in_vec->size() == 1) {
        	min_index = 0;
        }
        else {
        	if (x <= in_vec->at(min_index)) {
        		min_index = in_vec->size() - 1;
        	}
        }
    }

    void pop() {
    	if (in_vec->size() == 0) return;
    	if (min_index == (in_vec->size() -1)) {
    		int min_value = INT_MAX;
    		for (int i = 0; i < in_vec->size() - 1; i++) {
    			int v = in_vec->at(i);
    			if (v <= min_value) {
    				min_index = i;
    				min_value = v;
    			}
    		}
    	}
        in_vec->erase(in_vec->end()-1);
    }

    int top() {
    	if (in_vec->size() == 0) return -1;
        return in_vec->at(in_vec->size()-1);
    }

    int getMin() {
    	if (in_vec->size() == 0) return -1;
        return in_vec->at(min_index);
    }
};

int main(int argc, char **argv) {
	MinStack ms;
	//push(2147483646),push(2147483646),push(2147483647),top,pop,getMin,
	//pop,getMin,pop,push(2147483647),top,getMin,
	//push(-2147483648),top,getMin,pop,getMin

	ms.push(2147483646);
	ms.push(2147483646);
	ms.push(2147483647);
	cout << ms.top() << endl;
	ms.pop();
	cout << ms.getMin() << endl;
	
	ms.pop();
	cout << ms.getMin() << endl;
	ms.pop();
	ms.push(2147483647);
	cout << ms.top() << endl;
	cout << ms.getMin() << endl;
	
	ms.push(-2147483648);
	cout << ms.top() << endl;
	cout << ms.getMin() << endl;
	ms.pop();
	cout << "max:" << INT_MAX << endl;
	cout << "======" << endl;
	cout << ms.getMin() << endl;
	
}
