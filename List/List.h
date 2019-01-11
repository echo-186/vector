#pragma once
#define ListNodePos(T)=ListNode<T>*;
template<typename T>
 struct ListNode
{
	T data;
	ListNode<T>* pred,* succ;
	ListNode() {};
	ListNode(T e, ListNode<T>*p = nullptr, ListNode<T>*s = nullptr) :data(e), pred(p), succ(s) {}//Ĭ�Ϲ�����
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
	void copyNodes(ListNode<T> *p, int n);//β��
	ListNode<T>*selectmax(ListNode<T>*p, int n);
	void search(int n, ListNode<T>*p);//n����p
	

public:
	
	List();
	List( ListNode<T>*p, int n);
	~List();
	ListNode<T>* first() const{ return header->succ; };
	ListNode<T>* last()const { return trailer->pred; };
	T& operator[](int r)const;
	ListNode<T>* find(const T &e, int n, ListNode<T>*p)const;//�ڽڵ�p��n����ǰ�����ҵ�����e�������
	ListNode<T>* find(const T &e, ListNode<T>*p, int n)const;//�ڽڵ�p��n��������ҵ�����e�������
	ListNode<T>*search(const T&e, int n, ListNode<T>*p)const;//��p֮ǰ�ҵ�������e�������
	ListNode<T>* InsertAsFirst(T const&e);//��e��Ϊͷ������
	ListNode<T>*InsertAsLast(T const&e);
	ListNode<T>* InsertBefore(T const&e, ListNode<T>*p);//��Ϊp���ǰ������
	ListNode<T>* InsertAfter(ListNode<T>*p, T const&e);
	T remove(ListNode<T> *p);//ɾ���ڵ�
	int deduplicate();//�����б�Ψһ��
	int uniquify();//�����б�Ψһ��
	void selectionSort(ListNode<T>*p,int n);
	void insertSort(ListNode<T>*p, int n);

	



};

