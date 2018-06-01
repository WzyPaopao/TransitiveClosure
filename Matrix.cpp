#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	���ߣ�������
	ʱ�䣺2018��5��26��
	��ϵ��ʽ��wzypaopao@outlook.com 
	���ܣ�������󣬵ó��þ���Ĵ��ݱհ����� 
*/

int max(int a, int b){
	return a>b?a:b;
}

int min(int a, int b){
	return a<b?a:b;
}

int maxArray(int *a, int size){
	int temp;
	for(int i = 0; i < size-1; i ++){
		if( a[i] >= a[i+1] ){
			temp = a[i];
			a[i] = a[i+1];
			a[i+1] = temp;
		}
	}
	
	return a[size-1];
}

int getItem(int *a, int *b, int size){
	int *temp = (int *)malloc(sizeof(int) * size);
	for(int i = 0; i < size; i ++){
		temp[i] = min(a[i], b[i]);
	}
	
	return maxArray(temp, size);
}

/*
	����һ��size*size�ķ��󣬳�ʼ��Ϊ-1 
*/
int** createMatrix(int size){
	int** matrix = (int **)malloc(sizeof(int) * size);
	for(int i = 0; i < size; i ++){
		matrix[i] = (int *)malloc(sizeof(int) * size);
	}
	
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j ++){
			matrix[i][j] = -1;
		}
	}
	
	return matrix;
}

/*
	��ӡ���� 
*/
void printMatrix(int ** matrix, int size){
	for(int i = 0; i < size; i ++){
		for(int j = 0; j < size; j ++){
			printf("%d ", matrix[i][j]);
			if(j == size-1) printf("\n");
		}
	}
}

/*
	��ȡ�����һ�� 
*/
int* getRow(int **matrix, int size, int aim){
	int * row = (int *)malloc(sizeof(int) * size);
	for(int i = 0; i < size; i++){
		row[i] = matrix[aim][i];
	}
	return row;
}

/*
	��ȡ�����һ�� 
*/
int* getCol(int **matrix, int size, int aim){
	int * col = (int *)malloc(sizeof(int) * size);
	for(int i = 0; i < size; i++){
		col[i] = matrix[i][aim];
	}
	return col;
}

/*
	���������˷� 
*/
int** mulMatrix(int** AM, int** BM, int size){
	int **result = createMatrix(size);
	for(int i = 0; i < size; i ++){
		for(int j = 0; j < size; j ++){
			int* a = getRow(AM, size, i);
			int* b = getCol(BM, size, j);
			for(int k =0; k < size; k ++){
				result[i][j] = getItem(a, b, size);
			}
			
		}
	}
	
	return result;
}

void inputMatrix(int ** matrix, int size){
	for(int i = 0; i < size; i ++){
		for(int j = 0; j < size; j ++){
			scanf("%d", &matrix[i][j]);
		}
	}
}

void delay(int seconds){  
	clock_t start = clock();  
	clock_t lay = (clock_t)seconds * CLOCKS_PER_SEC;  
	while ((clock()-start) < lay)  
		;  
	}  

int main(){
	char flag = 'y';
	while( flag == 'y' || flag == 'Y' ){
		system("cls");
		printf("����������С����3*3��������3�������س�ȷ�ϣ�");
		int size;
		scanf("%d", &size);
		while(size <= 0){
			printf("���������������������С��\n");
			scanf("%d", &size);
		}
		printf("\n�밴����������Կո�ָ����س�����\n");
		int** testMatrix = createMatrix(size);
		inputMatrix(testMatrix, size);
		//printMatrix(testMatrix, 3);
		/*
		testMatrix[0][0] = 1;
		testMatrix[0][1] = 0;
		testMatrix[0][2] = 0;
		testMatrix[1][0] = 0;
		testMatrix[1][1] = 0;
		testMatrix[1][2] = 1;
		testMatrix[2][0] = 0;
		testMatrix[2][1] = 0;
		testMatrix[2][2] = 0;
		*/
		printf("\nԭʼ����\n");
		printMatrix(testMatrix, size);
	
		int** matrix = mulMatrix(testMatrix, testMatrix, size);
		for(int i = 0; i < size-1; i ++){
			matrix = mulMatrix(matrix, testMatrix, size);
		}
		
		printf("\n��������\n");
		printMatrix(testMatrix, size);
		
		printf("\n\n�Ƿ����ʹ�ã�y/n��\n");
		getchar();
		flag = getchar(); 
		if(flag != 'y' || flag != 'Y'){
			system("cls");
			printf("\n\n\n\n\n\t\t\t\t**********************\n");
			printf("\t\t\t\t*   ллʹ��(^_^)~~  *\n");
			printf("\t\t\t\t**********************\n");
			delay(3); 
			
		} 
	}
	
	return 0;
}