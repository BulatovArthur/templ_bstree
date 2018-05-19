#include <iostream>
#include <fstream>
#include <initializer_list>
#include <string>

using namespace std;

namespace BSTree {
	template <typename type>
        struct Node {
                type data;
                Node<type> *left;
                Node<type> *right;
                Node(type val);
        };
	enum traversal_order {pre, in, post};
	template <typename type>
        class Tree {
                Node<type> *root;
                void Add(type m_data, Node<type> *&m_root);
                void Print(Node<type> *m_root, int space) const;
                void Clear(Node<type> *&m_root);
                void Transversal(Node<type> *m_root) const;
                void Straight(Node<type> *m_root) const;
                void Reverse(Node<type> *m_root) const;
                bool Compare(type m_item, Node<type> *&m_root) const;
                void Deleting(type m_item, Node<type> *&m_root);
                void Saving(Node<type> *m_root, int space, string m_address) const;
		void Appropriation(Node<type> *m_root);
		void Auxiliary_fun(ostream& stream, Node<type> *m_root, int space);
         public:
                Tree();
        	Tree(initializer_list<type> list);
        	Tree(const Tree& tree);
                bool Check() const;
                void Print() const;
                void Add(type m_data);
                void Transversal() const;
                void Straight() const;
                void Reverse() const;
                bool Compare(type m_item);
                void Deleting(type m_item);
                void Saving() const;
                void Loading(string m_address);
                void Loading();
		void Detour();
		auto operator=(const Tree&) -> Tree&;
        	auto friend operator<<(ostream& stream, Tree& tree) -> ostream& {
            		tree.Auxiliary_fun (stream, tree.root, 0);
            		return stream;
        	}
		~Tree();
        };

	template <typename type>
	Node<type>::Node(type val) : data(val), left(nullptr), right(nullptr) {}

	template <typename type>
	Tree<type>::Tree() : root(nullptr) {}

	template <typename type>
	Tree<type>::Tree(initializer_list<type> list) : root(nullptr) {
		for (auto p = list.begin(); p != list.end(); p++)
                	Add(*p);
	}

	template <typename type>
	Tree<type>::Tree(const Tree<type>& tree) : root(nullptr) {
		Appropriation(tree.root);
	}

	template <typename type>
	void Tree<type>::Appropriation(Node<type> *m_root) {
        	Add(m_root->data);
        	if (m_root->left != nullptr)
                	Appropriation(m_root->left);
        	if (m_root->right != nullptr)
                	Appropriation(m_root->right);
	}

	template <typename type>
	bool Tree<type>::Check() const {
		if (root == nullptr)
			return false;
		else
			return true;
	}

	template <typename type>
	void Tree<type>::Add(type m_data, Node<type> *&m_root) {
        	if (m_root == nullptr)
                	m_root = new Node<type>{m_data};
        	if (m_data < m_root->data) {
                	if (m_root->left != nullptr)
                        	Add(m_data, m_root->left);
                	else
                        	m_root->left = new Node<type>{m_data};
        	}
        	if (m_data > m_root->data) {
                	if (m_root->right != nullptr)
                        	Add(m_data, m_root->right);
                	else
                        	m_root->right = new Node<type>{m_data};
        	}
	}

	template <typename type>
	void Tree<type>::Clear(Node<type> *&m_root) {
        	if (m_root != nullptr) {
                	Clear(m_root->left);
                	Clear(m_root->right);
                	delete m_root;
                	m_root = nullptr;
        	}
	}

	template <typename type>
	void Tree<type>::Add(type m_data) {
        	Add(m_data, root);
	}

	template <typename type>
	void Tree<type>::Detour() {
		cout << "Enter order code (0-2)" << endl;
		cout << "0. In" << endl;
		cout << "1. Pre" << endl;
		cout << "2. Post" << endl;
		int code;
		cin >> code;
		switch (code) {
			case in :
				Transversal();
				cout << endl;
				break;
			case pre :
				Straight();
				cout << endl;
				break;
			case post :
				Reverse();
				cout << endl;
				break;
		}

	}

	template <typename type>
	void Tree<type>::Print(Node<type> *m_root, int space) const {
        	if (m_root == nullptr)
                	return;
        	int count = 1;
        	space += count;
        	Print(m_root->right, space);
        	cout << endl;
        	for (int i = count; i < space; i++)
                	cout << "   ";
        	cout << "--" << m_root->data << endl;
        	Print(m_root->left, space);
	}

	template <typename type>
	void Tree<type>::Print() const {
		Print(root, 0);
	}

	template <typename type>
	void Tree<type>::Transversal(Node<type> *m_root) const {
		if (m_root->left != nullptr)
			Transversal(m_root->left);
		cout << m_root->data << " ";
		if (m_root->right != nullptr)
			Transversal(m_root->right);
	}

	template <typename type>
	void Tree<type>::Transversal() const {
		Transversal(root);
	}

	template <typename type>
	void Tree<type>::Straight(Node<type> *m_root) const {
		cout << m_root->data << " ";
		if (m_root->left != nullptr)
			Straight(m_root->left);
		if (m_root->right != nullptr)
			Straight(m_root->right);
	}

