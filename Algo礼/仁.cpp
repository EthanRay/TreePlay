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
//	cout << setw(4)<<shortRoad[i][j] << " ";	getline(cin, sent);cin >> hex >> hexNum;p = new ListNode;str.assign(CHAR);&(按位与);{string str = "101";int num = atoi(str.c_str());}
//cout << dec << hexNum;ss.insert(1, "#")a#b;char array[32] = { 0 },int len = strlen(array), _itoa_s(i, array,2,x) or _itoa_s(n,  array,x);x表示x进制2表示字符长度buffer表示存放结果;0x7ffffffe
//"|="按位逻辑或赋值,,scanf("%d-%d %d", &t, &num, &score);(int t, num, score;)；scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d)（l是L表示long long）;最大整型0x7fffffff

class Soluation{
public:
	vector<int> countBits(int num) {
		vector<int>res = vector<int>(0, num+1);
		int pow2 = 1, before = 1;
		for (int i = 1; i <= num; ++i){
			if (i == pow2){
				before = res[i] = 1;
				pow2 <<= 1;
			}
			else{
				res[i] = res[before] + 1;
				before++;
			}
		}
		return res;
	}

	bool increasingTriplet(vector<int>& nums) {
		bool f = false;
		int x1 = 0x7fffffff, x2 = 0x7fffffff;
		int len = nums.size();
		for (int i = 0; i < len; ++i){
			if (nums[i] <= x1)x1 = nums[i];
			else if (nums[i] <= x2&&nums[i]>x1)x2 = nums[i];

			if (nums[i] > x2){ f = true; break; }
		}
		return f;
	}

	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		unordered_map<string, map<string, int>>m;
		for (const auto &p : tickets){
			m[p.first][p.second]++;
		}
		string start = "JFK";
		vector<string>ans;
		ans.push_back(start);
		dfs322(start, ans, tickets.size() + 1, m);
		return ans;
	}
	bool dfs322(const string& cur, vector<string>&ans, const int &n, unordered_map<string, map<string, int>>&m){
		if (ans.size() == n)return true;
		for (auto ticket = m[cur].begin(); ticket != m[cur].end(); ticket++){
			if (ticket->second != 0){
				ticket->second--;
				ans.push_back(ticket->first);
				if (dfs322(ticket->first, ans, n, m))return true;
				ans.pop_back();
				ticket->second++;
			}
		}
		return false;
	}


};

struct treeNode{
	int value;
	treeNode *left;
	treeNode *right;
};
class Stanford{
public:

	//inserts a new node with the given number in 
	//the correct place in the tree.
	static treeNode* insertTreeNode(treeNode* node, int data){
		if (node == NULL)return(NewNode(data));
		else{
			if (data <= node->value)node->left = insertTreeNode(node->left, data);
			else node->right = insertTreeNode(node->right, data);

			return(node);
		}
	}

	//This problem demonstrates simple binary tree traversal. 
	//Given a binary tree, count the number of nodes in the tree. 
	static int treeSize(treeNode* node){
		if (node == NULL)return(0);
		else{
			return (treeSize(node->left) + 1 + treeSize(node->right));
		}
	}

	//Given a binary tree, compute its "maxDepth"
	//the number of nodes along the longest path 
	//from the root node down to the farthest leaf node
	static int maxDepth(treeNode *node){
		if (node == NULL){
			return(0);
		}
		else{
			int lDepth = maxDepth(node->left);
			int rDepth = maxDepth(node->right);
			if (lDepth > rDepth)return (lDepth + 1);
			else return(rDepth + 1);
		}
	}

	//Given a non-empty binary search tree (an ordered binary tree)
	// return the minimum data value found in that tree. 
	static int minValue(treeNode*node){
		treeNode *current =node;
		while (current->left != NULL){
			current = current->left;
		}
		return (current->value);
	}

