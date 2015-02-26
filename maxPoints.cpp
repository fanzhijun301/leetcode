#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <set>

using namespace std;

/**
 * Definition for a point.
 */
struct Point {
	int x;
	int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
		if (points.size() == 1) return 1;
		if (points.size() == 2) return 2;

		//y = ax + b
        map<pair<double,double>, set<pair<int,int>>> func_map;
		map<pair<double,double>, set<pair<int,int>>>::iterator it_func_map;
		//stat multi point
		map<pair<int,int>,int> point_stat_map;
		map<pair<int,int>,int>::iterator it_psm;
		//x = c
		map<int, int> xc_map;
		map<int, int>::iterator it_map;
		//pre deal points;
		vector<Point> in_points;
		vector<Point>::iterator it_vec;
		set<pair<int,int> > point_set; 
		set<pair<int,int> >::iterator it_set;
		for (it_vec = points.begin(); it_vec != points.end(); it_vec++) {
			Point p = *it_vec;
			pair<int, int> pa(p.x,p.y);
			it_set = point_set.find(pa);
			if (it_set == point_set.end()) {
				in_points.push_back(p);
				point_set.insert(pa);
			}
			//xc
			it_map = xc_map.find(p.x);
			if (it_map == xc_map.end()) {
				xc_map.insert(pair<int,int>(p.x, 0));
				it_map = xc_map.find(p.x);
			}
			int stat = it_map->second;
			xc_map[p.x] = stat + 1;
			//stat
			it_psm = point_stat_map.find(pa);
			if (it_psm == point_stat_map.end()) {
				point_stat_map.insert(pair<pair<int,int>, int>(pa,0));
				it_psm = point_stat_map.find(pa);
			}
			stat = it_psm->second;
			point_stat_map[pa] = stat + 1;
		}

		int size_min_one = in_points.size() - 1;
		int size_point = in_points.size();
		for (int i = 0; i < size_min_one; i++) {
			Point p1 = in_points.at(i);
			int x1 = p1.x;
			int y1 = p1.y;
			pair<int,int> pp1(x1, y1);
			for (int j = i + 1; j < size_point; j++) {
				Point p2 = in_points.at(j);
				int x2 = p2.x;
				int y2 = p2.y;

				if (x1 == x2) continue;
				double a = ((y2-y1) * 1.0) / (x2-x1);
				double b = ((x2*y1-x1*y2) * 1.0) / (x2-x1);
				
				pair<double, double> func_pair(a,b);
				pair<int, int> pp2(x2, y2);
				
				it_func_map = func_map.find(func_pair);
				if (it_func_map == func_map.end()) {
					set<pair<int,int>> point_set;
					func_map.insert(pair<pair<double,double>, set<pair<int, int>>>(func_pair, point_set));
					it_func_map = func_map.find(func_pair);
				}
				set<pair<int, int>> &in_set = it_func_map->second;
				in_set.insert(pp1); in_set.insert(pp2);
			}
		}

		int max_line_points = 0;
		for (it_func_map = func_map.begin(); it_func_map != func_map.end(); it_func_map++) {
			set<pair<int, int>> &in_set = it_func_map->second;
			set<pair<int, int>>::iterator it_set;
			int point_count = 0;
			for (it_set = in_set.begin(); it_set != in_set.end(); it_set++) {
				pair<int, int> point_pair = *it_set;
				it_psm = point_stat_map.find(point_pair);
				if (it_psm != point_stat_map.end()) point_count += it_psm->second;
			}
			if (point_count > max_line_points) max_line_points = point_count;
		}
		
		for (it_map = xc_map.begin(); it_map != xc_map.end(); it_map++) {
			int stat = it_map->second;
			if (stat > max_line_points) max_line_points = stat;
		}
		return max_line_points;
    }
};

void maxPoints_test_case1() {
	Solution solution;
	
	vector<Point> point_vec;
	Point p1(3,6),p2(3,8),p3(3,10),p4(4,8),p5(5,10),p6(6,12),p7(7,14);
	point_vec.push_back(p1); point_vec.push_back(p2); point_vec.push_back(p3);
	point_vec.push_back(p4); point_vec.push_back(p5); point_vec.push_back(p6); point_vec.push_back(p7);
	

	int max_line_points = solution.maxPoints(point_vec);
	cout << max_line_points << endl;
}

void maxPoints_test_case2() {
	Solution solution;
	
	vector<Point> point_vec;
	Point p1(0,0),p2(1,1),p3(0,0);
	point_vec.push_back(p1); point_vec.push_back(p2); point_vec.push_back(p3);

	int max_line_points = solution.maxPoints(point_vec);
	cout << max_line_points << endl;
}

int main_maxPoints(int argc, char **argv) {
	maxPoints_test_case2();
	return 0;	
}
