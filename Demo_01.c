#include<stdio.h>
/*
* ʵ�����PCB����ʽ��֯
*	1. ������ͷ�ڵ��PCB����
*	2. ��������״̬��PCB����������
*	3. ɾ��ָ����PCB
*	4. ��ʾ�����е�PCB��Ϣ 
*/

#define LEN sizeof(struct PCBNode)//��LEN����struct PCBNode�������ݵĳ���

//�����ṹ��
typedef struct PCBNode {
	int no;				//PCB���
	char name[10];		//PCB����
	int status;			//PCB����״̬	0������   1������	-1������
	int rt;				//PCB����ʱ��
	struct PCBNode *next;//�ṹ��ָ��
}PCB;

//������ͷ�ڵ��PCB����
struct PCBNode *newPCB(void) {
	struct PCBNode* head;
	struct PCBNode* head1,*head2;
	head1=head2 = (struct PCBNode*)malloc(LEN);//Ϊ�ṹ�������ڴ�ռ�
	head = NULL;
	int n = 0;
	printf("*****��ʼ��PCB����*****");
	while(1) {
		printf("\n������PCB��ţ�");
		scanf_s("%d", &head1->no);
		printf("������PCB���ƣ�");
		scanf("%s", &head1->name);
		while (1) {
			printf("������PCB����״̬��0-���� 1-���� -1-��������");
			scanf_s("%d", &head1->status);
			if (head1->status > 1 || head1->status < -1)
				continue;
			else
				break;
		}
		while (1) {
			printf("������PCB����ʱ�䣺");
			scanf_s("%d", &head1->rt);
			if (head1->rt >= 0)//����ʱ��ֻ�ܴ�����
				break;
			printf("����ʱ��ֻ��Ϊ������");
		}
		
		n += 1;
		if (n == 1) head = head1;
		else head2->next = head1;
		head2 = head1;
		head1 = (struct PCBNode*)malloc(LEN);
		int x;
		while (1) {
			printf("�Ƿ������(0-����  1-����)");
			scanf_s("%d", &x);
			if (x == 0 || x == 1) {
				break;
			}
		}
		if (x == 0) {
			head2->next = NULL;
			break;
		}
	}
	return head;
}

//ɾ���ڵ�
struct PCBNode* deletePCB(struct PCBNode* head) {
	int x;
	struct PCBNode* p1,*p2;
	p1 = head;
	printf("��������Ҫɾ���Ľڵ���ţ�");
	scanf_s("%d", &x);
	if (head != NULL) {
		while (p1->no != x && p1->next != NULL) {
			p2 = p1;
			p1 = p1->next;
		}
		if (p1->no == x) {
			if (p1 == head) {
				head = p1->next;
			}
			else {
				p2->next = p1->next;
			}
			printf("ɾ�����Ϊ��%d ��PCB�ڵ�ɹ���",x);
			free(p1);
		}
		else {
			printf("δ�ҵ����Ϊ��%d �Ľڵ㣡",x);
		}
		return (head);
	}
	else {
		printf("���������ݣ����ʼ������\n");
		return(head);
	}
}

//����ڵ�
struct PCBNode* insPCB(struct PCBNode* head) {
	int len = sizeof(*head);
	int x;
	struct PCBNode* head1, * head2;
	head1 = (struct PCBNode*)malloc(LEN);
	head2 = (struct PCBNode*)malloc(len);
	printf("*****����PCB�ڵ�*****");
	head2 = head;
	while (head2->next != NULL) {//ʹ��β�巨���ҵ����һ���ڵ�
		head2 = head2->next;
	}
	while (1) {
		printf("\n������PCB��ţ�");
		scanf_s("%d", &head1->no);
		printf("������PCB���ƣ�");
		scanf("%s", &head1->name);
		while (1) {
			printf("������PCB����״̬��0-���� 1-���� -1-��������");
			scanf_s("%d", &head1->status);
			if (head1->status > 1 || head1->status < -1)
				continue;
			else
				break;
		}
		while (1) {
			printf("������PCB����ʱ�䣺");
			scanf_s("%d", &head1->rt);
			if (head1->rt >= 0)//����ʱ��ֻ�ܴ�����
				break;
			printf("����ʱ��ֻ��Ϊ������");
		}
		head2->next = head1;
		head2 = head1;
		head1 = (struct PCBNode*)malloc(LEN);
		int x;
		while (1) {
			printf("�Ƿ������(0-����  1-����)");
			scanf_s("%d", &x);
			if (x == 0 || x == 1) {
				break;
			}
		}
		if (x == 0) {
			head2->next = NULL;
			break;
		}
	}
	return head;
}


//���PCB
void printPCB(struct PCBNode * head) {
	struct PCBNode* pcb;
	pcb = head;
	if (head != NULL) {
		do{
			printf("\n\n*******************");
			printf("\nPCB��ţ�%d", pcb->no);
			printf("\nPCB���ƣ�%s", pcb->name);
			printf("\nPCB����״̬��%d", pcb->status);
			printf("\nPCB����ʱ�䣺%d", pcb->rt);
			printf("\n*******************");
			pcb = pcb->next;
		} while (pcb != NULL);
	}
	else {
		printf("���������ݣ����ʼ������\n");
	}
}


/*
/*
* ʵ����
*	Ŀ�ģ�
*		1.�����̵ĸ���ͻ�������
*		2.���ս��̵�״̬��ת��
*		3.���ս��̵Ļ�������
*	���ݣ�
*		��д����ʵ�ֽ��̴��������̳������������������̻��Ѻͽ��̵������������������
*/

//�������̵ľ������к���������
void init(void) {
	struct PCBNode* PRun = (struct PCBNode*)malloc(LEN);//������ͷ�ڵ�Ŀ����ж���
	PRun->next = NULL;
	struct PCBNode* PReady = (struct PCBNode*)malloc(LEN);//������ͷ�ڵ�Ŀվ�������
	PReady->next = NULL;
	struct PCBNode* PBlock = (struct PCBNode*)malloc(LEN);//������ͷ�ڵ�Ŀ���������
	PBlock->next = NULL;

}



int main() {
	struct PCBNode* head;
	head = newPCB();//��ʼ������
	while (1) {
		printf("\n\n��ѡ������Ҫ���еĲ�����\n");
		int x;
		do {
			printf("1.ɾ���ڵ�\t2.����ڵ�\t3.����ڵ�\t0.����\n");
			scanf_s("%d", &x);
		} while (x != 1 && x != 2 && x != 3 && x != 0);
		switch (x) {
		case 0:
			free(head);
			return 0;
		case 1:
			head=deletePCB(head);//ɾ���ڵ�
			break;
		case 2:
			head=insPCB(head);
			break;
		case 3:
			printPCB(head);//�������
			break;
		}
	}
	

	return 0;
}