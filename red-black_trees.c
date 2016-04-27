/*
	Name		:	project2.c
	Version		:	9 - final
	Milestone	:	Red-Black Trees
	Author		:	George Karagiannis
	Date		:	5 Jan. 2016
	
	New in this version:
		->	
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0

typedef enum {
	red,
	black
} status;

typedef struct node *node_ptr;
struct node{
	int key;
	status color;
	node_ptr parent, left_child, right_child;
};

//global variables' declaration
node_ptr rbt_root, r_aux, x_aux, y_aux, z_aux, NIL;

//functions' declaration
void right_rotation();
void left_rotation();
void initialization();
void insert_fix_up();
void insert();
void find_predecessor();
void de1ete_fix_up();
void find_node(int key);
void de1ete();
void tree_print(node_ptr *nd);
void print();

int main(void){
	
	char c1='a';
	
	initialization();
	rbt_root = NIL;
	
	while ((c1 != 'q') && (c1 != 'Q')){
		printf("\n Your options are :\n (i)nsert\n (d)elete\n (p)rint\n (q)uit");
		if ((c1 != 'q') || (c1 != 'Q')){
			printf("\n Give new choice: ");
            c1='a';
            fflush(stdin);
            c1=getchar();
            getchar();
            
			if ((c1 == 'q') || (c1 == 'Q')){
            	printf("\n Quit \n");
        	}
			if ((c1 == 'i') || (c1 == 'I')){
				printf("\n INSERT \n");
                insert();
        	}
        	if ((c1 == 'd') || (c1 == 'D')){
        		printf("\n DELETE \n");
                de1ete();
        	}
            if ((c1 == 'p') || (c1 == 'P')){
				printf("\n PRINT \n");
                print();
            }
        }
    }
	
	return 0;
}



void initialization(){
	
	NIL = (node_ptr)malloc(sizeof(struct node));
	NIL->key = (int)INFINITY;//0;
	NIL->color = black;
	NIL->parent = NULL;
	NIL->left_child = NULL;
	NIL->right_child = NULL;
}


void right_rotation(){
	
	// finding child participating in rotation 
	z_aux = r_aux->left_child;
	
	// converting z_aux's right sub-tree in r_aux's left sub-tree
	r_aux->left_child = z_aux->right_child;
	if (z_aux->right_child != NIL){
		z_aux->right_child->parent = r_aux;
	}
	
	// connecting r_aux's parent with z_aux
	z_aux->parent = r_aux->parent;
	if (r_aux->parent == NIL){
		rbt_root = z_aux;
	}
	else{
		if (r_aux == r_aux->parent->right_child){
			r_aux->parent->right_child = z_aux;
		}
		else{
			r_aux->parent->left_child = z_aux;
		}
	}
	
	// setting r_aux as z_aux's right child 
	z_aux->right_child = r_aux;
	r_aux->parent = z_aux;
}


void left_rotation(){
	
	// finding child participating in rotation 
	z_aux = r_aux->right_child;
	
	// converting z_aux's left sub-tree in r_aux's right sub-tree
	r_aux->right_child = z_aux->left_child;
	if (z_aux->left_child != NIL){
		z_aux->left_child->parent = r_aux;
	}
	
	// connecting r_aux's parent with z_aux
	z_aux->parent = r_aux->parent;
	if (r_aux->parent == NIL){
		rbt_root = z_aux;
	}
	else{
		if (r_aux == r_aux->parent->left_child){
			r_aux->parent->left_child = z_aux;
		}
		else{
			r_aux->parent->right_child = z_aux;
		}
	}

	// setting r_aux as z_aux's right child
	z_aux->left_child = r_aux;
	r_aux->parent = z_aux;
}


void insert_fix_up(){
	
	// compliance of 4th property
	while (x_aux->parent->color == red){
		printf("\n Node and parent are both red. ");
		if (x_aux->parent == x_aux->parent->parent->left_child){
			y_aux = x_aux->parent->parent->right_child;
			if (y_aux->color == red){
				printf("Uncle of node is red -- push blackness down from grandparent");
				x_aux->parent->color = black;					// case 1
				y_aux->color = black;							// case 1
				x_aux->parent->parent->color = red;				// case 1
				x_aux = x_aux->parent->parent;					// case 1
			}
			else{
				
				if (x_aux == x_aux->parent->right_child){
					printf("Node is right child, parent is left child -- rotate");
					x_aux = x_aux->parent;						// case 2
					r_aux = x_aux;								// case 2
					printf("\n Single rotate left");			// case 2
					left_rotation();							// case 2
					printf("\n Node and parent are both red. ");
				}
				printf("Node is left child, parent is left child\n Can fix extra redness with a single rotation");
				x_aux->parent->color = black;					// case 3
				x_aux->parent->parent->color = red;				// case 3
				r_aux = x_aux->parent->parent;					// case 3
				printf("\n Single rotate right");				// case 3
				right_rotation();								// case 3
			}
		}
		else if (x_aux->parent == x_aux->parent->parent->right_child){
			y_aux = x_aux->parent->parent->left_child;
			if (y_aux->color == red){
				printf("Uncle of node is red -- push blackness down from grandparent");
				x_aux->parent->color = black;					// case 1
				y_aux->color = black;							// case 1
				x_aux->parent->parent->color = red;				// case 1
				x_aux = x_aux->parent->parent;					// case 1
			}
			else{
				
				if (x_aux == x_aux->parent->left_child){
					printf("Node is left child, parent is right child -- rotate");
					x_aux = x_aux->parent;						// case 2
					r_aux = x_aux;								// case 2
					printf("\n Single rotate right");			// case 2
					right_rotation();							// case 2
					printf("\n Node and parent are both red. ");
				}
				printf("Node is right child, parent is right child\n Can fix extra redness with a single rotation");
				x_aux->parent->color = black;					// case 3
				x_aux->parent->parent->color = red;				// case 3
				r_aux = x_aux->parent->parent;					// case 3
				printf("\n Single rotate left");				// case 3
				left_rotation();								// case 3
			}
		}
	}
	// compliance of 2nd property
	if (rbt_root->color == red)
		printf("\n Root of the tree is red. Color it black");
	rbt_root->color = black;
	printf("\n");
}


void insert(){
	
	int key;
	node_ptr aux = NIL, f_aux = rbt_root;
	/*
		f_aux	:	f(orward)_aux pointing one of aux's childs 
	*/
	
	printf("\n Give new node's key\t:\t");
	scanf("%d", &key);
	getchar();
	
	// construction of new struct node
	x_aux = (node_ptr)malloc(sizeof(struct node));
	x_aux->key = key;
	x_aux->color = red;		// new node is colored red
	x_aux->parent = NIL;
	x_aux->left_child = NIL;	// new node's left_child points NIL
	x_aux->right_child = NIL;	// new node's right_child points NIL
	
	// searching new node's position in red - black tree
	printf("\n Inserting %d", x_aux->key);
	while (f_aux != NIL){
		aux = f_aux;
		if (x_aux->key < f_aux->key){
			printf("\n %d < %d. Looking at left subtree", x_aux->key, f_aux->key);
			f_aux = f_aux->left_child;
		}
		else{// if (x_aux->key >= f_aux->key){
			printf("\n %d >= %d. Looking at right subtree", x_aux->key, f_aux->key);
			f_aux = f_aux->right_child;
		}
	}
	printf("\n Found null tree (or guard NIL), inserting element");
	
	// fixing pointers between new node and its parent
	x_aux->parent = aux;
	if (aux == NIL){
		rbt_root = x_aux;
	}
	else{
		if (x_aux->key < aux->key){
			aux->left_child = x_aux;
		}
		else{// if (x_aux->key >= aux->key){
			aux->right_child = x_aux;
		}
	}
	
	// call insert_fix_up to restore red - black tree's properties
	insert_fix_up();
}


