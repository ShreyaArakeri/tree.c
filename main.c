/* 
 C program to implement the insert and display operation in a BST  1. display in inorder 
 2. display in preorder 
 3. display in postorder 
*/ 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
struct tree 
{ 
 int info; 
 struct tree *left; 
 struct tree *right; 
}; 
typedef struct tree * NODE; 
NODE createnode() 
{ 
 NODE ptr=(NODE)malloc(sizeof(struct tree)); 
  
 if(ptr==NULL) 
 return NULL; 
  
 else 
 return ptr; 
} 
/* 
NODE insert_bt(int ele, NODE root) 
{ 
 NODE temp, cur, prev; 
  
 char direction[20]; 
 int i; 
 
 temp=createnode(); 
 temp->info=ele; 
 temp->left=temp->right=NULL;   
 if(root==NULL) 
 return temp; 
  
 printf("Give the direction to insert\n");  scanf("%s",direction); 
  
 prev=NULL, cur=root; 
  
 for(i=0; i<strlen(direction); i++)  { 
 //toupper(direction[i]); 
 if(cur==NULL) break; 
  
 prev=cur; 
 if(direction[i]=='L') 
 cur=cur->left; 
 else 
 cur=cur->right; 
 } 
  
 if(cur!=NULL || i!=strlen(direction))  { 
 printf("Insertion not possible\n");  free(temp); 
 return root; 
 } 
  
 if(direction[i-1]=='L') 
 prev->left=temp; 
 else 
 prev->right=temp; 
  
 return root; 
} 
*/
NODE insert_bst(NODE root, int ele) { 
 NODE temp=createnode(); 
 temp->info=ele; 
 temp->left=NULL; 
 temp->right=NULL; 
  
 if(root==NULL) 
 { 
 printf("Inserting the tree's root\n");  return temp; 
 } 
  
 NODE cur=root,prev=NULL; 
  
 while(cur!=NULL) 
 { 
 prev=cur; 
  
 if(ele < cur->info) 
 cur=cur->left; 
 else 
 cur=cur->right; 
 } 
 //attach the new node 
 if(ele < prev->info) 
 prev->left=temp; 
 else 
 prev->right=temp; 
  
 return root; 
} 
void inorder(NODE root) 
{ 
 if(root==NULL) 
 return; 
 
 inorder(root->left); 
 printf("%d->", root->info); 
 inorder(root->right); 
} 
void display(NODE root, int level) { 
 int i; 
  
 if(root==NULL) return;   
 display(root->right, level+1);   
 for(i=0; i<level;i++)  
 printf(" "); 
  
 printf("%d\n", root->info); 
 display(root->left, level+1); } 
void preorder(NODE root)
{ 
 if(root==NULL) 
 return; 
  
 printf("%d->", root->info); 
 preorder(root->left); 
 preorder(root->right); 
} 
void postorder(NODE root) { 
 if(root==NULL) 
 return; 
  
 postorder(root->left); 
 postorder(root->right); 
 printf("%d->", root->info);
 }
 void search(NODE root,int key)
 {
     if(root==NULL)
     {
         printf("no elements\n");
         return;
     }
    NODE cur=root;
     while(cur!=NULL)
     {
         if(key<cur->info)
         {
             cur=cur->left;
             if(key==cur->info)
             {
                 printf("element not found\n");
                 return;
             }
         }
         else
         {
             cur=cur->right;
             if(key==cur->info)
             {
                 printf("element not found\n");
                 return;
             }
         }
      }
             
}
        
         
int main() 
{ 
 int choice, ele,key,cur; 
  
 NODE root=NULL; 
  
             
         
     
 
 
  
 for(;;)
 { 
 printf("\t1.Insert\t2.Inorder\t3.Preorder\t4.Postorder\n");
 printf("5.Display tree\t6.search\t7.exit otherwise");  
  
 printf("Enter your choice: "); 
 scanf("%d", &choice); 
  
 switch(choice) 
 { 
 case 1: printf("Enter element to be inserted:");  scanf("%d", &ele); 
  
 root=insert_bst(root, ele); 
 break; 
  
 case 2: inorder(root); 
 break; 
  
 case 3: preorder(root); 
 break; 
  
 case 4: postorder(root); 
 break; 
  
 case 5: display(root,1); 
 break; 
 
 case 6:printf("enter an element to be searched:\n");
 scanf("%d",&key);
 search(root,key);
 break;
  
 /*case 6: min=minimum_bst(root); 
 printf("The min ele in the BST =%d\n",min);  break; 
  
 case 7: max=maximum_bst(root); 
 printf("The min ele in the BST =%d\n",max);  break; 
  
// case 8: h=height(root); 
 //printf("Level of tree=%d\nHeight of tree=%d\n",h-1,h);  break;*/ 
  
 case 7: exit(0);
 } 
 } 
 return 0; }
