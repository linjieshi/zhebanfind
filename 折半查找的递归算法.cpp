#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int key;
}Elemtype;
typedef struct {
	Elemtype *elem;
	int length;
}Table;
int Create(Table &S, int n) {
	S.elem = (Elemtype *)malloc(n * sizeof(Elemtype));
	if (!S.elem) {
		S.length = 0;
		exit(0);
	}
	else
		S.length = n;
	return 1;
}
int Search(Table S, int key, int low, int high) {
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (key = S.elem[mid].key) {
			return mid;
		}
		else if (key < S.elem[mid].key) {
			return Search(S, key, low, mid - 1);
		}
		else
			return Search(S, key, mid + 1, high);
	}
	return 0;//����ʧ�� 
}
int main() {
	int key, i, n;
	Table S;
	printf("�������");
	scanf_s("%d", &n);
	Create(S, n);
	printf("���������");
	for (i = 0; i < S.length; i++) {
		scanf_s("%d", &S.elem[i].key);
	}
	printf("����Ҫ���ҵ�����");
	scanf_s("%d", &key);
	printf("Ԫ������λ�ã�%d\n", Search(S, key, 0, n - 1) + 1);
	system("pause");
	return 0;
}