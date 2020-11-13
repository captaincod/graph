
// Реализация алгоритма Дейкстры

#include "Graph.cpp"
#include "Node.cpp"
#include "PriorityQueue.cpp"
using namwspace std;


struct Way {
	vector<Node*> nodes;
	int length;
	Way() : length(-1) {}
};

class Dijkstra {
	const Graph& graph;
public:
	Dijkstra(const Graph& agraph) : graph(agraph) {}
	Way shortestWay(Node* begin, Node* end);
};Way Dijkstra::shortestWay(Node* begin, Node* end) {
	PriorityQueue nodes; nodes.push(begin, 0, 0);
	map<Node*, MarkedNode> visited;
	while (!nodes.empty()) {
		MarkedNode next = nodes.pop();
		visited[next.node] = next;
		if (end == next.node) return unroll(visited, begin, end);
		for (node_iterator it = next.node->nb_begin();
			it != next.node->nb_end(); it++) {
			int weight = (*it)->getWeight(next.node) + next.mark;
			if (visited.find(*it) == visited.end())
				nodes.push(*it, weight, next.node);
		}
	}
	return Way();
}

//Раскрутка пути
static Way unroll(std::map<Node*, MarkedNode> visited,
	Node* begin, Node* curr) {
	Way way;
	way.length = visited[curr].mark;
	while (curr != begin) {
		way.nodes.push_back(curr);
		curr = visited[curr].prev;
	}
	way.nodes.push_back(begin);
	return way;
}// цикл for-each// nodes must have begin() and end(),
// iterator must have ++, ->, *
for (Node* other : nodes) {
	other->removeNeighbour(node);
}
// Is equivalent to
for (set<Node*>::iterator it = nodes.begin();
	it != nodes.end(); it++) {
	(*it)->removeNeighbour(node);
}