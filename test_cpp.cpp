#include <map>
#include <iostream>
#include <vector>


void test1() {
	std::map<float, int> stat_map;
	std::map<float, int>::iterator it_map;
	float f = 5/3;
	stat_map.insert(std::pair<float, int>(f, 10));
	it_map = stat_map.find(f);
	if (it_map != stat_map.end()) {
		std::cout << it_map->second << std::endl;
	}
}

void test2() {
	std::map<std::pair<double, double>, int> pair_map;
	std::map<std::pair<double, double>, int>::iterator it_pair;
	std::pair<double,double> pa1(1,2),pa2(1,3),pa3(2,2);
	pair_map[pa1]=1; pair_map[pa2]=2; pair_map[pa3]=3;
	std::cout << pair_map.size() << std::endl;
	std::pair<double,double> pa4(1,3);
	pair_map[pa4] = 4;
	std::cout << pair_map.size() << std::endl;
	for (it_pair = pair_map.begin(); it_pair != pair_map.end(); it_pair++) {
		std::pair<double, double> p = it_pair->first;
		int i = it_pair->second;
		std::cout << p.first << " " << p.second << " " << i << std::endl;
	}
}

struct tmp_node1 {
	int label;	
	tmp_node1(int x):label(x){};
};

void test_node() {
	std::vector<tmp_node1 *> node_vec;
	for (int i = 0; i < 5; i++) {
		tmp_node1 *tn = (tmp_node1 *)malloc(sizeof(tmp_node1));
		tn->label = i;
		node_vec.push_back(tn);
	}
}

void test_node2() {
	std::vector<tmp_node1 *> node_vec;
	std::vector<tmp_node1 *>::iterator it_vec;
	tmp_node1 n1(0);
	for (int i = 0; i < 5; i++) {
		node_vec.push_back(&n1);
		tmp_node1 *node = node_vec.back();
		node->label = i;
	}
	for (it_vec = node_vec.begin(); it_vec != node_vec.end(); it_vec++) {
		tmp_node1 *node = *it_vec;
		std::cout << node->label << std::endl;
	}
}

int main_test_cpp(int argc, char **argv) {
	test_node2();	
	return 0;
}