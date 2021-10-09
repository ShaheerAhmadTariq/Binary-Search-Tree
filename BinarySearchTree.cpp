#include<iostream>
#include<conio.h>
#define SPACE 10
using namespace std;

class TreeNode{
	public:
		TreeNode* left;
		TreeNode* right;
		int data;
		
		TreeNode(){
			data = 0;
			left = NULL;
			right = NULL;
		}
		
		TreeNode(int d){
			data = d;
			left = NULL;
			right = NULL;
		}
	
};

class BST{
	public:
		TreeNode* root = NULL;
		
		BST(){
			root = NULL;
		}
		
		BST(TreeNode* n){
			root = n;
		}
		
		bool isTreeEmpty(){
			if(root == NULL)
				return true;
			else
				return false;
		}
		
		void insertNode(int data){
			if(root == NULL){
				root = new TreeNode();
				root->data = data;
	
				cout<<root->data<<endl;
				cout<<"Value Inserted root node!"<<endl;
			}
			else{
				TreeNode* temp = root;
				TreeNode* ptr;
				ptr = new TreeNode();
				cout<<"in else"<<endl;
				while(temp != NULL){
					
					if(data == temp->data){
						cout<<"Value already exist"<<endl;
						return;//no dublication
					}
					else if((data < temp->data)&&(temp->left == NULL)){
						cout<<"Value Inserted to left!"<<endl;
						ptr->data = data; 
						temp->left = ptr;
						
						break;
					}
					else if(data < temp->data){
						temp = temp->left;
					}
					else if((data > temp->data)&&(temp->right == NULL)){
						cout<<"Value Inserted to right!"<<endl;
						//temp->right;
						break;
					}
					else{
						temp = temp->right;
					}
				}
			}
		}
		
		void print2D(TreeNode *r , int space){
			if(r==NULL)
				return;
			space += SPACE;
			print2D(r->right , space);
			for(int i = SPACE; i < space; i++){
				cout<<" ";
			}
			cout<<r->data<<"\n";
			print2D(r->left , space);
		}
		
	
};



int main(){
	BST obj;
	int option,val;
	TreeNode* n = new TreeNode();
	do{
		cout<<"What operation do want to perform? "<<endl;
		cout<< "1. Insert Node"<<endl;
		cout<< "2. Search Node"<<endl;
		cout<< "3. Delete Node"<<endl;
		cout<< "4. Print BST values"<<endl;
		cout<< "5. Clear Screen"<<endl;
		cout<< "0. Exit Program"<<endl;
		
		cin>> option;
		
		switch (option){
			case 0:
				break;
			case 1:
				cout<<"INSERT"<<endl;
				cout<<"Enter value of tree node to insert in BST"<<endl;
				cin>> val;
				n->data = val;
				obj.insertNode(val);
				cout<<endl;
				val = 0;
				break;
			case 4:
				cout<<"PRINT"<<endl;
				obj.print2D(obj.root,5);
				break;
			case 5:
				system("cls");
				break;
		}
		
	}while(option != 0);
}
