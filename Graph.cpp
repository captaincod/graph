
// Граф

#include "Node.cpp"
using namespace std;


typedef set<Node*>::const_iterator node_iterator;

class Graph {
	set<Node*> nodes;
public:
	void addNode(Node* node);
	void removeNode(Node* node);
	void addEdge(Node* begin, Node* end);
	void removeEdge(Node* begin, Node* end);
	node_iterator begin() const {
		return nodes.begin();
	}
	node_iterator end() const { return nodes.end(); }
};

void Graph::removeNode(Node* node) {
	nodes.erase(node);
	// Remove also from all neighbours list
	for (set<Node*>::iterator it = nodes.begin();
		it != nodes.end(); it++) {
		(*it)->removeNeighbour(node);
	}
}

void Graph::addEdge(Node* begin, Node* end) {
	if (nodes.find(begin) == nodes.end())
		return;
	if (nodes.find(end) == nodes.end())
		return;
	begin->addNeighbour(end);
	end->addNeighbour(begin);
}
