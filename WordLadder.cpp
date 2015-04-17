#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <limits.h>
#include <list>

using namespace std;

class Solution2 {
public:
    int ladderLength(string start, string end, set<string> &dict) { //unordered_set
        map<string, vector<string>> neighbor_map;
		buildGraph(neighbor_map, dict, start, end);
		
		int len = breadth_first(neighbor_map, start, end);
		return len;
    }

	int breadth_first(map<string, vector<string>> &neighbor_map, string start, string end) 
	{
		map<string,int> checked_map;
		map<string,int>::iterator it_checked_map;
		map<string, vector<string>>::iterator it_map;
		vector<string>::iterator it_vec;
		queue<string> breadth_queue;
		breadth_queue.push(start);
		checked_map.insert(pair<string,int>(start,1));
		while (!breadth_queue.empty()) {
			string top = breadth_queue.front();
			breadth_queue.pop();
			int curr_depth = checked_map[top];
			it_map = neighbor_map.find(top);
			if (it_map != neighbor_map.end()) {
				vector<string> in_vec = it_map->second;
				for (it_vec = in_vec.begin(); it_vec != in_vec.end(); it_vec++) {
					string tmp_s = *it_vec;
					if (tmp_s == end) return curr_depth + 1;

					it_checked_map = checked_map.find(tmp_s);
					if (it_checked_map != checked_map.end()) continue;
					breadth_queue.push(tmp_s);
					checked_map.insert(pair<string,int>(tmp_s, curr_depth+1));
				}
			}
		}
		return 0;
	}

	void buildGraph(map<string, vector<string>> &neighbor_map, 
		set<string> &dict, string start, string end) 
	{
		map<string, vector<string>>::iterator it_map;
		
		dict.insert(start);
		dict.insert(end);

		vector<string> str_vec;
		set<string>::iterator it_set;
		for (it_set = dict.begin(); it_set != dict.end(); it_set++) {
			str_vec.push_back(*it_set);
		}
				
		for (int i = 0; i < str_vec.size()-1; i++) {
			string str_i = str_vec[i];
			for (int j = i + 1; j < str_vec.size(); j++) {
				string str_j = str_vec[j];
				int diff = 0;
				for (int k = 0; k < str_i.size(); k++) {
					if (str_i[k] != str_j[k]) diff++;
					if (diff > 1) break;
				}
				if (diff == 1) {
					it_map = neighbor_map.find(str_i);
					if (it_map == neighbor_map.end()) {
						vector<string> neighbor_vec;
						neighbor_map.insert(pair<string,vector<string>>(str_i, neighbor_vec));
						it_map = neighbor_map.find(str_i);
					}
					vector<string> &nei_i_vec = it_map->second;
					nei_i_vec.push_back(str_j);
					
					it_map = neighbor_map.find(str_j);
					if (it_map == neighbor_map.end()) {
						vector<string> neighbor_vec;
						neighbor_map.insert(pair<string,vector<string>>(str_j,neighbor_vec));
						it_map = neighbor_map.find(str_j);
					}
					vector<string> &nei_j_vec = it_map->second;
					nei_j_vec.push_back(str_i);
				}
			}
		}
	}
};

/**********************************************/

struct GraphNode {
	string val;
	char color;
	int depth;
	vector<GraphNode *> nei_vec;
	GraphNode(string s):val(s),color(0),depth(0){}
};

class Solution3 {
public:
	int ladderLength(string start, string end, set<string> &dict) { //unordered_set
		GraphNode *graph;
		buildGraph(graph, dict, start, end);
		
		int len = breadth_first(graph, start, end);
		return len;
	}

	int breadth_first(GraphNode *graph, string start, string end) 
	{
		vector<GraphNode *>::iterator it_vec;
		queue<GraphNode *> breadth_queue;
		breadth_queue.push(graph);
		graph->color=1; graph->depth=1;
		while (!breadth_queue.empty()) {
			GraphNode *top = breadth_queue.front();
			breadth_queue.pop();
			int curr_depth = top->depth;

			vector<GraphNode *> in_vec = top->nei_vec;
			for (it_vec = in_vec.begin(); it_vec != in_vec.end(); it_vec++) {
				GraphNode *tmp_node = *it_vec;
				if (tmp_node->val == end) return curr_depth + 1;

				if (tmp_node->color == 1) continue;
				breadth_queue.push(tmp_node);
				tmp_node->color = 1;
				tmp_node->depth = curr_depth + 1;
			}
		}
		return 0;
	}

	void buildGraph(GraphNode *& graph, set<string> &dict, string start, string end) 
	{		
		dict.insert(start);
		dict.insert(end);

		vector<GraphNode *> graph_vec;
		set<string>::iterator it_set;
		for (it_set = dict.begin(); it_set != dict.end(); it_set++) {
			GraphNode *node = new GraphNode(*it_set);
			graph_vec.push_back(node);
			if (*it_set == start) graph = node;
		}
				
		for (int i = 0; i < graph_vec.size()-1; i++) {
			GraphNode *node_i = graph_vec[i];
			string str_i = node_i->val;
			for (int j = i + 1; j < graph_vec.size(); j++) {
				GraphNode *node_j = graph_vec[j];
				string str_j = node_j->val;
				int diff = 0;
				for (int k = 0; k < str_i.size(); k++) {
					if (str_i[k] != str_j[k]) diff++;
					if (diff > 1) break;
				}
				if (diff == 1) {
					node_i->nei_vec.push_back(node_j);
					node_j->nei_vec.push_back(node_i);
				}
			}
		}
	}
};