	//iterate over the nodes to print them out in increasing order
	static void printTree(treeNode*node){
		if (node == NULL)return;
		printTree(node->left);
		cout << node->value << " ";
		printTree(node->right);
	}

	/*
	Given a binary tree, print its
	nodes according to the "bottom-up"
	postorder traversal.
	*/
	static void printPostorder(treeNode*node){
		if (node == NULL)return;
		printTree(node->left);
		printTree(node->right);
		cout << node->value;
	}

	static int hasPathSum(treeNode*node, int sum){
		if (node == NULL){
			return NULL;
		}
		else{
			int subSum = sum - node->value;
			return(hasPathSum(node->left, subSum) 
				|| hasPathSum(node->right, subSum));
		}
	}
	//print out all of its root-to-leaf 
	//paths, one per line.
	static void printPaths(treeNode *node){
		int path[100];
		printPathRecur(node, path, 0);
	}

	/*
	So the tree...
	4
	/ \
	2   5
	/ \
	1   3
	is changed to...
	4
	/ \
	5   2
	    / \
	   3   1
	*/
	static void mirror(treeNode*node){
		if (node == NULL)return;
		else{
			treeNode *tmp;
			mirror(node->left);
			mirror(node->right);

			//swap
			tmp = node->left;
			node->left = node->right;
			node->right = tmp;
		}
	}
	//前序遍历
	static void preorder(treeNode*node){
		if (node == NULL)return;
		else{
			cout << node->value << " ";
			preorder(node->left);
			preorder(node->right);
		}
	}
	//中序遍历
	static void inorder(treeNode* node){
		if (node == NULL)return;
		else{
			inorder(node->left);
			cout << node->value << " ";
			inorder(node->right);
		}
	}
	//后序遍历
	static void postorder(treeNode*node){
		if (node == NULL)return;
		else{
			inorder(node->left);
			inorder(node->right);
			cout << node->value << " ";
		}
	}

private:
	static void printPathRecur(treeNode*node, int path[], int pathLen){
		if (node == NULL)return;
		path[pathLen] = node->value;
		pathLen++;

		if (node->left == NULL&&node->right == NULL){
			printArray(path, pathLen);
		}
		else{
			printPathRecur(node->left, path, pathLen);
			printPathRecur(node->right, path, pathLen);
		}
	}
	static void printArray(int ints[], int len){
		for (int i = 0; i < len; ++i)
			cout << ints[i] << " ";
		cout << "\n";
	}
	/*
	Helper function that allocates a new node
	with the given data and NULL left and right
	pointers.
	*/
	static treeNode* NewNode(int data){
		treeNode* node = new treeNode;
		node->value = data;
		node->left = NULL;
		node->right = NULL;

		return node;
	}


};

void nodeInsert(int key, treeNode*leaf){
	if (key < leaf->value){
		if (leaf->left != NULL)
			nodeInsert(key, leaf->left);
		else{
			leaf->left = new treeNode;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key >= leaf->value){
		if (leaf->right != NULL)
			nodeInsert(key, leaf->right);
		else{
			leaf->right = new treeNode;
			leaf->right->value = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}

treeNode* searchNode(int key, treeNode*leaf){
	if (leaf != NULL)
	{
		if (key == leaf->value)
			return leaf;
		else if (key < leaf->value)
			return searchNode(key, leaf->left);
		else
			return searchNode(key, leaf->right);
	}
	else
		return NULL;
}

void destroyTree(treeNode*leaf){
	if (leaf != NULL){
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}
}
int num[7] = { 13, 27, 18, 6, 9,5,34 };
int main(){
	treeNode* root=new treeNode;
	root->value = num[0]; root->left = NULL; root->right = NULL;
	for (int i = 1; i < 7; ++i){
		nodeInsert(num[i], root);
	}
	Stanford::printPaths(root);
	cout << "\n";
	Stanford::insertTreeNode(root, 19);
	cout << "\n";
	Stanford::printPaths(root);
	return 0;
}