	template <typename type>
	void Tree<type>::Straight() const {
		Straight(root);
	}

	template <typename type>
	void Tree<type>::Reverse(Node<type> *m_root) const {
		if (m_root->left != nullptr)
			Reverse(m_root->left);
  		if (m_root->right != nullptr)
			Reverse(m_root->right);
  		cout << m_root->data << " ";
	}

	template <typename type>
	void Tree<type>::Reverse() const {
		Reverse(root);
	}

	template <typename type>
	bool Tree<type>::Compare(type m_item, Node<type> *&m_root) const {
		if (m_root == nullptr)
			return false;
		if (m_item == m_root->data)
			return true;
		if (m_item < m_root->data) {
			if (m_root->left != nullptr)
				return Compare(m_item, m_root->left);
			else
				return false;
		} else {
			if (m_root->right != nullptr)
				return Compare(m_item, m_root->right);
			else
				return false;
		}
	}

	template <typename type>
	bool Tree<type>::Compare(type m_item) {
		Compare (m_item, root);
	}

	template <typename type>
	void Tree<type>::Deleting(type m_item, Node<type> *&m_root) {
    		if (m_item == m_root->data) {
        		Node<type> *tmp;
        		if (m_root->right == nullptr)
            			tmp = m_root->left;
        		else {
            			Node<type> *ptr = m_root->right;
            			if (ptr->left == nullptr) {
                			ptr->left = m_root->left;
                			tmp = ptr;
            			} else {
                			Node<type> *pmin = ptr->left;
                			while (pmin->left != nullptr) {
                    				ptr  = pmin;
                    				pmin = ptr->left;
                			}
                			ptr->left = pmin->right;
                			pmin->left = m_root->left;
                			pmin->right = m_root->right;
                			tmp = pmin;
            			}
        		}
        	delete m_root;
		m_root = tmp;
    		} else if (m_item < m_root->data)
        			Deleting(m_item, m_root->left);
    			else
        			Deleting(m_item, m_root->right);
	}

	template <typename type>
	void Tree<type>::Deleting(type m_item) {
		Deleting(m_item, root);
	}

	template <typename type>
	void Tree<type>::Saving(Node<type> *m_root, int space, string m_address) const {
		ofstream fout(m_address, ios_base::app);
        	if (m_root == nullptr)
                	return;
        	int count = 1;
        	space += count;
        	Saving(m_root->right, space, m_address);
        	fout << endl;
        	for (int i = count; i < space; i++)
                	fout << "   ";
        	fout << "--" << m_root->data << endl;
        	Saving(m_root->left, space, m_address);
		fout.close();
	}

	template <typename type>
	void Tree<type>::Saving() const {
		string address;
		cout << "Enter the path to the file: ";
		cin >> address;
		ifstream file;
		file.open(address);
		if (!file.is_open())
			cerr << "This file does not exist" << endl;
		else {
			file.seekg(0, ios::end);
			if (file.tellg() == 0) {
				file.close();
                		Saving(root, 0, address);
			}
			else {
				cout << "File already exists, overwrite?:" << endl;
				string exit;
				cin >> exit;
				if ((exit == "y") || (exit == "yes")) {
					file.close();
					ofstream file(address, ios_base::out | ios_base::trunc);
					file.close();
					Saving(root, 0, address);
				}
				else
					return;
			}
		}
	}

	template <typename type>
	void Tree<type>::Loading(string address) {
		ifstream fin(address);
    		string stree;
    		getline (fin, stree);
    		int count = 0;
    		for (int i=0; i< stree.length(); i++) {
        		if (stree[i] == ' ')
				count++;
    		}
    		fin.close();
    		fin.open(address);
    		for (int i = 0; i <= count; i++) {
        		fin >> stree;
        		Add(atoi(stree.data()));
    		}
		fin.close();
	}

	template <typename type>
	void Tree<type>::Loading() {
        	string address;
        	cout << "Enter the path to the file: ";
        	cin >> address;
        	ifstream file;
        	file.open(address);
        	if (!file.is_open())
                	cerr << "This file does not exist" << endl;
        	else {
        		file.close();
                	Loading(address);
		}
	}

	template <typename type>
	void Tree<type>::Auxiliary_fun(ostream& stream, Node<type> *m_root, int space) {
        	if (m_root == nullptr)
                	return;
        	int count = 1;
        	space += count;
        	Auxiliary_fun(stream, m_root->right, space);
        	cout << endl;
        	for (int i = count; i < space; i++)
                	stream << "   ";
        	stream << "--" << m_root->data << endl;
        	Auxiliary_fun(stream, m_root->left, space);
	}

	template <typename type>
	auto Tree<type>::operator=(const Tree<type>&) -> Tree& {
		Node<type> *ptr  = nullptr;
        	try {
                	ptr->left = new Node(*tree.root->left);
                	ptr->right = new Node(*tree.root->right);
        	}
        	catch(...) {
                	delete ptr;
                	throw;
        	}
        	this->root->data = tree.root->data;
        	swap(root->left, ptr->left);
        	swap(root->right, ptr->right);
        	delete ptr;
        	return *this;
	}

	template <typename type>
	Tree<type>::~Tree() {
        	Clear(root);
	}
}
