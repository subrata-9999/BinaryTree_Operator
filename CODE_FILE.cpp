#include<bits/stdc++.h>
using namespace std;

template <typename t>
class binarytreenode
{
public:
	int data;
	binarytreenode* left;
	binarytreenode* right;

	binarytreenode(t data)
	{
		this->data=data;
		left = NULL;
		right = NULL;
	}

	~binarytreenode(){
		delete left;
		delete right;
	}
	
};



//to take input the BST >>>>>>>>>>>>>>>>>>>>>>>>>
binarytreenode<int>* takeinputofbinarytree(){

	int rootdata;
	cout<<"enter the root data "<<endl;
	cin>>rootdata;
	if(rootdata==-1){//for the null tree input ..........
		return NULL;
	}

	binarytreenode<int>* root=new binarytreenode<int>(rootdata); // root data initilization ..........

	queue<binarytreenode<int>*> pendingnode;//queue initilazation ..................
	pendingnode.push(root);// puch the root data that helps to run the while loop .........

	while(pendingnode.size() != 0){

		binarytreenode<int>* front=pendingnode.front();
		pendingnode.pop();

		//for left child ............ 
		cout<<"enter the left child of "<<front->data<<" : ";
		int leftchilddata;
		cin>>leftchilddata;
		if(leftchilddata != -1){
			binarytreenode<int>* child=new binarytreenode<int>(leftchilddata);//initilization of the child node ........
			front->left=child;
			pendingnode.push(child);//push the left data in the queue .......
		}
   
		//for the right child .................
		cout<<"enter the right child of "<<front->data<<" : ";
		int rightchilddata;
		cin>>rightchilddata;
		if(rightchilddata!=-1){
			binarytreenode<int>* child=new binarytreenode<int>(rightchilddata);//initilization of the child node ........
			front->right=child;
			pendingnode.push(child);// push the right data in the queue ............
		}

	}
	return root;
} 



//to print the Binary tree >>>>>>>>>>>>>>>>>>>>>>>>>
void print_tree(binarytreenode<int>* root){

	if(root==NULL){
		return;
	}
	cout<<root->data<<":";
	if(root->left != NULL)
	{
		cout<<"L"<<root->left->data<<",";
	}
	if(root->right != NULL)
	{
		cout<<"L"<<root->right->data;
	}
	cout<<endl;
	print_tree(root->left);
	print_tree(root->right);

}



//to count the node of the binary tree >>>>>>>>>>>>>>>>>>>>>>>>>
int count_the_node(binarytreenode<int>* root){
	static int numberofnode=0;
	if(root==NULL){
		return 0;
	}
	
	if(root->data!=-1){
		numberofnode++;
	}
	
	return 1+count_the_node(root->left)+count_the_node(root->right);

}



//to check the presence of an elment in the BST  >>>>>>>>>>>>>>>>>>>>>>>>>
bool ispresent_the_node(binarytreenode<int>* root, int element){
	static int counter=0;
	if(root==NULL){
		return false;
	}
	if(root->data==element){
		counter++;
	}
	ispresent_the_node(root->left, element);
	ispresent_the_node(root->right, element);
	if(counter>0){
		return true;
	}
    else{
        return false;
    }

}



//print the elmnts in a given range >>>>>>>>>>>>>>>>>>>>>>>>>
void print_element_in_a_range(binarytreenode<int> *root, int start, int end){

	if(root==NULL){
		return;
	}
	if(root->data>=start && root->data<=end){
		cout<<root->data<<" ";
	}
		print_element_in_a_range(root->left, start, end);
		print_element_in_a_range(root->right, start, end);

}



//height of a binary tree  >>>>>>>>>>>>>>>>>>>>>>>>>
int height(binarytreenode<int>* root){
	if(root==NULL){
		return 0;
	}
	return 1+ max(height(root->left), height(root->right));

}



//diameter of a binary tree  
int diameter(binarytreenode<int> *root){
	if(root==NULL){
		return 0;
	}
	int option1=1+height(root->left) + height(root->right);
	int option2=diameter(root->left);
	int option3=diameter(root->right);

	return max(option1,max(option2, option3));

}



