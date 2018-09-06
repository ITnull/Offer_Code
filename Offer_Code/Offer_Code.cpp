// Offer_Code.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*	一、FindOfArrayInt(int target, vector<vector<int> > array):
	在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
	每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一
	个整数，判断数组中是否含有该整数。
*/
bool FindOfArrayInt(int target, vector<vector<int> > array){
	/*思想：二分查找
		把每一行看成有序递增的数组，
		利用二分查找，
		通过遍历每一行得到答案，
		时间复杂度是nlogn
	*/
	int row = array.size();
	int col = array[0].size();

	for (int i = 0; i < row;i++){
		//二分查找处理

	}
	return true;
}

bool FindOfArrayInt2(int target, vector<vector<int> > array){
	/*思想：
		矩阵是有序的，从左下角来看，向上数字递减，向右数字递增，
		因此从左下角开始查找，当要查找数字比左下角数字大时。右
		移要查找数字比左下角数字小时，上移
	*/
	
	int row = array.size();
	int col = array[0].size();
	
	//将i,j变量作为数组的下标
	for (int i = row - 1, j = 0; i >= 0 && j < col;){
		if (target==array[i][j]){
			return true;
		}

		if (target<array[i][j]){
			i--;
			continue;
		}
		if (target > array[i][j]){
			j++;
			continue;
		}
	}
	return false;
}

/*二、jumpFloor(int number):
	一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少
	种跳法（先后次序不同算不同的结果）。
*/
int jumpFloor(int number) {
	return 0;
}


bool BinarySearch(int target,vector<int> array){
	int low = 0;
	int high = array.size() - 1;
	while (low<=high){
		int mid = (low + high) / 2;
		
		if (target < array[mid]){
			high = mid - 1;
		}
		else if (target > array[mid]){
			low = mid + 1;
		}
		else{
			return true;
		}
	}
	return false;
}

/*折半插入排序
*/
void BinaryInsertSort(int a[], int len){
	for (int i = 1; i < len; i++){
		int key = a[i];
		int low = 0, mid, high = i - 1;
		while (low <= high){
			mid = (low + high) / 2;
			if (key > a[mid]){
				low = mid + 1;
			}
			else if (key < a[mid]){
				high = mid - 1;
			}
		}
		//将low往后元素(包括low所指向的元素)全部后移一个位置
		for (int j = i - 1; j >= low; j--)
		{
			a[j + 1] = a[j];
		}
		a[low] = key;
	}
}
/*字符串替换:replaceSpace(char *str,int length)
	请实现一个函数，将一个字符串中的每个空格替换成“ % 20”。例如，当字符串为We Are Happy.
	则经过替换之后的字符串为We%20Are % 20Happy。
*/
void replaceSpace(char *str, int length){
	string s;
	for (int i = 0; i < length; i++){
		if (str[i]!=' '){
			s += str[i];
		}
		else{
			s += "% 20";
		}
	}
	cout << s << endl;
}

/*
	冒泡排序：
*/
void BubbleSort(int a[], int len){
	int len2 = len;
	for (int i = 1; i<len; i++)
	{
		for (int j = 1; j<len2; j++)
		{
			if (a[j - 1]>a[j])
			{
				int temp;
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
		len2--;
	}
	//输出结果
	for (int i = 0; i < len; i++){
		cout << a[i] << " ";
	}
}

/*
	选择排序:每次选出最小或者最大的元素
*/
void SelectionSort(int a[], int len){
	
	int temp;
	for (int i = 0; i < len; i++){
		//找出最小的元素的index
		int index = i;
		for (int j = i+1; j < len; j++){
			if (a[index] > a[j]){
				index = j;
			}
		}
		//将最小元素替换
		temp = a[index];
		a[index] = a[i];
		a[i] = temp;
	}

	for (int i = 0; i < len; i++){
		cout << a[i] << " ";
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	/*一、测试案例
		4*4的二位数组
		1  2  3  4
		5  6  7  8
		9  10 11 12
		13 14 15 16
	*/
	vector<vector<int>> vec;
	vector<int> vec1;
	int x=1;
	for (int i = 0; i < 4; i++){
		vec1.clear();		//每次都要clear
		for (int j = 0; j < 4; j++){
			vec1.push_back(x);
			x+=2;
		}
		vec.push_back(vec1);
	}

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			cout << vec[i][j]<<" ";
		}
		cout << endl;
	}

	int target[] = { 0, 6, 11, 19, 21, 28, 31, 37, 50, 100 };

	/*****************FindOfArrayInt2算法测试**********************/
	for (int i = 0; i < 10; i++){
		if (FindOfArrayInt2(target[i], vec)){
			cout << "二位数组中存在该整数："<<target[i] << endl;
		}
		else{
			cout << "二位数组中不存在该整数："<<target[i] << endl;
		}
	}
	cout << endl;

	/*****************BinarySearch() 二分查找算法测试**********************/
	vector<int> bsvec;
	int array[] = { 1, 10, 11, 21, 28, 37, 45, 57, 60, 72, 83, 90, 100, 143, 150 };
	for (int i = 0; i < 15; i++){
		bsvec.push_back(array[i]);
		cout << array[i] << " ";
	}
	for (int i = 0; i < 10; i++){
		if (BinarySearch(target[i], bsvec)){
			cout << "数组中存在这个整数" << target[i] << endl;
		}
		else{
			cout << "数组中不存在这个整数" << target[i] << endl;
		}
	}
	cout << endl;

	/********************replaceSpace(char *str, int length)测试**********/
	char str[] = {"hello world"};
	int len = strlen(str);
	//cout << len << endl;
	replaceSpace(str,len);


	/****************BubbleSort(int a[], int len) 冒泡排序测试*************/
	int a[] = { 23, 11, 5, 100, 58, 45, 76, 82, 65, 99 };
	for (int i = 0; i < 10; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	cout <<"冒泡排序结果：";
	BubbleSort(a, 10);

	cout << endl;
	/**************SelectionSort(int a[], int len) 选择排序测试**************/
	cout << "选择排序结果：";
	SelectionSort(a, 10);

	cout << endl;
	/**************BInsertSort(int a[], int len) 折半插入排序测试************/
	int B[] = { 1, 10, 11, 21, 28, 37, 45, 57, 60, 72, 83, 90, 100, 143, 150 };
	//求数组长度方法
	BinaryInsertSort(B, sizeof(B) / sizeof(int));
	cout << "折半插入排序的结果：";
	for (int i = 0; i < sizeof(B) / sizeof(int); i++){
		cout << B[i] << " ";
	}

	cout << endl;
	/*****************************************/

	system("pause");
	return 0;
}