void find_predecessor(){
	//searches for predecessor
	node_ptr aux = z_aux;
	
	if (aux->left_child != NIL){
		y_aux = aux->left_child;
		while(y_aux->right_child != NIL){
			y_aux = y_aux->right_child;
		}
	}
	else{
		y_aux = aux->parent;
		while ((y_aux != NIL) && (aux = y_aux->left_child)){
			aux = y_aux;
			y_aux = y_aux->parent;
		}
	}
}


void de1ete_fix_up(){
	
	while ((x_aux != rbt_root) && (x_aux->color == black)){
		if (x_aux == x_aux->parent->left_child){
			z_aux = x_aux->parent->right_child;
			if (z_aux->color == red){
				printf("\n Double black node has black sibling. Rotate tree to make sibling black...");
				z_aux->color = black;						// case 1
				x_aux->parent->color = red;					// case 1
				r_aux = x_aux->parent;						// case 1
				printf("\n Single rotate left");
				left_rotation();							// case 1
				z_aux = x_aux->parent->right_child;			// case 1
			}
			if ((z_aux->left_child->color == black) && (z_aux->right_child->color == black)){
				printf("\n Double black node has black sibling and 2 black nephews. Push up black level");
				z_aux->color = red;							// case 2
				x_aux = x_aux->parent;						// case 2
			}
			else{
				
				if (z_aux->right_child->color == black){
					printf("\n Double black node has black siblings, but double black node is a left child,");
					printf("\n and the right nephew is black. Rotate tree to make opposite nephew red...");
					z_aux->left_child->color = black;		// case 3
					z_aux->color = red;						// case 3
					r_aux = z_aux;							// case 3
					printf("\n Single rotate right");
					right_rotation();						// case 3
					z_aux = x_aux->parent->right_child;		// case 3
				}
				printf("\n Double black node has black sibling, is a left child, and its right nephew is red");
				printf("\n One rotation can fix double blackness.");
				z_aux->color = x_aux->parent->color;		// case 4
				x_aux->parent->color = black;				// case 4
				z_aux->right_child->color = black;			// case 4
				r_aux = x_aux->parent;						// case 4
				printf("\n Single rotate left");
				left_rotation();							// case 4
				x_aux = rbt_root;							// case 4
			}
		}
		else{// if (x_aux == x_aux->parent->right_child){
			z_aux = x_aux->parent->left_child;
			if (z_aux->color == red){
				printf("\n Double black node has black sibling. Rotate tree to make sibling black...");
				z_aux->color = black;						// case 1
				x_aux->parent->color = red;					// case 1
				r_aux = x_aux->parent;						// case 1
				printf("\n Single rotate right");
				right_rotation();							// case 1
				z_aux = x_aux->parent->left_child;			// case 1
			}
			if ((z_aux->left_child->color == black) && (z_aux->right_child->color == black)){
				printf("\n Double black node has black sibling and 2 black nephews. Push up black level");
				z_aux->color = red;							// case 2
				x_aux = x_aux->parent;						// case 2
			}
			else{
				
				if (z_aux->left_child->color == black){
					printf("\n Double black node has black siblings, but double black node is a right child,");
					printf("\n and the left nephew is black. Rotate tree to make opposite nephew red...");
					z_aux->right_child->color = black;		// case 3
					z_aux->color = red;						// case 3
					r_aux = z_aux;							// case 3
					printf("\n Single rotate left");
					left_rotation();						// case 3
					z_aux = x_aux->parent->left_child;		// case 3
				}
				printf("\n Double black node has black sibling, is a right child, and its left nephew is red");
				printf("\n One rotation can fix double blackness.");
				z_aux->color = x_aux->parent->color;		// case 4
				x_aux->parent->color = black;				// case 4
				z_aux->left_child->color = black;			// case 4
				r_aux = x_aux->parent;						// case 4
				printf("\n Single rotate right");
				right_rotation();							// case 4
				x_aux = rbt_root;							// case 4
			}
		}
	}
	x_aux->color = black;
	printf("\n");
}


