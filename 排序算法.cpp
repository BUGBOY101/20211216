#define	_CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#define MAXSIZE 20//顺序表最大长度
typedef int keytype;//定义关键词类型为整型
typedef int Infotype;
typedef struct {
	keytype key;//关键词
	Infotype otherinfo;//其他数据项（本实验无要求）
}Redtype;
typedef struct {
	Redtype r[MAXSIZE+1];//r[0]闲置做哨兵
	int length;//顺序表长度
}Sqlist;

//创建一个长度为n的顺序表L
void CreateList(Sqlist& L, int n) {
	if (n > MAXSIZE) {
		cout << "存储已满" << endl;
		return;
	}
	int i;
	L.length = n;
	cout << "请输入您要创建的顺序表中的元素：";
	for (i = 1; i <= n; i++) {
		cin >> L.r[i].key;//本实验不考虑其他数据项
	}
}
//直接插入排序
void Insertsort(Sqlist& L) {
	int i, j;
	for (i = 2; i <= L.length; i++) {
		if (L.r[i].key < L.r[i - 1].key) {
			L.r[0] = L.r[i];//将其值复制为哨兵
			for (j = i - 1; L.r[0].key < L.r[j].key; j--)
				L.r[j + 1] = L.r[j];//从j->i-1全部元素后后移
			L.r[j + 1] = L.r[0];
		}
		
	}
}

//快速排序
void quicksort(Sqlist& L, int left, int right) {
	int i, j, temp;
	if (left > right)
		return;
	i = left;
	j = right;
	L.r[0] = L.r[left];
	temp=L.r[left].key;//temp存放基准数
	while (i != j) {//先从右边开始找
		while (L.r[j].key >= temp && i < j)//从右边找第一个小于基准数的数
		{
			j--;
		}	
		while (L.r[i].key <= temp && i < j)//从左边找第一个大于基准数的数
		{
			i++;
		}
		if (i < j) {//交换两个元素
			L.r[0] = L.r[i];
			L.r[i] = L.r[j];
			L.r[j] = L.r[0];
		}
	}
	//基准数归位
	L.r[0] = L.r[left];
	L.r[left] = L.r[i];
	L.r[i] = L.r[0];
	quicksort(L,left, i - 1);//对基准数左边的数组递归排序
	quicksort(L, i + 1, right);//对基准数右边的数组递归排序
}

//选择排序
void selectsort(Sqlist& L) {
	int i;
	for (i = 1; i <= L.length; i++) {
		int min = i, pos = i + 1;
		while (pos <= L.length) {//选出从i到n之间的最小值
			if (L.r[pos].key <= L.r[min].key) {
				min = pos;
			}
			pos++;
		}//将最小值与L.r[i]交换
		L.r[0] = L.r[i];
		L.r[i] = L.r[min];
		L.r[min] = L.r[0];
	}
}

//void selectsort(Sqlist& L) {
//	int i, j, n = L.length;
//	for (i = 1; i <= n-1; i++) {
//		for (j = i+1; j <= n; j++) {
//			if (L.r[i].key > L.r[j].key) {
//				L.r[0] = L.r[i];
//				L.r[i] = L.r[j];
//				L.r[j] = L.r[0];
//			}
//		}
//	}
//}

void print(Sqlist L) {//打印顺序表的关键词
	int i;
	cout << "顺序表关键词顺序为：";
	for (i = 1; i <= L.length; i++)
		cout << L.r[i].key << " ";
	cout << endl;
}

int main() {
	Sqlist L;
	int n;
	cout << "*********************************************************************" << endl;
	cout << "   1.直接插入排序     2.简单快速排序     3.选择排序     4.退出程序   " << endl;
	cout << "*********************************************************************" << endl;
	int input;
	while (1) {
		cout << "请输入您要进行的操作：";
		cin >> input;
		switch (input) {
		case 1: {
			cout << "请输入你要创建顺序表的长度：";
			cin >> n;
			CreateList(L, n);
			Insertsort(L);
			print(L);
			break;
		}
		case 2: {
			cout << "请输入你要创建顺序表的长度：";
			cin >> n;
			CreateList(L, n);
			quicksort(L,1,n);
			print(L);
			break;
		}
		case 3: {
			cout << "请输入你要创建顺序表的长度：";
			cin >> n;
			CreateList(L, n);
			selectsort(L);
			print(L);
			break;
		}
		case 4: {
			cout << "退出程序" << endl;
			exit(0);
		}
		default: {
			cout << "输入错误重新输入" << endl;
			break;
		}
		}
	}
}
