#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	作者：王正奕
	时间：2018年5月26日
	联系方式：wzypaopao@outlook.com 
	功能：输入矩阵，得出该矩阵的传递闭包矩阵 
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
	创建一个size*size的方阵，初始化为-1 
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
	打印矩阵 
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
	获取矩阵的一行 
*/
int* getRow(int **matrix, int size, int aim){
	int * row = (int *)malloc(sizeof(int) * size);
	for(int i = 0; i < size; i++){
		row[i] = matrix[aim][i];
	}
	return row;
}

/*
	获取矩阵的一列 
*/
int* getCol(int **matrix, int size, int aim){
	int * col = (int *)malloc(sizeof(int) * size);
	for(int i = 0; i < size; i++){
		col[i] = matrix[i][aim];
	}
	return col;
}

/*
	矩阵的特殊乘法 
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
		printf("请输入矩阵大小（如3*3，则输入3），按回车确认：");
		int size;
		scanf("%d", &size);
		while(size <= 0){
			printf("输入错误，请重新输入矩阵大小：\n");
			scanf("%d", &size);
		}
		printf("\n请按行输入矩阵，以空格分隔，回车结束\n");
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
		printf("\n原始矩阵：\n");
		printMatrix(testMatrix, size);
	
		int** matrix = mulMatrix(testMatrix, testMatrix, size);
		for(int i = 0; i < size-1; i ++){
			matrix = mulMatrix(matrix, testMatrix, size);
		}
		
		printf("\n计算后矩阵：\n");
		printMatrix(testMatrix, size);
		
		printf("\n\n是否继续使用（y/n）\n");
		getchar();
		flag = getchar(); 
		if(flag != 'y' || flag != 'Y'){
			system("cls");
			printf("\n\n\n\n\n\t\t\t\t**********************\n");
			printf("\t\t\t\t*   谢谢使用(^_^)~~  *\n");
			printf("\t\t\t\t**********************\n");
			delay(3); 
			
		} 
	}
	
	return 0;
}