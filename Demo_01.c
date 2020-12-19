#include<stdio.h>
/*
* 实验二：PCB的链式组织
*	1. 创建带头节点的PCB链表
*	2. 创建就绪状态的PCB并加入链表
*	3. 删除指定的PCB
*	4. 显示链表中的PCB信息 
*/

#define LEN sizeof(struct PCBNode)//令LEN代表struct PCBNode类型数据的长度

//创建结构体
typedef struct PCBNode {
	int no;				//PCB序号
	char name[10];		//PCB名称
	int status;			//PCB运行状态	0：就绪   1：运行	-1：阻塞
	int rt;				//PCB运行时间
	struct PCBNode *next;//结构体指针
}PCB;

//创建带头节点的PCB链表
struct PCBNode *newPCB(void) {
	struct PCBNode* head;
	struct PCBNode* head1,*head2;
	head1=head2 = (struct PCBNode*)malloc(LEN);//为结构体申请内存空间
	head = NULL;
	int n = 0;
	printf("*****初始化PCB链表*****");
	while(1) {
		printf("\n请输入PCB序号：");
		scanf_s("%d", &head1->no);
		printf("请输入PCB名称：");
		scanf("%s", &head1->name);
		while (1) {
			printf("请输入PCB运行状态（0-就绪 1-运行 -1-阻塞）：");
			scanf_s("%d", &head1->status);
			if (head1->status > 1 || head1->status < -1)
				continue;
			else
				break;
		}
		while (1) {
			printf("请输入PCB运行时间：");
			scanf_s("%d", &head1->rt);
			if (head1->rt >= 0)//运行时间只能大于零
				break;
			printf("运行时间只能为正数！");
		}
		
		n += 1;
		if (n == 1) head = head1;
		else head2->next = head1;
		head2 = head1;
		head1 = (struct PCBNode*)malloc(LEN);
		int x;
		while (1) {
			printf("是否继续？(0-结束  1-继续)");
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

//删除节点
struct PCBNode* deletePCB(struct PCBNode* head) {
	int x;
	struct PCBNode* p1,*p2;
	p1 = head;
	printf("请输入您要删除的节点序号：");
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
			printf("删除序号为：%d 的PCB节点成功！",x);
			free(p1);
		}
		else {
			printf("未找到序号为：%d 的节点！",x);
		}
		return (head);
	}
	else {
		printf("链表无数据，请初始化链表。\n");
		return(head);
	}
}

//插入节点
struct PCBNode* insPCB(struct PCBNode* head) {
	int len = sizeof(*head);
	int x;
	struct PCBNode* head1, * head2;
	head1 = (struct PCBNode*)malloc(LEN);
	head2 = (struct PCBNode*)malloc(len);
	printf("*****插入PCB节点*****");
	head2 = head;
	while (head2->next != NULL) {//使用尾插法，找到最后一个节点
		head2 = head2->next;
	}
	while (1) {
		printf("\n请输入PCB序号：");
		scanf_s("%d", &head1->no);
		printf("请输入PCB名称：");
		scanf("%s", &head1->name);
		while (1) {
			printf("请输入PCB运行状态（0-就绪 1-运行 -1-阻塞）：");
			scanf_s("%d", &head1->status);
			if (head1->status > 1 || head1->status < -1)
				continue;
			else
				break;
		}
		while (1) {
			printf("请输入PCB运行时间：");
			scanf_s("%d", &head1->rt);
			if (head1->rt >= 0)//运行时间只能大于零
				break;
			printf("运行时间只能为正数！");
		}
		head2->next = head1;
		head2 = head1;
		head1 = (struct PCBNode*)malloc(LEN);
		int x;
		while (1) {
			printf("是否继续？(0-结束  1-继续)");
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


//输出PCB
void printPCB(struct PCBNode * head) {
	struct PCBNode* pcb;
	pcb = head;
	if (head != NULL) {
		do{
			printf("\n\n*******************");
			printf("\nPCB序号：%d", pcb->no);
			printf("\nPCB名称：%s", pcb->name);
			printf("\nPCB运行状态：%d", pcb->status);
			printf("\nPCB运行时间：%d", pcb->rt);
			printf("\n*******************");
			pcb = pcb->next;
		} while (pcb != NULL);
	}
	else {
		printf("链表无数据，请初始化链表。\n");
	}
}


/*
/*
* 实验三
*	目的：
*		1.理解进程的概念和基本特征
*		2.掌握进程的状态及转换
*		3.掌握进程的基本操作
*	内容：
*		编写程序实现进程创建、进程撤销、进程阻塞、进程唤醒和进程调度运行五个基本操作
*/

//创建进程的就绪队列和阻塞队列
void init(void) {
	struct PCBNode* PRun = (struct PCBNode*)malloc(LEN);//建立带头节点的空运行队列
	PRun->next = NULL;
	struct PCBNode* PReady = (struct PCBNode*)malloc(LEN);//建立带头节点的空就绪队列
	PReady->next = NULL;
	struct PCBNode* PBlock = (struct PCBNode*)malloc(LEN);//建立带头节点的空阻塞队列
	PBlock->next = NULL;

}



int main() {
	struct PCBNode* head;
	head = newPCB();//初始化链表
	while (1) {
		printf("\n\n请选择您想要进行的操作：\n");
		int x;
		do {
			printf("1.删除节点\t2.插入节点\t3.输出节点\t0.结束\n");
			scanf_s("%d", &x);
		} while (x != 1 && x != 2 && x != 3 && x != 0);
		switch (x) {
		case 0:
			free(head);
			return 0;
		case 1:
			head=deletePCB(head);//删除节点
			break;
		case 2:
			head=insPCB(head);
			break;
		case 3:
			printPCB(head);//输出链表
			break;
		}
	}
	

	return 0;
}