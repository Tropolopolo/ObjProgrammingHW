#include <vector>

template<class T>
class Node
{
public:
	Node(int i = 0, std::string s = "") : id(i), type(s) {};

	//gets
	int getId()
	{
		return id;
	}

	//sets
	void setId(int i)
	{
		id = i;
	}

	//other
	void addArc(Node* n)
	{
		arcs.push_back(n);
	}

	void removeArc(int i)
	{
		arcs.erase(i);
	}

private:
	T t;
	int id;
	std::string type;
	std::vector<Node*> arcs;
};