class Solution {
public:
	int ladderLength(string start, string end, set<string> &dict) { //unordered_set
		list<string> str_list;
		list<string>::iterator it_list;
		set<string>::iterator it_set;
		str_list.push_back(end);
		for (it_set = dict.begin(); it_set != dict.end(); it_set++) 
			str_list.push_back(*it_set);
		
		int depth = 1;
		vector<string> nei_vec(1,start);
		while (true) {
			vector<string> add_vec;
			vector<string>::iterator it_last_vec;
			for (it_last_vec = nei_vec.begin(); it_last_vec != nei_vec.end(); 
				it_last_vec++) 
			{
				string str_i = *it_last_vec;
				
				it_list = str_list.begin();
				while (it_list != str_list.end()) {
					string str_j = *it_list;

					int diff = 0;
					for (int k = 0; k < str_i.size(); k++) {
						if (str_i[k] != str_j[k]) diff++;
						if (diff > 1) break;
					}
					if (diff == 1) {
						if (str_j == end) return depth + 1;
						add_vec.push_back(str_j);
						it_list = str_list.erase(it_list);
					} else it_list++;
				}	
				if (str_list.empty()) return 0;
			}
			if (add_vec.size()==0)return 0;
			nei_vec = add_vec;
			depth++;
		}
		return 0;
	}
};

void ladderLength_test_case1() {
	Solution solution;
	set<string> dict;
	dict.insert("hot"); dict.insert("dot"); dict.insert("dog");
	dict.insert("lot"); dict.insert("log");

	string start = "hit", end = "cog";
	int len = solution.ladderLength(start, end, dict);
	cout << len << endl;
}

void ladderLength_test_case2() {
	Solution solution;
	set<string> dict;
	dict.insert("a"); dict.insert("b"); dict.insert("c");

	string start = "a", end = "c";
	int len = solution.ladderLength(start, end, dict);
	cout << len << endl;
}

void ladderLength_test_case3() {
	Solution solution;
	
	string arr[] = {"dose","ends","dine","jars","prow","soap","guns","hops","cray","hove","ella","hour","lens","jive","wiry","earl","mara","part","flue","putt","rory","bull","york","ruts","lily","vamp","bask","peer","boat","dens","lyre","jets","wide","rile","boos","down","path","onyx","mows","toke","soto","dork","nape","mans","loin","jots","male","sits","minn","sale","pets","hugo","woke","suds","rugs","vole","warp","mite","pews","lips","pals","nigh","sulk","vice","clod","iowa","gibe","shad","carl","huns","coot","sera","mils","rose","orly","ford","void","time","eloy","risk","veep","reps","dolt","hens","tray","melt","rung","rich","saga","lust","yews","rode","many","cods","rape","last","tile","nosy","take","nope","toni","bank","jock","jody","diss","nips","bake","lima","wore","kins","cult","hart","wuss","tale","sing","lake","bogy","wigs","kari","magi","bass","pent","tost","fops","bags","duns","will","tart","drug","gale","mold","disk","spay","hows","naps","puss","gina","kara","zorn","boll","cams","boas","rave","sets","lego","hays","judy","chap","live","bahs","ohio","nibs","cuts","pups","data","kate","rump","hews","mary","stow","fang","bolt","rues","mesh","mice","rise","rant","dune","jell","laws","jove","bode","sung","nils","vila","mode","hued","cell","fies","swat","wags","nate","wist","honk","goth","told","oise","wail","tels","sore","hunk","mate","luke","tore","bond","bast","vows","ripe","fond","benz","firs","zeds","wary","baas","wins","pair","tags","cost","woes","buns","lend","bops","code","eddy","siva","oops","toed","bale","hutu","jolt","rife","darn","tape","bold","cope","cake","wisp","vats","wave","hems","bill","cord","pert","type","kroc","ucla","albs","yoko","silt","pock","drub","puny","fads","mull","pray","mole","talc","east","slay","jamb","mill","dung","jack","lynx","nome","leos","lade","sana","tike","cali","toge","pled","mile","mass","leon","sloe","lube","kans","cory","burs","race","toss","mild","tops","maze","city","sadr","bays","poet","volt","laze","gold","zuni","shea","gags","fist","ping","pope","cora","yaks","cosy","foci","plan","colo","hume","yowl","craw","pied","toga","lobs","love","lode","duds","bled","juts","gabs","fink","rock","pant","wipe","pele","suez","nina","ring","okra","warm","lyle","gape","bead","lead","jane","oink","ware","zibo","inns","mope","hang","made","fobs","gamy","fort","peak","gill","dino","dina","tier"};

	set<string> dict(arr, arr + sizeof(arr)/sizeof(string));
	string start = "nape", end = "mild";
	int len = solution.ladderLength(start, end, dict);
	cout << len << endl;
}

void ladderLength_test_case4() {
	Solution solution;
	
	string arr[] = {"hot","dog"};
	set<string> dict(arr, arr + sizeof(arr)/sizeof(string));
	string start = "hot", end = "dog";
	int len = solution.ladderLength(start, end, dict);
	cout << len << endl;
}

int main_wordLadder(int argc, char **argv) {
	ladderLength_test_case1();
	ladderLength_test_case2();
	ladderLength_test_case3();
	ladderLength_test_case4();
	return 0;
}