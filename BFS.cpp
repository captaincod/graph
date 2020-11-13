
// –еализаци€ поиска в ширину
// ÷ель Ц определить, существует ли путь между двум€ заданными вершинами


#include "Graph.cpp"
#include "Node.cpp"
using namwspace std;

class BFS {
	const Graph& graph;
public:
	BFS(const Graph& agraph) : graph(agraph) {}
	bool connected(Node* begin, Node* end);
};

bool BFS::connected(Node* begin, Node* end) {
	queue<Node*> nodes; nodes.push(begin);
	set<Node*> visited;
	while (!nodes.empty()) {
		Node* next = nodes.front(); nodes.pop();
		if (end == next) return true;
		visited.insert(next);
		for (node_iterator it = next->nb_begin();
			it != next->nb_end(); it++)
			if (visited.find(*it) == visited.end())
				nodes.push(*it);
	}
	return false;
}