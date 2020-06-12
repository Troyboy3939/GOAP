#pragma once

#include <vector>


class Node
{
public:
	Node();
	enum class Type
	{
		GOAL,
		ACTION
	};
	Node* GetChild(int nIndex);
	std::vector<Node*>* GetChildren();
	Type GetType();
	void AddChild(Node* pChild);

	Node* GetParent();

	int GetFScore();
	int GetHScore();
	int GetGScore();

	void SetFScore(int nFScore);
	void SetHScore(int nHScore);
	void SetGScore(int nGScore);

	bool operator==(Node* pRHS);

	int GetID();

protected:
	
	std::vector<Node*> m_aChildren;
	
	//used as the previous node in A* algorithm
	Node* m_pParent;

	//the type of node it is (Goal or action node)
	Type m_eType;

	//F = G + H
	int m_nFScore;

	//Cost of getting to node
	int m_nGScore;

	//Hueristic
	int m_nHScore;

	int m_nID;

	static int m_nNumberOfNodes;
};

