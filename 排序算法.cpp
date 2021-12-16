#define	_CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#define MAXSIZE 20//˳�����󳤶�
typedef int keytype;//����ؼ�������Ϊ����
typedef int Infotype;
typedef struct {
	keytype key;//�ؼ���
	Infotype otherinfo;//�����������ʵ����Ҫ��
}Redtype;
typedef struct {
	Redtype r[MAXSIZE+1];//r[0]�������ڱ�
	int length;//˳�����
}Sqlist;

//����һ������Ϊn��˳���L
void CreateList(Sqlist& L, int n) {
	if (n > MAXSIZE) {
		cout << "�洢����" << endl;
		return;
	}
	int i;
	L.length = n;
	cout << "��������Ҫ������˳����е�Ԫ�أ�";
	for (i = 1; i <= n; i++) {
		cin >> L.r[i].key;//��ʵ�鲻��������������
	}
}
//ֱ�Ӳ�������
void Insertsort(Sqlist& L) {
	int i, j;
	for (i = 2; i <= L.length; i++) {
		if (L.r[i].key < L.r[i - 1].key) {
			L.r[0] = L.r[i];//����ֵ����Ϊ�ڱ�
			for (j = i - 1; L.r[0].key < L.r[j].key; j--)
				L.r[j + 1] = L.r[j];//��j->i-1ȫ��Ԫ�غ����
			L.r[j + 1] = L.r[0];
		}
		
	}
}

//��������
void quicksort(Sqlist& L, int left, int right) {
	int i, j, temp;
	if (left > right)
		return;
	i = left;
	j = right;
	L.r[0] = L.r[left];
	temp=L.r[left].key;//temp��Ż�׼��
	while (i != j) {//�ȴ��ұ߿�ʼ��
		while (L.r[j].key >= temp && i < j)//���ұ��ҵ�һ��С�ڻ�׼������
		{
			j--;
		}	
		while (L.r[i].key <= temp && i < j)//������ҵ�һ�����ڻ�׼������
		{
			i++;
		}
		if (i < j) {//��������Ԫ��
			L.r[0] = L.r[i];
			L.r[i] = L.r[j];
			L.r[j] = L.r[0];
		}
	}
	//��׼����λ
	L.r[0] = L.r[left];
	L.r[left] = L.r[i];
	L.r[i] = L.r[0];
	quicksort(L,left, i - 1);//�Ի�׼����ߵ�����ݹ�����
	quicksort(L, i + 1, right);//�Ի�׼���ұߵ�����ݹ�����
}

//ѡ������
void selectsort(Sqlist& L) {
	int i;
	for (i = 1; i <= L.length; i++) {
		int min = i, pos = i + 1;
		while (pos <= L.length) {//ѡ����i��n֮�����Сֵ
			if (L.r[pos].key <= L.r[min].key) {
				min = pos;
			}
			pos++;
		}//����Сֵ��L.r[i]����
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

void print(Sqlist L) {//��ӡ˳���Ĺؼ���
	int i;
	cout << "˳���ؼ���˳��Ϊ��";
	for (i = 1; i <= L.length; i++)
		cout << L.r[i].key << " ";
	cout << endl;
}

int main() {
	Sqlist L;
	int n;
	cout << "*********************************************************************" << endl;
	cout << "   1.ֱ�Ӳ�������     2.�򵥿�������     3.ѡ������     4.�˳�����   " << endl;
	cout << "*********************************************************************" << endl;
	int input;
	while (1) {
		cout << "��������Ҫ���еĲ�����";
		cin >> input;
		switch (input) {
		case 1: {
			cout << "��������Ҫ����˳���ĳ��ȣ�";
			cin >> n;
			CreateList(L, n);
			Insertsort(L);
			print(L);
			break;
		}
		case 2: {
			cout << "��������Ҫ����˳���ĳ��ȣ�";
			cin >> n;
			CreateList(L, n);
			quicksort(L,1,n);
			print(L);
			break;
		}
		case 3: {
			cout << "��������Ҫ����˳���ĳ��ȣ�";
			cin >> n;
			CreateList(L, n);
			selectsort(L);
			print(L);
			break;
		}
		case 4: {
			cout << "�˳�����" << endl;
			exit(0);
		}
		default: {
			cout << "���������������" << endl;
			break;
		}
		}
	}
}
