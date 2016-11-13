#include<stdio.h>
#include<stdlib.h>

 /*--------------------- All sum + count format -------------------------------------
 1).
 sum node even     >>  if(root->data%2 == 0 && (root->left != NULL || root->right != NULL))
 count node even   >>  if(root->data%2 == 0 && (root->left != NULL || root->right != NULL))
 count all node    >>  if(root->left != NULL || root->right != NULL)


 2).
 sum leaf even     >>  if(root->data%2 == 0 && root->left == NULL && root->right == NULL)
 count leaf even   >>  if(root->data%2 == 0 && root->left == NULL && root->right == NULL)
 count all leaf    >>  if(root->left == NULL && root->right == NULL)

 3).
 sum all even
 count all even    >>  if(root->data%2 == 0)

 4)
 countMore         >>  if(d >= root->data) return countMore(root->right);


 ex1) sum all even format

  if(root->data%2 == 0)
  {
	printf("+%d",r->data);
    return root->data + sumall(root->left) + sumall(root->right);
  }
  return sumall(root->left) + sumall(root->right);




  ex2) count all even format

  if(root->data%2 == 0)
  {
	printf("%d ",r->data);
    return 1 + countalle(root->left) + countalle(root->right);
  }
  return countalle(root->left) + countalle(root->right);

 */
typedef struct node
{
  int data;
  struct node *left,*right;
}node;

void inOrder(node *root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}

void print(node *t,int indent)
{
	if(t!=NULL)
	{
		print(t->right,indent+1);
		for(int i=0;i<indent;i++)
		{
			printf("   ");
		}
        printf("%d\n",t->data);
		print(t->left,indent+1);
	}
}

node *getnode(int d)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = d;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void add(node **root,int d)
{
	if(*root == NULL)
	{
		*root = getnode(d);
		return;
	}

	node *temp = *root;
	if(d < temp->data) return add(&(temp->left),d);
	if(d > temp->data) return add(&(temp->right),d);
}

