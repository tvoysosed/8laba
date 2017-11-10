#include <iostream> 
#include <string> 

using namespace std; 

struct Node { 
string str; 
Node * next; 
}; 
struct List { 
Node *head; 
}; 
bool simple_print (List list, string filter) { 
Node *curr = nullptr; 
int flag = 0; 
curr = list.head; 
do { 
 if (curr->str == filter) flag = 1; 
curr = curr->next; 
} while (curr != nullptr) ; 
if (flag == 1) return true; 
else return false; 
} 
bool reg_print (List list, string filter) { 
Node *curr = nullptr; 
int flag = 1; 
int k = 0; 
curr = list.head; 
do { 
for (int i = 0; i < filter.length(); i++) 
 {if ((curr->str)[i]!= filter[i]) flag = 0; }; 
if (flag == 1) k = 1 ; 
flag=1; 
curr= curr->next; 
} while (curr != nullptr) ; 
if (k == 1) return true; 
else return false; 
} 
int main() { 
List list; 
string str; 
cin >> str; 
Node *first = new Node {str, nullptr}; 
list.head = first; 
Node *last = nullptr; 
while (true) { 
cin >> str; if (str == "end") break; 
Node *curr= new Node {str, nullptr}; 
if (list.head->next == nullptr) list.head->next = curr; 
if (last != nullptr) { 
last->next = curr;} 
last = curr; } 
Node *curr = nullptr; 
curr = list.head; 
do { 
cout << curr->str << endl; 
curr = curr->next; 
} while (curr != nullptr) ; 
string filter; 
cin >> filter; 
bool a = simple_print (list, filter); 
cout << a << endl; 
string filter2; 
cin >> filter2; 
bool b = reg_print(list, filter2); 
cout << b; 
}
