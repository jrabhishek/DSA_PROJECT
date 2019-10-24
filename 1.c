/*
4.1. Write a menu driven program (array based) to

- insert items
- delete items
- reverse the elements using recursion
- sort the elements using recursion
- rearrange the elements by interleaving the first half of the queue with the
second half of the queue.
The program should handle erroneous condition.*/
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

int front = -1;
int rear = -1;
int size = 100;
int queue[100];



bool isEmpty()
{
	return front==-1;
}
void insert(int item)
{
	if (rear == size-1)
	{
		printf("memory full\n");
		return;
	}
	if (front ==-1 && rear == -1)
	{
		front=rear=0;
		queue[rear] = item;
		return;
	}

	queue[++rear] = item;

}

void delete()
{
	if (front==-1)
	{
		printf(" nothing to delete in memory ::::memory empty\n");
		return;
	}
	if (front==rear)
	{
		front = -1;
		rear = -1;
		return;
	}
	front += 1;
}

void reverse(int top,int back)
{
	if (isEmpty())
	{
		printf("no element in memory\n");
		return;
	}
	if(top<back)
	{
		
		//swaping last and front element 
		int temp ;
		temp=queue[top];
		queue[top] = queue[back];
		queue[back] = temp;

		reverse(top+1,back-1);

	}

	
	

}

void display()
{
	if (isEmpty())
	{
		printf("no element in memory\n");
		return;
	}
	int i;
	for ( i = front; i <= rear; ++i)
	{
		printf("%d\n",queue[i]);
	}
}


void rearrange(int top ,int back)
{
	if (isEmpty())
	{
		printf("no element in memory\n");
		return;
	}

	int mid = (back+top+1)/2;
	printf("%d    %d     %d\n",top,back,mid );
	if((back-top+1)%2 !=0) 
	{
		printf("elements cannot be rearrange by interleaving since elements in memory is odd\n");
		return;
	}
	int new[100],i=0,j;
	int flag = mid;

	while(top<mid && flag<back)
	{
		new[i++] = queue[top++];
		new[i++] = queue[flag++];
	}
	while(top<mid)
	{
		new[i++] = queue[top++];		
	}
	
	int k =0;
	i=0;
	for (j = front; j <= rear-1; ++j)
	{
		queue[j] = new[i++];
			
	}

}
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;

	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return; // base condition. If the array has less than two element, do nothing. 

	mid = n/2;  // find the mid index. 

	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array 
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
	for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray

	MergeSort(L,mid);  // sorting the left subarray
	MergeSort(R,n-mid);  // sorting the right subarray
	Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
        free(L);
        free(R);
}


int main()
{
	printf("\nenter 1 --- to insert \n2 --- to delete\n 3 --- to reverse \n 4 ----- to display\n5 to rearrange the elements by interleaving\n6 to --- sort");
	int ch;
	scanf("%d",&ch);
	while(ch!=-1)
	{
		switch(ch)
		{
			case 1:
				printf("enter elements to be inserted\n");
				int item;
				scanf("%d",&item);
				insert(item);
				break;
			case 2:
				delete();
				break;
			case 3:
				reverse(front,rear);
				break;
			case 4:
				display();
				break;
			case 5:
				rearrange(front,rear);
				break;
			case 6:
				if (isEmpty())
				{
					printf("no element in memory\n");
					exit(0);
				}
				MergeSort(queue+front,rear-front+1);
				printf("%d\n",rear-front+1);
				break;
			default:
				printf("wrong choice\n");
			
		}
		printf("\nenter 1 --- to insert \n2 --- to delete\n 3 --- to reverse \n 4 ----- to display\n 5 to rearrange the elements by interleaving\n6 to --- sort");
		//int ch;
		scanf("%d",&ch);

	}
	return 0;

}