//minimum node in a binary tree  >>>>>>>>>>>>>>>>>>>>>>>>>
int minnode(binarytreenode<int>* root){
	static int minimum=INT_MAX;
	if(root==NULL){
		return 0;
	}
	if(root->data<minimum){
		minimum=root->data;
	}
	minnode(root->left);
	minnode(root->right);

	return minimum;

}



//maximum node in a binary tree  >>>>>>>>>>>>>>>>>>>>>>>>>
int maxnode(binarytreenode<int>* root){
	static int maximum=INT_MIN;
	if(root==NULL){
		return 0;
	}
	if(root->data>maximum){
		maximum=root->data;
	}
	maxnode(root->left);
	maxnode(root->right);

	return maximum;

}



//mirror of the binary tree  >>>>>>>>>>>>>>>>>>>>>>>>>
binarytreenode<int>* mirror_tree(){

	cout<<"enter the root data : ";
	int rootdata;
	cin>>rootdata;
	if(rootdata==-1){
		return NULL;
	}
	binarytreenode<int>* root=new binarytreenode<int>(rootdata);
	queue<binarytreenode<int>*> pendingnode;
	pendingnode.push(root);
	while(pendingnode.size()!=0){

		binarytreenode<int>* front=pendingnode.front();
		pendingnode.pop();

		cout<<"enter the left child of "<<front->data<<": ";
		int leftchilddata;
		cin>>leftchilddata;
		if(leftchilddata!=-1){
			binarytreenode<int>* child=new binarytreenode<int>(leftchilddata);
			front->right=child;
			pendingnode.push(child);
		}

		cout<<"enter the right child of "<<front->data<<": ";
		int rightchilddata;
		cin>>rightchilddata;
		if(rightchilddata!=-1){
			binarytreenode<int>* child=new binarytreenode<int>(rightchilddata);
			front->left=child;
			pendingnode.push(child);
		}

	}
	return root;
}



//inorder traversal in a binary tree  >>>>>>>>>>>>>>>>>>>>>>>>>
void inorder_traversal(binarytreenode<int>* root){
	if(root==NULL){
		return;
	}
	inorder_traversal(root->left);
	cout<<root->data<<" ";
	inorder_traversal(root->right);

}



//preorder traversal in a binary tree   >>>>>>>>>>>>>>>>>>>>>>>>>
void preorder_traversal(binarytreenode<int>* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder_traversal(root->left);
	preorder_traversal(root->right);

}



//postorder traversal in a binary tree   >>>>>>>>>>>>>>>>>>>>>>>>>
void postorder_traversal(binarytreenode<int>* root){
	if(root==NULL){
		return;
	}
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	cout<<root->data<<" ";

}



//is the binary tree is balanced or not  >>>>>>>>>>>>>>>>>>>>>>>>>
bool is_balanced(binarytreenode<int> *root){
    if(root==NULL){
        return true;
    }

    if(height(root->left) - height(root->right) >1){
        return false;
    }
    else{
        return true;
    }
    is_balanced(root->left);
    is_balanced(root->right);

}





int search(int inorder[], int start, int end, int curr){

	for(int i=start; i<=end; i++){
		if(inorder[i]==curr){
			return i;
		}
	}
	return -1;

}

//build a tree from in from inorder and preorder traversal  >>>>>>>>>>>>>>>>>>>>>>>>>
binarytreenode<int> *buildtree(int preorder[], int inorder[], int start, int end){
	static int idx=0;
	
	if(start>end){
		return NULL;
	}

	int curr=preorder[idx];
	idx++;
	binarytreenode<int> *root=new binarytreenode<int>(curr);
	if(start==end){
		return root;
	}

   
	int pos=search(inorder, start, end, curr);
	root->left=buildtree(preorder, inorder, start, pos-1);
	root->right=buildtree(preorder, inorder, pos+1, end);

	return root;
}



