#pragma once
#define MAX_LEN 100000	//链表最大容许长度
#define DEFAULT_INITIAL_VOLUMN 100	//默认初始化链表容量

//以下的class T应当具备大小关系的、可比较的
template <class T>
struct Node {
	T data;
	Node *previous;		//指向前一个结点
	Node *next;			//指向后一个结点
};

template <class T>
class Priority_Linklist {
private:
	Node empty_list_h;			//空链表头，表头本身不计入表长，不用作数据记录。注意它不是指针。
	Node full_list_h;			//满链表头，表头本身不计入表长，不用作数据记录。注意它不是指针。
	int m_size;
	int m_volumn;

	int increment();			//公共函数push()需要使用的方法
								//如果空链表块链为空，先检查m_volumn * 2是否大于MAX_LEN，如果大于，则扩容非法，返回-1
								//否则进行扩容，建立m_volumn个空链表Node，然后更新m_volumn变量，返回0.
public:
	Priority_Linklist(int initial_volumn = DEFAULT_INITIAL_VOLUMN);
								//待定义的构造函数，需要完成以下工作：
								//1.确定一个初始容量initial_volumn
								//2.让空链表头和满链表头的p域和n域都指向自身
								//3.对空链表头的n域：为n域申请空间，然后为n域指向结点的n域申请空间，以此类推，直至个数满足要求
								//4.调整空链表，使各指针正确作用。主要是调整空链表的p域。
								//5.填写m_size=0, m_volumn=initial_volumn.

	~Priority_Linklist();		//待定义的析构函数

	T top();					//返回满链表块链的链头

	int push(T element);		//从空链表链中取出一个空链表块，把element拷贝到链表块的d域后，将它移动到满链表队列的恰当位置
								//如果空链表队列为空，则调用increment()扩容
								//如果元素插入失败，返回-1.成功插入,m_size++, 返回0.

	int pop(T element);			//删除满链表链的链头，size--
								//如果原本满链表链就为空，则返回-1，否则返回0.

	bool empty();				//如果满链表链为空，则返回true，否则返回false.

	void swap(Priority_Linklist<T> other);	//交换两链表对象。如果用不到，可以不实现这一方法。（直接返回）

	int size() { return(m_size); }
	int volumn() { return(m_volumn); }
};
