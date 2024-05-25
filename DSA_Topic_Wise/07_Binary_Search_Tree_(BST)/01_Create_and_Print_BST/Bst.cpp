#include <iostream>
#include <queue>
using namespace std;

class Node
{
   public:
   int data;
   Node* left;
   Node* right;
   
   Node(int data)
   {
       this->data=data;
       left=NULL;
       right=NULL;
   }
   
};


Node* InsertNode(Node* root, int data)
{
    // base case, if root even not exist of the binary tree
    if(root==NULL)
    {
        Node* newnode=new Node(data);
        return newnode;
    }
    
    if(data>root->data) 
    {
        // Insert the node in the root right
        root->right=InsertNode(root->right,data);
    }
    
    if(data<root->data)
    {
        // Insert the node in the root left
        root->left=InsertNode(root->left,data); 
    }
    
    return root;
}
Node* takeInput(Node* root)
{
    int data;
    cin>>data;
    
   
    while(data!=-1)
    {      
        root=InsertNode(root,data);
        cin>>data;
    }
    return root;
}

void  levelOrder(Node* root) {
         vector<vector<int>>ans;
        
        if(root==NULL) return ;
        queue<Node*>q;
        q.push(root);
        
      
        while(!q.empty())
        {
          
            
            int size=q.size();
            vector<int>temp(size);
            
            
                for(int i=0;i<size;i++)
                {
                    auto curr=q.front();
                    cout<<curr->data<<"=>";
                    q.pop();
                    temp[i]=(curr->data);
                    if(curr->left) 
                    {
                        q.push(curr->left);
                        cout<<"L:"<<curr->left->data<<" ";
                    }
                    if(curr->right) 
                     {
                        q.push(curr->right);
                        cout<<"R:"<<curr->right->data<<" ";
                    }

                    cout<<" , ";
                    
                }
                cout<<endl;
                
            
            
        
        }
        
   
    }

int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    //**********
    cout<<"Enter the Nodes of the BST :"<<endl;
    Node* root=NULL;
    root=takeInput(root);
    
    cout<<"Printing the BST Node Level wise:"<<endl;
    levelOrder(root);
    
    return 0;
}

/*
Enter the Nodes of the BST :
3
2
1
5
6
7
-1
Printing the BST Node Level wise:
3=>L:2 R:5  ,
2=>L:1  , 5=>R:6  ,
1=> , 6=>R:7  ,
7=> ,


*/