//build a tree from inorder and postorder traversal  >>>>>>>>>>>>>>>>>>>>>>>>>
binarytreenode<int>* buildtree1(int postorder[], int inorder[], int start, int end){
	static int idx=end;
	if(start>end){
		return NULL;
	}
	int curr=postorder[idx];	
	idx--;
	binarytreenode<int> *root=new binarytreenode<int>(curr);
	if(start==end){
		return root;
	}
		int pos=search(inorder, start, end, curr);

	root->right=buildtree1(postorder, inorder, pos+1, end);
	root->left=buildtree1(postorder, inorder, start, pos-1);
	
	return root;

}




//check for BST or not >>>>>>>>>>>>>>>>>>>>>>>>>
bool isBST3(binarytreenode<int> *root, int start=INT_MIN, int end=INT_MAX){
	if(root==NULL){
		return true;
	}
	if(root->data<start || root->data>end){
		return false;
	}
	bool lefttree=isBST3(root->left, start, root->data-1);
	bool righttree=isBST3(root->right, root->data, end);

	 return lefttree && righttree;
}



//construct a BST from a sorted array >>>>>>>>>>>>>>>>>>>>>>>>>
binarytreenode<int> *const_tree(int arr[], int start, int end){
	if(start>end){
		return NULL;
	}

	int mid=(start+end)/2;
	binarytreenode<int> *root=new binarytreenode<int>(arr[mid]);
	root->left=const_tree(arr, start, mid-1);
	root->right=const_tree(arr, mid+1,end);

	return root;
}




