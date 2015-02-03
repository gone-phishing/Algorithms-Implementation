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
int tree_search(node *tree, int item)
{
	if(!tree)
	{
		//printf("NO\n");
		return 0;
	}
	else if (tree->key == item)
	{
		//printf("YES\n");
		return 1;
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
int lca(node *tree, int n1, int n2)
{
	if(!tree)
	{
		printf("Tree not found\n");
	}
	if(tree->key < n1 && tree->key < n2)
	{
		return lca(tree->right_node,n1,n2);
	}
	if(tree->key > n1 && tree->key > n2)
	{
		return lca(tree->left_node,n1,n2);
	}
	//printf("%d\n",tree->key);
	return tree->key;
}
int main(int argc, char const *argv[])
{
	/* code */
	printf("Elements in Tree: ");
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
	int n1,n2;
	printf("\nEnter elements for Lowest Common Ancesstor: ");
	scanf("%d %d",&n1,&n2);
	if((tree_search(root,n1) == 1)&&(tree_search(root,n2) == 1))
	{
		printf("LCA is %d\n",lca(root,n1,n2));
	}
	else if(tree_search(root,n1) == 0) printf("First element not found\n");
	else if(tree_search(root,n2) == 0) printf("Second element not found\n");
	return 0;
}