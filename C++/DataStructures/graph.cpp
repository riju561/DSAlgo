#include <map>
#include <list>
#include <iostream>
using namespace std;

class Graph
{
		int V; // no. of vertices
		list<int> *adjList;
		map<int, bool> visited;
	public:
		Graph(int V)
		{
			V = V;
			adjList = new list<int>[V];
		}

		void addEdge(int v, int w)
		{
			// connects edge between v and w
			adjList[v].push_back(w);
		}

		void BFS(int s)
		{
			// prints BFS traversal from starting node s
		}

		void DFS(int s)
		{
			// prints DFS traversal from starting node s
			visited[s] = true;
			cout << s << " ";

			list<int>::iterator it;
			for(it = adjList[s].begin(); it != adjList[s].end(); it++)
			{
				if(!visited[*it])
				{
					DFS(*it);
				}
			}
		}
};

int main()
{
	int n, u, v;
	char resp;
	cout << "Enter number of vertices in the graph: ";
	cin >> n;
	
	Graph G(n);

	cout << "Enter each edge as u v: " << endl;
	do
	{	
		cin >> u >> v;
		G.addEdge(u, v);

		cout << "Add another node? (y/n): ";
		cin >> resp;

	}while(resp == 'y');

	cout << endl << "DFS Traversal of graph is ";
	G.DFS(1);
	cout << endl;

	cout << endl << "BFS Traversal of graph is ";
	G.BFS(1);
	cout << endl;
	return 0;
}
