#pragma once
#define ListNodePos(T)=ListNode<T>*;
template<typename T>
 struct ListNode
{
	T data;
	ListNode<T>* pred,* succ;
	ListNode() {};
	ListNode(T e, ListNode<T>*p = nullptr, ListNode<T>*s = nullptr) :data(e), pred(p), succ(s) {}//默认构造器
	ListNode<T>* insertAsPred(T const&e) { ListNode*p = new ListNode(e, pred, this); pred->succ = p; pred = p; return p; }
	ListNode<T>* insertAsSucc(T const&e) { ListNode*p = new ListNode(e, this, succ); succ->pred = p; succ = p; return p; }

};

template<typename T>
class List
{
private:
	ListNode<T>* trailer,*header;
	int _size;
protected:
	void init();
	void clear();
	void copyNodes(ListNode<T> *p, int n);//尾插
	ListNode<T>*selectmax(ListNode<T>*p, int n);
	void search(int n, ListNode<T>*p);//n包括p
	

public:
	
	List();
	List( ListNode<T>*p, int n);
	~List();
	ListNode<T>* first() const{ return header->succ; };
	ListNode<T>* last()const { return trailer->pred; };
	T& operator[](int r)const;
	ListNode<T>* find(const T &e, int n, ListNode<T>*p)const;//在节点p的n个真前驱中找到等于e的最后者
	ListNode<T>* find(const T &e, ListNode<T>*p, int n)const;//在节点p的n个后继中找到等于e的最后者
	ListNode<T>*search(const T&e, int n, ListNode<T>*p)const;//在p之前找到不大于e的最后者
	ListNode<T>* InsertAsFirst(T const&e);//把e作为头结点插入
	ListNode<T>*InsertAsLast(T const&e);
	ListNode<T>* InsertBefore(T const&e, ListNode<T>*p);//作为p点的前驱插入
	ListNode<T>* InsertAfter(ListNode<T>*p, T const&e);
	T remove(ListNode<T> *p);//删除节点
	int deduplicate();//无序列表唯一化
	int uniquify();//有序列表唯一化
	void selectionSort(ListNode<T>*p,int n);
	void insertSort(ListNode<T>*p, int n);

	



};

