#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <iomanip>
#include<sstream>
#include<time.h>
#include<queue>
#include<map>
#include<unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

 class Solution {
	 //ָ��pָ��ǰ�����������ڵ�����һ��λ��
	 //����һ��ָ��qָ�����ȡ�������ڵ��ǰһ��λ��
 public:
	static ListNode* oddEvenList(ListNode* head)  {
		 if (!head)return head;
		 ListNode *p = head, *q = head;
		 ListNode* OH = head;
		 while (q){
			 q = q->next;
			 if (!q || !q->next)break;
			 while (head){
				 cout << head->val << " ";
				 head = head->next;
			 }
			 head = OH;
			 cout << "UNUM:" << q->val << " " << p->val << endl;
			 ListNode *next_p = p->next, *next_q = q->next;
			 q->next = next_q->next;
			 p->next = next_q;
			 next_q->next = next_p;
			 p = p->next;

		 }
		 return head;
	}

	static void makeList(ListNode* head,int num){
		 int i = 1;
		 ListNode*p = head;
		 while (num){
			 ListNode *s = new ListNode(i++);
			 p->next = s;
			 p = p->next;
			 --num;
		 }
	 }

	static ListNode* oddEven(ListNode*head){
		if (!head)return head;
		ListNode* pOdd = head;
		ListNode* p = head->next;
		ListNode* pNext = NULL;
		ListNode* OH = head;
		while (p && (pNext = p->next)){
			
			while (head){
				cout << head->val << " ";
				head = head->next;
			}
			head = OH;
			cout << "ǰ" << pOdd->val << " " << p->val << endl;
			p->next = pNext->next;
			pNext->next = pOdd->next;
			pOdd->next = pNext;

			p = p->next;
			pOdd = pOdd->next;
			//cout <<"��"<< pOdd->val << " " << p->val << endl;
		}
		return head;
	}
 };

int main(){
	//cout << "Hell\n" << endl;
	ListNode* head=new ListNode(0);
	ListNode* p = head;
	Solution::makeList(head, 5);
	while (head){
		cout << head->val<<" ";
		head = head->next;
	}
	cout << endl;
	head = p;
	head = head->next;
	cout << head->val << endl;
	//head=Solution::oddEven(head);
	head = Solution::oddEvenList(head);
	while (head){
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}