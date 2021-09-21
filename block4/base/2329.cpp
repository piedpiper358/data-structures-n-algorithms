#include <iostream>



using namespace std;

void search(int);

struct NODE {	// Структура "Узел" для элементов дерева

	int elem;	// данные
	NODE *left;		// левое поддерево
	NODE *right;	// правое поддерево
	NODE(int el) { left = right = NULL; elem = el; }
};

NODE *root;	// глобальный корень дерева

void push(int el) { // вставка нового элемента в дерево

	if (!root) {
		root = new NODE(el);
		return;
	}

	NODE *buf;
	buf = root;

	while (true) {
		if (buf->elem >= el) {
			if (!buf->left) {
				buf->left = new NODE(el);
				return;
			}
			buf = buf->left;
		}
		else {
			if (!buf->right) {
				buf->right = new NODE(el);
				return;
			}
			buf = buf->right;
		}
	}
}

void search(int key) {
	// ЭТУ ФУНКЦИЮ НУЖНО НАПИСАТЬ
	NODE *buf;
	buf = root;
	while (true) {
		if (buf->elem == key) {
			
			cout << "Element \""<< key <<"\" is found.\n";
			return;
		}
		if (buf->elem > key) {
			if (buf->left) {
				
				buf = buf->left;
			}
			else{
				cout << "Element \""<< key <<"\" is not found.\n";
				return;
			}
		}
		else {
			if (buf->right) {
				buf = buf->right;
			}
			else{
				cout << "Element \""<< key <<"\" is not found.\n";
				return;
			}
		}
	}
}

void print(NODE* cur) {	// печать, симметричный обход
	if (cur->left) {
		print(cur->left);
	}
	cout << cur->elem << endl;
	if (cur->right) {
		print(cur->right);
	}
}

int main() {
	// для отладки:
	// вывод дерева print(node) где node - указатель на корень дерева
	// поместить элемент в дерево push(element) прим. - элемент поместится в нужное место.
	// шаблон предназначен для отправки на проверку, для отладки можете самостоятельно
	// помещать свои элементы напр. push(5); push(20); push(50) и т.д. и работать со своими элементами
	
	// Само дерево объявлено глобально в коде
	int N;	// кол-во элементов
	cin >> N;
	for (int i = 0; i < N; i++) {	// ввод элементов в дерево
		int a;
		cin >> a;
		push(a);
	}
	cin >> N;	// искомый элемент
	search(N);	// поиск с выводом
	return 0;
}
