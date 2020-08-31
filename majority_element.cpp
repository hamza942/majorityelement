#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	int number;
	int iter = 0;
	node* next;
};
vector<node*>head;
void append(int val, int index) {
	node* newnode = new node;
	newnode->number = val;
	newnode->iter = 1;
	newnode->next = nullptr;
	if (head[index] == nullptr) {
		head[index] = newnode;
	}
	else {
			node* temp = head[index];
			bool r = false;
			while (temp!= nullptr) {
				if (temp->number == val) {
					temp->iter++;
					r = true;
					break;
				}
				else {
					temp = temp->next;
				}
			}
			if (!r) {
				temp = newnode;
			}

	}

}

int majority_element(vector<int>& ar) {
	
	for (int t = 0; t < ar.size(); t++) {
		int hash_key = ar[t] % ar.size();
		append(ar[t], hash_key);
	}
	int max = 0;
	for (int k = 0; k < ar.size(); k++) {
		if (head[k] == nullptr) {
		}
		else {
			node* temp = head[k];
			while (temp != nullptr) {
				if (temp->iter > max) {
					max = temp->iter;
				}
				temp = temp->next;

			}
		}
	}
	if (max > ar.size() / 2) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	int n;
	cin >> n;
	vector<int>ar(n);
	for (int x = 0; x < n; x++) {
		cin >> ar[x];
		head.push_back(nullptr);
	}
	cout << majority_element(ar) << endl;
}