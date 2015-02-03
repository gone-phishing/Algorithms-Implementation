#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *left_node;
	struct node *right_node;
	int key;
}node;

void tree_insert(node **tree,node *item)
{
	if(!(*tree))
	{
		*tree = item;
		return;
	}
	if((*tree)->key < item->key) return tree_insert(&((*tree)->right_node),item);
	else if((*tree)->key > item->key) return tree_insert(&((*tree)->left_node),item);
}
void print_inorder(node *tree)
{
	if(tree->left_node) print_inorder(tree->left_node);
	printf("%d ",tree->key);
	if(tree->right_node) print_inorder(tree->right_node);
}
void print_preorder(node *tree)
{
	printf("%d ",tree->key);
	if(tree->left_node) print_inorder(tree->left_node);
	if(tree->right_node) print_inorder(tree->right_node);
}
void print_postorder(node *tree)
{
	if(tree->left_node) print_inorder(tree->left_node);
	if(tree->right_node) print_inorder(tree->right_node);
	printf("%d ",tree->key);
}
void printGivenLevel(node *tree, int level)
{
	if(!tree) return;
	else if(level == 1) printf("%d ",tree->key );
	else if(level >1)
	{
		printGivenLevel(tree->left_node,level-1);
		printGivenLevel(tree->right_node,level-1);
	}
}
int tree_height(node *tree)
{
	if(!tree)
		return 0;
	else
	{
		int left_height = tree_height(tree->left_node);
		int right_height = tree_height(tree->right_node);

		if(left_height > right_height) return left_height+1;
		else return right_height+1;
	}
}
void print_levelorder(node *tree)
{
	int h = tree_height(tree);
	int i;
	for(i=1;i<=h;i++)
	{
		printGivenLevel(tree,i);
	}
}
void tree_search(node *tree, int item)
{
	if(!tree)
	{
		printf("NO\n");
		return;
	}
	else if (tree->key == item)
	{
		printf("YES\n");
		return;
	}
	else if(tree->key > item)
	{
		tree_search(tree->left_node,item);
	}
	else
	{
		tree_search(tree->right_node, item);
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	printf("Array Size: ");
	int n=0;
	scanf("%d",&n);
	int nums[n];
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&nums[i]);
	}
	node *curr, *root;
	root = NULL;
	for(i=0;i<n;i++)
	{
		curr = (node *)malloc(sizeof(node));
		curr->left_node = NULL;
		curr->right_node = NULL;
		curr->key = nums[i];
		tree_insert(&root,curr);
	}
	printf("Inorder\n");
	print_inorder(root);
	printf("\nPre order\n");
	print_preorder(root);
	printf("\nPost order\n");
	print_postorder(root);
	printf("\nLevel Order\n");
	print_levelorder(root);
	printf("\nEnter element to search: ");
	int item = 0;
	scanf("%d",&item);
	tree_search(root,item);
	return 0;
}