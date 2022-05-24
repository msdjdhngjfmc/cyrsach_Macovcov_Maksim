#pragma once
#include <fstream>
#include "Queue.h"
#include "List.h"
#include "outList.h"
using namespace std;




	class EdmondsKarp_algorithm
	{
	public:
		struct pair {
			int first;
			long second;
		};
		List<char> listofvertexes;
		outer_list<List<int>> capacity;
		outer_list<List<int>> adj;
		long INF = 100000;

		~EdmondsKarp_algorithm() {
			capacity.clear();
			adj.clear();
			listofvertexes.clear();
		}

		int maxflow() {
			int a;
			a = listofvertexes.get_size();
			/*int maximum_flow = 0;
			List<int> parent(capacity.get_size(), 0);
			int new_flow;
			bfs(0, listofvertexes.get_size() - 1, parent);
			while (new_flow = bfs(0, listofvertexes.get_size() - 1, parent)) {
				maximum_flow += new_flow;
				int cur = listofvertexes.get_size() - 1;
				while (cur != 0) {
					int prev = parent.at(cur);
					capacity.at(prev).set(cur, capacity.at(prev).at(cur) - new_flow);
					capacity.at(cur).set(prev, capacity.at(cur).at(prev) + new_flow);
					cur = prev;
				}
			}*/
			return 5;
		}

		bool input(string input) {
			ifstream file(input);
			if (!file.is_open())
				return false;
			int symb_num = 0;
			char symb;
			int cap;
			char first_vrtx, scnd_vrtx;
			while (!file.eof()) {
				file >> noskipws >> symb;
				if ((symb_num == 0 || symb_num == 2) && !listofvertexes.contains(symb))
					listofvertexes.push_back(symb);
				symb_num++;
				if (symb == '\n' || file.eof())
					symb_num = 0;
			}


			file.clear();
			file.seekg(0);
			List<int> temp;

			for (int i = 0; i < listofvertexes.get_size(); i++) {
				for (int j = 0; j < listofvertexes.get_size(); j++)
					temp.push_back(0);
				capacity.push_back(temp);
				temp.reset();
			}

			while (!file.eof())
			{
				if (symb_num != 4) {
					file >> noskipws >> symb;

					if (symb_num == 0)
						first_vrtx = symb;

					else if (symb_num == 2)
						scnd_vrtx = symb;
				}

				else {
					file >> cap;
					capacity.at(listofvertexes.get_index((char)first_vrtx)).set(listofvertexes.get_index((char)scnd_vrtx), cap);
				}

				symb_num++;
				if (symb == '\n' || file.eof())
					symb_num = 0;

			}

			for (int i = 0; i < capacity.get_size(); i++) {
				temp.reset();
				for (int j = 0; j < capacity.at(i).get_size(); j++) {
					temp.push_back(capacity.at(i).at(j));
				}
				adj.push_back(temp);
			}

			for (int i = 0; i < adj.get_size(); i++) {
				for (int j = i; j < adj.at(i).get_size(); j++) {
					adj.at(j).set(i, adj.at(i).at(j));
				}
			}


			temp.reset();

			List<int> parent(capacity.get_size(), 0);
			return true;
		}

		int bfs(int s, int t, List<int>& parent) {
			for (int i = 0; i < parent.get_size(); i++)
				parent.set(i, -1);
			parent.set(s, -2);
			queue_like <pair> queue;
			queue.enqueue({ s, INF });
			while (queue.get_size() != 0) {
				int cur = queue.peek().first;
				int flow = queue.peek().second;
				queue.dequeue();

				for (int next = 0; next < adj.at(cur).get_size(); next++) {
					if (parent.at(next) == -1 && capacity.at(cur).at(next)) {
						parent.set(next, cur);
						int new_flow;
						if (capacity.at(cur).at(next) < flow)
							new_flow = capacity.at(cur).at(next);
						else
							new_flow = flow;
						if (next == t)
							return new_flow;
						queue.enqueue({ next, new_flow });
					}
				}
			}

			return 0;
		}
	};


