#include <queue>
#include <iostream>

using namespace std;

template <class T>
class ArvoreNo
{
public:
	T el;
	ArvoreNo<T> *left, *right;
	ArvoreNo()
	{
		left = right = 0;
	}
	ArvoreNo(T e, ArvoreNo<T> *l = 0, ArvoreNo<T> *r = 0)
	{
		el = e;
		left = l;
		right = r;
	}
};

template <class T>
class Arvore
{
protected:
	ArvoreNo<T> *root;

public:
	Arvore()
	{
		root = 0;
	}
	~Arvore()
	{
		clear();
	}
	void clear()
	{
		clear(root);
		root = 0;
	}

	ArvoreNo<T> *getRoot()
	{
		return root;
	}
	bool isEmpty() const
	{
		return root == 0;
	}

	void visit(ArvoreNo<T> *p)
	{
		cout << p->el << " ";
	}

	T search(T el)
	{
		ArvoreNo<T> *p = root;
		while (p != 0)
		{
			if (el == p->el)
				return p->el;
			else
			{
				if (el < p->el)
					p = p->left;
				else
					p = p->right;
			}
		}
		return 0;
	}

	void insert(T el)
	{
		ArvoreNo<T> *p = root, *prev = 0;
		while (p != 0)
		{
			prev = p;
			if (el < p->el)
				p = p->left;
			else
				p = p->right;
		}
		if (root == 0)
			root = new ArvoreNo<T>(el);
		else if (el < prev->el)
			prev->left = new ArvoreNo<T>(el);
		else
			prev->right = new ArvoreNo<T>(el);
	}

	void percusoExtensao()
	{
		queue<ArvoreNo<T> *> f;
		ArvoreNo<T> *p = root;
		if (p != 0)
		{
			f.push(p);
			while (!f.empty())
			{
				p = f.front();
				visit(p);
				f.pop();
				if (p->left != 0)
					f.push(p->left);
				if (p->right != 0)
					f.push(p->right);
			}
		}
	}

	void preorder(ArvoreNo<T> *p)
	{
		if (p != 0)
		{
			visit(p);
			preorder(p->left);
			preorder(p->right);
		}
	}

	void clear(ArvoreNo<T> *p)
	{
		if (p != 0)
		{
			clear(p->left);
			clear(p->right);
			delete p;
		}
	}

	int calcularAltura(ArvoreNo<T> *node)
	{
		if (node == 0)
			return 0;

		int alturaEsquerda = calcularAltura(node->left);
		int alturaDireita = calcularAltura(node->right);

		return 1 + max(alturaEsquerda, alturaDireita);
	}

	int calcularBalanceamento(ArvoreNo<T> *node)
	{
		if (node == 0)
			return 0;

		int alturaEsquerda = calcularAltura(node->left);
		int alturaDireita = calcularAltura(node->right);

		return alturaEsquerda - alturaDireita;
	}

	bool verificarBalanceamento(ArvoreNo<T> *node)
	{
		if (node == 0)
			return true;

		int balanceamento = calcularBalanceamento(node);
		if (balanceamento > 1 || balanceamento < -1)
			return false;

		return verificarBalanceamento(node->left) && verificarBalanceamento(node->right);
	}

	void backbone(ArvoreNo<T> *p)
	{
		if (p == 0)
			return;
		ArvoreNo<T> *prev = 0;
		while (p != 0)
		{
			if (p->left != 0)
			{
				ArvoreNo<T> *r = p->left;
				p->left = r->right;
				r->right = p;
				if (prev != 0)
					prev->right = r;
				else
					root = r;
				p = r;
			}
			prev = p;
			p = p->right;
		}
	}
};

int main()
{
	Arvore<int> *a = new Arvore<int>();

	a->insert(50);
	a->insert(30);
	a->insert(70);
	a->insert(20);
	a->insert(40);
	a->insert(60);
	a->insert(77);

	int altura = a->calcularAltura(a->getRoot());
	cout << "Altura: " << altura << endl;

	cout << "Árvore resultante: ";
	a->preorder(a->getRoot());
	cout << endl;

	bool balanceada = a->verificarBalanceamento(a->getRoot());
	if (balanceada)
		cout << "Balanceada." << endl;
	else
		cout << "Não está balanceada." << endl;

	// 1.4) Primeira parte do algoritmo DWS
	a->backbone(a->getRoot());

	cout << "Árvore após as rotações: ";
	a->preorder(a->getRoot());
	cout << endl;

	delete a;
}

/*
Altura: 3
Árvore resultante: 50 30 20 40 70 60 77 
Balanceada.
Árvore após as rotações: 30 20 40 50 60 70 77 
*/
