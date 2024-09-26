//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};


//TC O(N)  AS->O(w) width of tree
void levelOrder(Node *root){
    if(root == NULL)return;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        cout<<curr->data<<" ";
        q.pop();
        if(curr->left != NULL)q.push(curr->left);
        if(curr->right != NULL)q.push(curr->right);
        
    }   

}


void levelOrderLineByLine(Node *root){
    if(root == NULL)return;
    queue<Node*> q;
    q.push(root);

    Node *temp = new Node(-1);
    q.push(temp);

    while(q.size() > 1){
        Node* curr = q.front();
        if(curr == temp){
            cout<<endl;
            q.pop();
            q.push(temp);
            continue;
        }
        cout<<curr->data<<" ";
        q.pop();

        if(curr->left != NULL)q.push(curr->left);
        if(curr->right != NULL)q.push(curr->right);
        
    } 

}

//By using two loops

void levelOrderLineByLineLoop(Node *root){
    if(root == NULL)return;
    queue<Node*> q;
    q.push(root);

    

    while(q.size() != 0){

        ll ct = q.size();

        for(ll i = 0; i < ct; i++){
            Node* curr = q.front();
            cout<<curr->data<<" ";
            q.pop();
            if(curr->left != NULL)q.push(curr->left);
            if(curr->right != NULL)q.push(curr->right);

        }
       
        cout<<endl;
        
    } 

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);
    root->right = new Node(30);
    root->right->right = new Node(60);
    

    levelOrder(root);
    cout<<endl;
    levelOrderLineByLine(root);
    cout<<endl;
    levelOrderLineByLineLoop(root);


    return 0;
}

/*

10 
20 30 
40 50 60 
70 80 
10
20 30
40 50 60
70 80

*/