int main(){

    int n=1;

        cout<<"____________________________________________________________________________________________________________________"<<endl;
        cout<<"|  _______________________________________________________________________________________________________________  |"<<endl;
        cout<<"|  |                                                                                                             |  |"<<endl;
        cout<<"|  |                                                                                                             |  |"<<endl;
        cout<<"|  |                                                BINARY TREE OPERATOR                                         |  |"<<endl;
        cout<<"|  |                                            ------------------------------                                   |  |"<<endl;
        cout<<"|  |                                                                                                             |  |"<<endl;
        cout<<"|  |                             Code by --> Subrata Pramanik                                                    |  |"<<endl;
        cout<<"|  |                             Author  --> Subrata Pramanik                                                    |  |"<<endl;
        cout<<"|  |                                                                                                             |  |"<<endl;
        cout<<"|  |_____________________________________________________________________________________________________________|  |"<<endl;
        cout<<"|___________________________________________________________________________________________________________________|"<<endl;
    

	while(n==1){
        cout<<"_______________________________________________________________________"<<endl;
        cout<<"|                                                                      |"<<endl;
        cout<<"|               Choose a number between 1 to 16                        |"<<endl;
        cout<<"|         -------------------------------------------                  |"<<endl;
        cout<<"|                                                                      |"<<endl;
        cout<<"| 1.  Enter 1 to count the node in the binary tree                     |"<<endl;
        cout<<"| 2.  Enter 2 to check the presence of an element in the tree          |"<<endl;
        cout<<"| 3.  Enter 3 to print the elments in a given range                    |"<<endl;
        cout<<"| 4.  Enter 4 to calculate the height of your input tree               |"<<endl;
        cout<<"| 5.  Enter 5 to calculate the diameter of your input tree             |"<<endl;
        cout<<"| 6.  Enter 6 to calculate the Minimum element of your input tree      |"<<endl;
        cout<<"| 7.  Enter 7 to calculate the Maximum element of your input tree      |"<<endl;
        cout<<"| 8.  Enter 8 to print the mirror tree of your input tree              |"<<endl;
        cout<<"| 9.  Enter 9 for inorder traversal of your input tree                 |"<<endl;
        cout<<"| 10. Enter 10 for preorder traversal of your input tree               |"<<endl;
        cout<<"| 11. Enter 11 for postorder traversal of your input tree              |"<<endl;
        cout<<"| 12. Enter 12 to check your input tree is balanced or not             |"<<endl;
        cout<<"| 13. Enter 13 to build the tree from inorder and preorder traversal   |"<<endl;
        cout<<"| 14. Enter 14 to build the tree from inorder and preorder traversal   |"<<endl;
        cout<<"| 15. Enter 15 to checking the tree is BST or not                      |"<<endl;
        cout<<"| 16. Enter 16 to construct a BST from a sorted Array                  |"<<endl;
        cout<<"|______________________________________________________________________|"<<endl;



        int op;
        cout<<endl<<"Enter a number betwen 1 to 16  :) "<<endl;;
        cin>>op;

        switch (op){

            case 1:{
                cout<<"nter your tree :------- "<<endl;
                binarytreenode<int> *root1=takeinputofbinarytree();
                cout<<"Your input tree is : "<<endl;
                print_tree(root1);
                cout<<endl;
                cout<<"Number of node in your input tree :--- "<<count_the_node(root1)<<endl;
                break;
        }


            case 2:{
                cout<<"Enter your binary tree :------- "<<endl;
                binarytreenode<int> *root2=takeinputofbinarytree();
                cout<<"Your input tree is : "<<endl;
                print_tree(root2);
                cout<<"Enter the element to check, is the element is presence or not : ";
                int ele;
                cin>>ele;
                if(ispresent_the_node(root2, ele)==true){
                    cout<<ele<<" is present in your input tree."<<endl;
                }
                else{
                    cout<<ele<<" is not present in your input tree."<<endl;
                }
                break;
        }


            case 3:{
                cout<<"Enter your binary tree :------- "<<endl;
                binarytreenode<int> *root3=takeinputofbinarytree();
                cout<<"Your input tree is : "<<endl;
                print_tree(root3);
                cout<<"Enter the starting value of your range : "<<endl;
                int start,end;
                cin>>start;
                cout<<"Enter the ending value of your range : "<<endl;
                cin>>end;
                cout<<"The elements which are in the given range :--- ";
                print_element_in_a_range(root3, start, end);
                break;
        }


            case 4:{
                cout<<"Enter your binary tree :------- "<<endl;
                binarytreenode<int> *root4=takeinputofbinarytree();
                cout<<"Your input tree is : "<<endl;
                print_tree(root4);
                cout<<"The height of the given binary tree is : "<<height(root4)<<endl;
                break;
        }


            case 5:{
                cout<<"Enter your binary tree :------- "<<endl;
                binarytreenode<int> *root5=takeinputofbinarytree();
                cout<<"Your input tree is : "<<endl;
                print_tree(root5);
                cout<<"The diameter of the given binary tree is : "<<diameter(root5)<<endl;
                break;
        }


            case 6:{
                cout<<"Enter your binary tree :------- "<<endl;
                binarytreenode<int> *root6=takeinputofbinarytree();
                cout<<"Your input tree is : "<<endl;
                print_tree(root6);
                cout<<"The minimum element of the given binary tree is : "<<minnode(root6)<<endl;
                break;
        }


            case 7:{
                cout<<"Enter your binary tree :------- "<<endl;
                binarytreenode<int> *root7=takeinputofbinarytree();
                cout<<"Your input tree is : "<<endl;
                print_tree(root7);
                cout<<"The maximum element of the given binary tree is : "<<maxnode(root7)<<endl;
                break;
        }

            
            case 8:{
                cout<<"Enter your binary tree :------- "<<endl;
                binarytreenode<int> *root8=mirror_tree();
                cout<<"The mirror tree of your input tree : "<<endl;
                print_tree(root8);
                break;
        }
                

            case 9:{
                cout<<"Enter your binary tree :------- "<<endl;
                binarytreenode<int> *root9=takeinputofbinarytree();
                cout<<"Your input tree is : "<<endl;
                print_tree(root9);
                cout<<"The inorder traversal of your input tree is : ";
                inorder_traversal(root9);
                break;
        }


            case 10:{
                cout<<"Enter your binary tree :------- "<<endl;
                binarytreenode<int> *root10=takeinputofbinarytree();
                cout<<"Your input tree is : "<<endl;
                print_tree(root10);
                cout<<"The preorder traversal of your input tree is : ";
                preorder_traversal(root10);
                break;
        }


            case 11:{
                cout<<"Enter your binary tree :------- "<<endl;
                binarytreenode<int> *root11=takeinputofbinarytree();
                cout<<"Your input tree is : "<<endl;
                print_tree(root11);
                cout<<"The postorder traversal of your input tree is : ";
                postorder_traversal(root11);
                break;
        }


            case 12:{
                cout<<"Enter your binary tree :------- "<<endl;
                binarytreenode<int> *root12=takeinputofbinarytree();
                cout<<"Your input tree is : "<<endl;
                print_tree(root12);
                cout<<endl;
                if(is_balanced(root12)==true){
                    cout<<"The tree is balanced."<<endl;
                }
                else{
                    cout<<"The tree is not balanced."<<endl;
                }
                break;
        }

            
            case 13:{
                int size;
                cout<<"Enter the size of the inorder/preorder array : ";
                cin>>size;
                int inorder[100];
                int preorder[100];
                cout<<"Enter the inorder array : "<<endl;
                for(int i=0;i<size;i++){
                    cin>>inorder[i];
                }
                cout<<"Enter the preorder array : "<<endl;
                for(int i=0;i<size;i++){
                    cin>>preorder[i];
                }
                cout<<"Your tree is : -------------- "<<endl;
                binarytreenode<int> *root13=buildtree(preorder, inorder, 0, size-1);
                print_tree(root13);
                break;
        }



            case 14:{
                int size;
                cout<<"Enter the size of the inorder/postorder array : ";
                cin>>size;
                int inorder[100];
                int postorder[100];
                cout<<"Enter the inorder array : "<<endl;
                for(int i=0;i<size;i++){
                    cin>>inorder[i];
                }
                cout<<"Enter the postorder array : "<<endl;
                for(int i=0;i<size;i++){
                    cin>>postorder[i];
                }
                cout<<"Your tree is : ---------- "<<endl;
                binarytreenode<int> *root14=buildtree1(postorder, inorder, 0, size-1);
                print_tree(root14);
                break;
        }



            case 15:{
                cout<<"Enter your binary tree :------- "<<endl;
                binarytreenode<int> *root15=takeinputofbinarytree();
                cout<<"Your input tree is : "<<endl;
                print_tree(root15);
                cout<<endl;
                if(isBST3(root15)==true){
                    cout<<"The tree is a BST."<<endl;
                }
                else{
                    cout<<"The tree is not a BST."<<endl;
                }
                break;
        }


            case 16:{
                int size;
                cout<<"Enter the size of the array ";
                cin>>size;
                int arr[100];
                for(int i=0;i<size;i++){
                    cin>>arr[i];
                }
                binarytreenode<int> *root16=const_tree(arr, 0, size-1);
                cout<<"Your tree is : "<<endl;
                print_tree(root16);
                break;
            }

            
            default:
                cout<<"___________________________________________________"<<endl;
                cout<<"|                                                  |"<<endl;
                cout<<"|--------:( You entered an Invalid Number :(--------|"<<endl;
                cout<<"|__________________________________________________|"<<endl;
                break;

        }
        int p;
        cout<<endl;
        cout<<"_____________________________________________________"<<endl;
        cout<<"|                                                   |"<<endl;
        cout<<"|  Enter 1 if you want to do this operations again  |"<<endl;
        cout<<"|--------    Else enter any key for exit    --------|"<<endl;
        cout<<"|___________________________________________________|"<<endl;
        cout<<endl;
        cin>>p;
        n=p;
    }
    cout<<endl;
    cout<<"___________________________________________"<<endl;
    cout<<"|                                          |"<<endl;
    cout<<"|  :) .....Thank You for using Me..... :)  |"<<endl;
    cout<<"|__________________________________________|"<<endl<<endl<<endl;


    return 0;
}
