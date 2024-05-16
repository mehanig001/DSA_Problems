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


//TC O(N)  AS->O(h) height of tree

int height(Node *root){
    if(root == NULL)return 0;
    return 1+(max(height(root->left),height(root->right)));
}

void nodesAtKDistance(Node *root, int k, int i){

    if(root == NULL)return;
    if(i == k){
        cout<<root->data<<" ";
    }
    nodesAtKDistance(root->left,k,i+1);
    nodesAtKDistance(root->right,k,i+1);

    

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
    

    cout<<height(root)<<endl;

    nodesAtKDistance(root,0,0);
    


    return 0;
}

/*

4
10

*/