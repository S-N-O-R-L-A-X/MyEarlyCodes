#include <bits/stdc++.h>

using namespace std;

/**
  Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode *findtail(ListNode *head,int cnt)
    {
        ListNode *p=head;
        while(--cnt)
            p=p->next;

        return p;
    }

    void reorderList(ListNode* head) {
        ListNode *p=head,*tail=head;
        int cnt=0;
        while(p)
        {
            if(cnt!=0)
                tail=tail->next;
            cnt++;
            p=p->next;
        }

        if(cnt==0||cnt==1)
            return ;
        ListNode *h=head;
        int exchange=(cnt-1)/2;
        while(exchange)
        {
            tail->next=h->next;
            h->next=tail;
            h=tail->next;
            cnt-=2;
            tail=findtail(h,cnt);
            exchange--;
        }
        tail->next=NULL;
        p=head;
        while(p)
        {
            cout<<p->val;
            p=p->next;
        }
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);

        Solution().reorderList(head);

        string out = listNodeToString(head);
        cout << out << endl;
    }
    return 0;
}
