#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
	int val;
	struct node *left;
	struct node *right;
}*root;

class Binary_Search_Tree
{
	public:
		void find(int, node **, node **);
	    void insert(node *, node *);
		void del(int);
		void case_a(node *, node *);
		void case_b(node *, node *);
		void case_c(node *, node *);
		void preorder(node *);
		void inorder(node *);
		void postorder(node *);
		void display(node *, int);
	
		Binary_Search_Tree()
		{
			root = NULL;
		}
};

int main()
{
	Binary_Search_Tree bst;
	node *temp;
	int choice, num;
	
	while(1)
	{
	
		cout << "1. Insert Element"<< endl;
		cout << "2. Delete Element" << endl;
		cout << "3. Inorder" << endl;
		cout << "4. Preorder" << endl;
		cout << "5. Postorder" << endl;
		cout << "6. Display" << endl;
		cout << "7. Quit" << endl;
		cout << "------------------------" << endl;
		cout << "Enter : " << endl;
		
		cin >> choice;
		
		cout << choice << endl << endl;
		
		switch(choice)
		{
			case 1:
				
				temp = new node;
				cout << "Number to be inserted: "<< endl;
				cin >> temp->val;
				bst.insert(root, temp);
				
				break;
				
			case 2:
				
				if(root == NULL)
				{
					cout << "The tree is empty. Nothing to be deleted" << endl;
					continue;
				}
				cout << "Enter the number to be deleted: " << endl;
				cin >> num;
				bst.del(num);
				break;
			
			case 3:
			
				cout << "Inorder traversal: " << endl;
				bst.inorder(root);
				cout << endl;
				break;
				
			case 4:
			
				cout << "Preorder traversal: " << endl;
				bst.preorder(root);
				cout << endl;
				break;
				
			case 5:
			
				cout << "Postorder traversal: " << endl;
				bst.postorder(root);
				cout << endl;
				break;
				
				
			case 6:
			
				bst.display(root, 1);
				cout << endl;
				break;
				
			case 7:
				
				exit(1);
	
			
			default:
			
				cout << "Wrong choice" << endl;
			}
		}
	}
	
// Find element in the tree

void Binary_Search_Tree::find(int item, node **parent, node **loc)
{
	node *ptr, *ptrsave;
	if(root == NULL)
	{
		*loc = NULL;
		*parent = NULL;
		return;
	}
	
	if(item == root->val)
	{
		*loc = root;
		*parent = NULL;
		return;
	}
	
	if(item<root->val)
	{
		ptr = root->left;
	}
	else
	{
		ptr = root->right;
	}
	
	ptrsave = root;
	
	while(ptr!=NULL)
	{
		if(item == ptr->val)
		{
			*loc = ptr;
			*parent = ptrsave;
			return;
		}
		ptrsave = ptr;
		
		if(item<ptr->val)
		{
			ptr = ptr->left;
		}
		else
		{
			ptr = ptr->right;
		}
	}
		*loc = NULL;
		*parent = ptrsave;
}
	
	
	
	
// Insert element
	
void Binary_Search_Tree::insert(node *tree, node *newnode)
{
	if(root == NULL)
	{
		root = new node;
		root->val = newnode->val;
		root->left = NULL;
		root->right = NULL;
		cout << "Node is added" << endl;
		return;
	}
	
	if(tree->val == newnode->val)
	{
		cout << "Element already in the tree" << endl;
		return;
	}
	
	if(tree->val > newnode->val)
	{
		if(tree->left !=NULL)
		{
			insert(tree->left, newnode);
		}
		else
		{
			tree->left = newnode;
			(tree->left)->left = NULL;
			(tree->left)->right = NULL;
			cout << "Node added to the left" << endl;
			return;
		}
	}
	else
	{
		if(tree->right !=NULL)
		{
			insert(tree->right, newnode);
		}
		else
		{
			tree->right = newnode;
			(tree->right)->left = NULL;
			(tree->right)->right = NULL;
			cout << "Node added to the right" << endl;
			return;
		}
		
	}
}

// Deleting an element

void Binary_Search_Tree::del(int item)
{
	node *parent, *location;
	if(root == NULL)
	{
		cout << "The tree is empty" << endl;
		return;
	}
	
	find(item, &parent, &location);
	
	if(location == NULL)
	{
		cout << "The item is not present in the tree" << endl;
		return;
	}
	
	if(location->left == NULL && location->right == NULL)
	{
		case_a(parent, location);
	}
	if(location->left != NULL && location->right == NULL)
	{
		case_b(parent, location);
	}
	if(location->left == NULL && location->right !=NULL)
	{
		case_b(parent, location);
	}
	if(location->left !=NULL && location->right !=NULL)
	{
		case_c(parent, location);
	}
	free(location);
}

// Case A

void Binary_Search_Tree::case_a(node *par, node *loc)
{
	if(par == NULL)
	{
		root = NULL;
	}
	else
	{
		if(loc == par->left)
		{
			par->left = NULL;
		}
		else
		{
			par->right = NULL;
		}
	}
}

// Case B

void Binary_Search_Tree::case_b(node *par, node *loc)
{
	node *child;
	
	if(loc->left !=NULL)
	{
		child = loc->left;
	}
	else
	{
		child = loc->right;
	}
	
	if(par == NULL)
	{
		root = child;
	}
	
	else
	{
		if(loc == par->left)
		{
			par->left = child;
		}
		else
		{
			par->right = child;
		}
	}
}

// Case C

void Binary_Search_Tree::case_c(node *par, node *loc)
{
	node *ptr, *ptrsave, *suc, *parsuc;
	ptrsave = loc;
	ptr = loc->right;
	while(ptr->left !=NULL)
	{
		ptrsave = ptr;
		ptr = ptr->left;
	}
	
	suc = ptr;
	parsuc = ptrsave;
	
	if(suc->left == NULL && suc->right == NULL)
	{
		case_a(parsuc, suc);
	}
	else
	{
		case_b(parsuc, suc);
	}
	
	if(par == NULL)
	{
		root = suc;
	}
	
	else
	{
		if(loc == par->left)
		{
			par->left = suc;
		}
		else
		{
			par->right = suc;
		}
	}
	
	suc->left = loc->left;
	suc->right = loc->right;
}

// Pre Order Traversal

void Binary_Search_Tree::preorder(node *ptr)
{
	if(root == NULL)
	{
		cout << "The tree is empty" << endl;
		return;
	}
	
	if(ptr !=NULL)
	{
		cout << ptr->val<< " ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

// In Order Traversal
	
void Binary_Search_Tree::inorder(node *ptr)
{
	if(root == NULL)
	{
		cout << "The tree is empty" << endl;
		return;
	}
	
	if(ptr !=NULL)
	{
		inorder(ptr->left);
		cout << ptr->val<< " ";
		inorder(ptr->right);
	}
}

// Post Order Traversal

void Binary_Search_Tree::postorder(node *ptr)
{
	if(root == NULL)
	{
		cout << "The tree is empty" << endl;
		return;
	}
	
	if(ptr !=NULL)
	{
		
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->val<< " ";
	}
}







// Display the tree

void Binary_Search_Tree::display(node *ptr, int level)
{
	int i;
	if(ptr!=NULL)
	{
		display(ptr->right, level+1);
		cout << endl;
		if(ptr == root)
		{
			cout << "Root-> ";
		}
		else
		{
			for(i=0;i<level;i++)
			{
				cout << "     ";
			}
			
		}
		cout << ptr->val;
		display(ptr->left, level+1);
	}
}	

			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	




