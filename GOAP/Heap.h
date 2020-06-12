#pragma once
#include <vector>

class Node;

class Heap
{
public:
	Heap();
	~Heap();

	void Add(Node* pNode);
	Node* GetTop();
	int Size();
	void Clear();
	bool Find(Node* pNode);
private:
	int GetChild(int nIndex, int nChild);
	int GetParent(int nIndex);
	std::vector<Node*> m_aNodes;
};