void mirror(node *root)
{
	if(root!=NULL)
	{
		mirror(root->left);
		mirror(root->right);

		node *temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

int sumNode(node *root)
{
	if(root!=NULL)
	{
      if(root->left == NULL && root->right == NULL)
      {
         return 0;
      }
      printf("+%d",root->data);
      return root->data + sumNode(root->left) + sumNode(root->right);
	}
	return 0;
}


int sumNodeeven(node *root)
{
	if(root!=NULL)
	{
      if(root->data%2 == 0 && (root->left != NULL || root->right != NULL))
      {
          printf("+%d",root->data);
          return root->data + sumNodeeven(root->left) + sumNodeeven(root->right);
      }
      return sumNodeeven(root->left) + sumNodeeven(root->right);
    }
	return 0;
}

int sumLeaf(node *root)
{
	if(root!=NULL)
	{
		if(root->left == NULL && root->right == NULL)
		{
          printf("+%d",root->data);
          return root->data;
		}
		return sumLeaf(root->left) + sumLeaf(root->right);
	}
	return 0;
}

int sumLeafe(node *root)
{
   if(root != NULL)
   {
     if(root->data%2==0 && root->left == NULL && root->right == NULL)
     {
       printf("+%d",root->data);
       return root->data + sumLeafe(root->left) + sumLeafe(root->right);
     }
     return sumLeafe(root->left) + sumLeafe(root->right);
   }
   return 0;
}

int sumAll(node *root)
{
	if(root != NULL)
	{
	  printf("+%d",root->data);
      return root->data + sumAll(root->left) + sumAll(root->right);
	}
    return 0;
}

int sumAlleven(node *root)
{
	if(root!=NULL)
	{
      if(root->data%2 == 0)
      {
        printf("+%d",root->data);
        return root->data + sumAlleven(root->left) + sumAlleven(root->right);
      }
      return sumAlleven(root->left) + sumAlleven(root->right);
	}
	return 0;
}

int countAll(node *root)
{
	if(root!=NULL)
	{
	  printf("%d ",root->data);
      return 1 + countAll(root->left) + countAll(root->right);
	}
	return 0;
}

int countAlleven(node *root)
{
	if(root!=NULL)
	{
       if(root->data%2 == 0)
       {
       	 printf("%d ",root->data);
         return 1 + countAlleven(root->left) + countAlleven(root->right);
       }
       return countAlleven(root->left) + countAlleven(root->right);
	}
  return 0;
}

int countAllfe(node *root)
{
	if(root!=NULL)
	{
      if(root->data%2==0 && root->right == NULL && root->left == NULL)
      {
      	printf("%d ",root->data);
        return 1 + countAllfe(root->left) + countAllfe(root->right);
      }
       return countAllfe(root->left) + countAllfe(root->right);
	}
	return 0;
}

int countAlln(node *root)
{
	if(root!=NULL)
	{
       if(root->left != NULL || root->right != NULL)
       {
          printf("%d ",root->data);
          return 1 + countAlln(root->left) + countAlln(root->right);
       }
       return countAlln(root->left) + countAlln(root->right);
	}
	return 0;
}

int countAllne(node *root)
{
	if(root!=NULL)
	{
       if(root->data%2 == 0 &&(root->left != NULL || root->right != NULL))
       {
       	 printf("%d ",root->data);
       	 return 1 + countAllne(root->right) + countAllne(root->left);
       }
       else return countAllne(root->right) + countAllne(root->left);
	}
  return 0;
}

int countLess(node *root,int d)
{
	if(root!=NULL)
	{
	  printf("%d ",root->data);
      if(d <= root->data)
      {
      	return countLess(root->left,d);
      }
      return 1 + countLess(root->left,d) + countLess(root->right,d);
	}
	return 0;
}
void main()
{
	node *t = NULL;
	add(&t,4);
	add(&t,6);
	add(&t,2);
	add(&t,7);
	add(&t,3);
	add(&t,1);
	add(&t,5);
	add(&t,8);
	add(&t,2);
	add(&t,2);
	add(&t,10);

    printf("\n\n----- inOrder -----\n");
	inOrder(t);
	printf("\n\n");
	print(t,0);

	printf("\n\n----- mirror -----\n");
	mirror(t);
    inOrder(t);
	printf("\n\n");
	print(t,0);


	printf("\n------ Sum node ----------\n");
	int sn = sumNode(t);
	printf("\nsum node = %d\n",sn);

	printf("\n------ Sum node even ----------\n");
	int sne = sumNodeeven(t);
	printf("\nsum node even = %d\n",sne);


	printf("\n------ Sum leaf ----------\n");
	int sf= sumLeaf(t);
	printf("\nsum leaf = %d\n",sf);

	printf("\n------ Sum leaf even ----------\n");
	int sfe= sumLeafe(t);
	printf("\nsum leaf even = %d\n",sfe);


	printf("\n------ Sum All ----------\n");
	int sa= sumAll(t);
	printf("\nsum All = %d\n",sa);

    printf("\n------ Sum All even----------\n");
	int sae= sumAlleven(t);
	printf("\nsum All even = %d\n",sae);

	printf("\n------ Count All----------\n");
	int ca= countAll(t);
	printf("\ncount All = %d\n",ca);

	printf("\n------ Count All even----------\n");
	int cae= countAlleven(t);
	printf("\ncount All even = %d\n",cae);


	printf("\n------ Count All leaf----------\n");
	int caf= countAllfe(t);
	printf("\ncount All leaf = %d\n",caf);


    printf("\n------ Count All leaf even ----------\n");
	int cafe= countAllfe(t);
	printf("\ncount All leaf even = %d\n",cafe);

	printf("\n------ Count All node----------\n");
	int can= countAlln(t);
	printf("\ncount All node = %d\n",can);

    printf("\n------ Count All node even----------\n");
	int cane= countAllne(t);
	printf("\ncount All node even = %d\n",cane);

	printf("\n------ Count Less 5----------\n");
	int cl= countLess(t,5);
	printf("\ncount Less 5  = %d\n",cl);
}
