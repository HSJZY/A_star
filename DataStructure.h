#ifndef DATASTRUCTURE
#define DATASTRUCTURE
#include<iostream>
#include<vector>
#include<algorithm>
#include"MazeTool.h"
using namespace std;
class PosType
{
public:
	PosType(int posX, int posY) :xPosition(posX), yPosition(posY) {};
	PosType() :xPosition(0), yPosition(0) {};
	~PosType();
	void setX(int x) { xPosition = x; };
	int getX() { return xPosition; };
	void setY(int y) { yPosition = y; };
	int  getY() { return yPosition; };
	void setF(int f) { m_F =f ; }
	int getF() { return m_F; }
	void setG(int G) { m_G = G; }
	int getG() { return m_G; }
	void changeParent(PosType position)
	{
		this->parentNode[0] = position.getX();
		this->parentNode[1]= position.getY();
	};
	int* getParent()
	{
		int *retParent = new int[2];
		retParent = parentNode;
		return retParent;
	}
private:
	int xPosition;
	int yPosition;
	int m_F;
	int m_G;
	int parentNode[2];
};

PosType::~PosType()
{
}
//¿ªŒ¯ºÏ
class OpenList
{
public:
	OpenList(PosType position);
	OpenList();
	~OpenList();
	void insertElement(PosType position) 
	{
		int size = m_pos.size();
		bool changed=false;
		/*if (size == 0)
		{
			m_pos.push_back(position);
		}*/
		for (int i = size - 1; i>=0; i--)//žùŸÝFÖµœøÐÐÅÅÐò
		{
			if (position.getF() > m_pos[i].getF())
			{
				m_pos.insert(m_pos.begin()+i+1, position);
				changed = true;
				break;
			}
		}
		if (changed == false)
		{
			m_pos.insert(m_pos.begin(), position);
		}
	};
	bool elemInList(PosType position)//Œì²éÊÇ·ñÔÚŒ¯ºÏÖ®ÖÐ
	{
		int size = m_pos.size();
		for (int i = 0; i < size; i++)
		{
			if (m_pos[i].getX() == position.getX() && m_pos[i].getY() == position.getY())
			{
				return true;
			}

		}
		return false;
	};
	void deleteElement(PosType position) 
	{
		if (elemInList(position))
		{
			int size = m_pos.size();
			for (int i=0; i<size; i++)
			{
				if (m_pos[i].getX() == position.getX() && m_pos[i].getY() == position.getY()) 
				{
					vector<PosType>::iterator it=m_pos.begin()+i;
					m_pos.erase(it);
					i = 0;
					size--;
				}
			}
		}
	};
	bool isEmpty()
	{
		if (m_pos.size() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	PosType	getFirst()
	{
		return m_pos[0];
	}
private:
	vector<PosType> m_pos;
};

OpenList::OpenList(PosType position)
{
	m_pos.push_back(position);
}
OpenList::OpenList()
{
}
OpenList::~OpenList()
{
}

//±ÕŒ¯ºÏ
class ClosedList
{
public:
	ClosedList();
	ClosedList(PosType position);
	~ClosedList();
	void appendElement(PosType position)
	{
		m_Closed.push_back(position);
	}
	bool elemInList(PosType position)//Œì²éÊÇ·ñÔÚŒ¯ºÏÖ®ÖÐ
	{
		int size = m_Closed.size();
		for (int i = 0; i < size; i++)
		{
			if (m_Closed[i].getX()==position.getX()&&m_Closed[i].getY()==position.getY())
			{
				return true;
			}
			
		}
		return false;
		
	};
	PosType getback(int x,int y)
	{
		int size = m_Closed.size();
		for (int i = 0; i < size; i++)
		{
			if ( m_Closed[i].getX()==x && y == m_Closed[i].getY())
			{
				return m_Closed[i];
			}
		}
	}
private:
	vector<PosType> m_Closed;
};

ClosedList::ClosedList(PosType position)
{
	m_Closed.push_back(position);
}
ClosedList::ClosedList()
{
}

ClosedList::~ClosedList()
{
}



#endif // DATASTRUCTURE
