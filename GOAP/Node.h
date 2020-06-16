#pragma once

#include <vector>


class Node
{
public:
	Node();
	enum class Type
	{
		GOAL,
		ACTION,
		NONE
	};
	Node* GetChild(int nIndex);
	std::vector<Node*>* GetChildren();
	Type GetType();
	void AddChild(Node* pChild);

	Node* GetParent();

	float GetFScore();
	float GetHScore();
	float GetGScore();

	void SetFScore(float nFScore);
	void SetHScore(float nHScore);
	void SetGScore(float nGScore);

	bool operator==(Node* pRHS);

	int GetID();

protected:
	
	std::vector<Node*> m_aChildren;
	
	//used as the previous node in A* algorithm
	Node* m_pParent;

	//the type of node it is (Goal or action node)
	Type m_eType;

	//F = G + H
	float m_nFScore;

	//Cost of getting to node
	float m_nGScore;

	//Hueristic
	float m_nHScore;

	int m_nID;

	static int m_nNumberOfNodes;
};

