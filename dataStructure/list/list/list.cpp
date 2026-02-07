#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
	// 用法1：默认构造函数
	ListNode* node1 = new ListNode();     // val=0, next=nullptr
	cout << "node1: val=" << node1->val << endl;

	// 用法2：单参数构造函数
	ListNode* node2 = new ListNode(5);    // val=5, next=nullptr
	cout << "node2: val=" << node2->val << endl;

	// 用法3：双参数构造函数
	ListNode* node3 = new ListNode(3, node2);  // val=3, next指向node2
	cout << "node3: val=" << node3->val << ", next指向节点的val=";
	if (node3->next) cout << node3->next->val << endl;

	// 创建链表 1->2->3
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3)));

	// 遍历链表
	ListNode* current = head;
	while (current) {
		cout << current->val << " -> ";
		current = current->next;
	}
	cout << "nullptr" << endl;

	return 0;
}