void find_node(int key){
	
	z_aux = rbt_root;
	
	while ((z_aux != NIL) && (z_aux->key != key)){
		
		if (key < z_aux->key){
			printf("\n %d < %d. Looking at left subtree", key, z_aux->key);
			z_aux = z_aux->left_child;
		}
		else{
			printf("\n %d > %d. Looking at left subtree", key, z_aux->key);
			z_aux = z_aux->right_child;
		}
	}
}


void de1ete(){
	
	int key;
	status y_original_color;
	
	printf("\n Give me the the node's key\t:\t");
	scanf("%d", &key);
    getchar();
    
	// search node to delete
    printf("\n Deleting %d", key);
    find_node(key);
    if (z_aux == NIL)
		printf("\n Node with key = %d not found", key);
	else
		printf("\n %d = %d. Found node to delete", key, z_aux->key);
	
	// search descendant to replace deleted node
	if ((z_aux->left_child == NIL) || (z_aux->right_child == NIL)){
		y_aux = z_aux;
	}
	else{
		printf("\n Node to delete has two children.\n Find largest node in left subtree.");
		find_predecessor();
	}
	
	// fix pointers of deleted node's immediate relatives and descendant
	if (y_aux->left_child != NIL){
		x_aux = y_aux->left_child;
	}
	else{
		x_aux = y_aux->right_child;
	}
	
	x_aux->parent = y_aux->parent;
	
	if (y_aux->parent == NIL){
		rbt_root = x_aux;
	}
	else{
		if (y_aux == y_aux->parent->left_child){
			printf("\n Set parent of deleted node to left child of deleted node");
			y_aux->parent->left_child = x_aux;
		}
		else{
			if ((y_aux->left_child == NIL)&&(y_aux == z_aux))
				printf("is a leaf. Delete it");
			else if (y_aux == z_aux)
				printf("has no left child.\n Set parent of deleted node to right child of deleted node");
			y_aux->parent->right_child = x_aux;
		}
	}
	
	// copy descendant properties to deleted node's position
	if (y_aux != z_aux){
		printf("\n Copy largest value of left subtree into node to delete");
		z_aux->key = y_aux->key;
	}
	
	// delete proper node
	y_original_color = y_aux->color;
	printf("\n Remove node");
	free(y_aux);
	
	// call de1ete_fix_up to restore red - black tree's properties, if needed
	if (y_original_color == black){
		de1ete_fix_up();
	}
	
}


void tree_print(node_ptr *nd){
	
	node_ptr aux = (*nd);
	
	if (aux != NIL){
		if (aux->left_child != NIL){
			tree_print(&(aux->left_child));
		}
		
		printf("%d\t", aux->key);
		
		if (aux->color == red)
			printf("red\t");
		else if (aux->color == black)
			printf("black\t");
		
		if (aux->parent == NIL)
			printf("NIL\t");
		else
			printf("%d\t", aux->parent->key);
		
		if (aux->left_child == NIL)
			printf("NIL\t");
		else
			printf("%d\t", aux->left_child->key);
		
		if (aux->right_child == NIL)
			printf("    NIL\t");
		else
			printf("    %d\t", aux->right_child->key);
		
		if (aux->parent == NIL)
			printf("\t<--(root)\n ", aux->key);
		else
			printf("\n ");
		
		if (aux->right_child != NIL){
			tree_print(&(aux->right_child));
		}
	}
}

 
void print(){
	
	printf("\n KEY\tCOLOR\tPARENT\tLEFT_CHILD  RIGHT_CHILD\n");
	printf("------------------------------------------------\n ");
	tree_print(&rbt_root);
}
 
 
 
 
 
 
