#include <cstdio>
#include <cassert>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <list>

int nums[100000];

int binarySearch(std::vector<int> const& list, int num) {
	int l = 0, r = list.size(), lower = list.size(), upper = -1;
	while (r > l) {
		int mid = (l + r) >> 1;
		if (list[mid] <= num) {
			lower = std::min(lower, mid);
			upper = std::max(upper, mid);
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return upper;
}

class Node {
public:
	int lower;
	int upper;
	Node* left;
	Node* right;
	std::vector<int> list;
	std::vector<int> prefixes;
};

class SegmentTree {
private:
	Node* root;
public:
	SegmentTree(int n) {
		root = buildTree(0, n);
	}

	Node* buildTree(int l, int r) {
		Node* node = new Node();
		node->lower = l;
		node->upper = r;
		for (int i = l; i < r; ++i) {
			node->list.push_back(nums[i]);
		}
		std::sort(node->list.begin(), node->list.end());
		int prefix = 0;
		for (unsigned int i = 0; i < node->list.size(); ++i) {
			prefix += node->list[i];
			node->prefixes.push_back(prefix);
		}
		if (l + 1 < r) {
			node->left = buildTree(l, (l + r) >> 1);
			node->right = buildTree((l + r) >> 1, r);
		} else {
			node->left = NULL;
			node->right = NULL;
		}
		return node;
	}

	int searchTree(int l, int r, int n, Node* node) {
		int mid = (node->lower + node->upper) >> 1;
		if (l == node->lower && r == node->upper) {
			int index = binarySearch(node->list, n);
			return index == -1 ? 0 : node->prefixes[index];
		} else if (r <= mid) {
			return searchTree(l, r, n, node->left);
		} else if (l >= mid) {
			return searchTree(l, r, n, node->right);
		} else {
			return searchTree(l, mid, n, node->left) + searchTree(mid, r, n, node->right);
		}
	}

	int findSum(int l, int r) {
		int sum = 0;
		while (true) {
			int newSum = searchTree(l, r, sum + 1, root);
			if (newSum == sum) {
				return sum + 1;
			} else {
				sum = newSum;
			}
		}
		assert(false);
		return -1;
	}
};

int main() {
	int length;
	scanf("%i", &length);
	for (int i = 0; i < length; ++i) {
		scanf("%i", &nums[i]);
	}
	SegmentTree tree(length);
	int cases;
	scanf("%i", &cases);
	while (cases--) {
		int l, r;
		scanf("%i %i", &l, &r);
		printf("%i\n", tree.findSum(l - 1, r));
	}
	return 0;
}
