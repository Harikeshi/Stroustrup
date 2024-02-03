
template<typename T>
class Tree {


	using value_type = T;
	enum Policy { rb, splay, treeps };

	class Node {

		Node* right;
		Node* left;
		value_type value;
	public:
		void f(Tree* t);

	};

	Node* top;
public:
	void g(const T&) {
		
	}

};

template<typename T>
void Tree<T>::Node::f(Tree* t)
{
	//top = right;
	t->top = right;
	value_type v = left->value;
}
