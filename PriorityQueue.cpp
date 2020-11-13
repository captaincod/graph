// Очередь с приоритетами - методы

#include "Graph.cpp"
#include "Node.cpp"
using namwspace std;


struct MarkedNode {
	Node* node; int mark;
	Node* prev;
	MarkedNode(Node* anode = 0, int amark = 0, Node * aprev = 0) :
		node(anode), mark(amark), prev(aprev) {}
};

class PriorityQueue {
	vector<MarkedNode> nodes;
public:
	MarkedNode pop();
	void push(Node* node, int mark, Node* prev);
	bool empty() const { return nodes.empty(); }
};MarkedNode PriorityQueue::pop() {
	MarkedNode mn = nodes.back();
	nodes.pop_back();
	return mn;
}

void PriorityQueue::push(Node* node, int mark, Node* prev) {
	std::vector<MarkedNode>::iterator it = nodes.begin();
	MarkedNode mn(node, mark, prev);
	// From higher to lower
	while (it != nodes.end() && mark < it->mark) it++;
	if (it == nodes.end()) nodes.push_back(mn);
	else nodes.insert(it, mn);
}