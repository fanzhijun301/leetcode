#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>

using namespace std;

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;

        map<UndirectedGraphNode *, UndirectedGraphNode *> read_map;
		map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator it_map;
		queue<UndirectedGraphNode *> read_queue;
			
		read_queue.push(node);
		UndirectedGraphNode *head_copy_node = new UndirectedGraphNode(node->label);
		//UndirectedGraphNode head_copy_node(node->label);
		read_map.insert(pair<UndirectedGraphNode *, UndirectedGraphNode *>(node, head_copy_node));

		while (!read_queue.empty()) {
			UndirectedGraphNode *front = read_queue.front();
			read_queue.pop();
			//cout << front->label << endl;
			it_map = read_map.find(front);
			UndirectedGraphNode *front_copy_node = it_map->second;
			vector<UndirectedGraphNode *> &front_copy_neighbors = front_copy_node->neighbors;
			
			vector<UndirectedGraphNode *> neighbors = front->neighbors;
			for (int i = 0; i < neighbors.size(); i++) {
				UndirectedGraphNode *tmp_node = neighbors.at(i);
				it_map = read_map.find(tmp_node);
				if (it_map == read_map.end()) {
					read_queue.push(tmp_node);
				
					UndirectedGraphNode *nei_copy_node = new UndirectedGraphNode(tmp_node->label);
					//UndirectedGraphNode nei_copy_node(tmp_node->label);
					front_copy_neighbors.push_back(nei_copy_node);
					read_map.insert(pair<UndirectedGraphNode *, UndirectedGraphNode *>(tmp_node, nei_copy_node));
				} else {
					UndirectedGraphNode *tmp_copy_node = it_map->second;
					front_copy_neighbors.push_back(tmp_copy_node);
				}
			}
		}
		
		return head_copy_node;
    }

	void breadth_first(UndirectedGraphNode *ugn) {
		set<UndirectedGraphNode *> read_set;
		set<UndirectedGraphNode *>::iterator it_set;
		queue<UndirectedGraphNode *> read_queue;
		if (ugn != NULL) {read_queue.push(ugn); read_set.insert(ugn);}
		
		while (!read_queue.empty()) {
			UndirectedGraphNode *front = read_queue.front();
			cout << front->label << endl;
			read_queue.pop();

			vector<UndirectedGraphNode *> neighbors = front->neighbors;
			for (int i = 0; i < neighbors.size(); i++) {
				UndirectedGraphNode *tmp_node = neighbors.at(i);
				it_set = read_set.find(tmp_node);
				if (it_set == read_set.end()) {
					read_queue.push(tmp_node);
					read_set.insert(tmp_node);
				}
			}
		}
	}
};

void cloneGraph_test_case1() {
	Solution solution;
	UndirectedGraphNode n0(0),n1(1),n2(2);
	vector<UndirectedGraphNode *> n0_nei_vec, n1_nei_vec, n2_nei_vec;
	n0_nei_vec.push_back(&n1); n0_nei_vec.push_back(&n2);
	n1_nei_vec.push_back(&n2); n1_nei_vec.push_back(&n0);
	n2_nei_vec.push_back(&n2);

	n0.neighbors = n0_nei_vec;
	n1.neighbors = n1_nei_vec;
	n2.neighbors = n2_nei_vec;

	UndirectedGraphNode *ugn = solution.cloneGraph(&n0);
	solution.breadth_first(ugn);
}

int main_cloneGraph(int argc, char **argv) {
	cloneGraph_test_case1();
	return 0;
}