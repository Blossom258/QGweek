# C++类模板实现排序二叉树的相关功能函数(前序遍历，中序遍历，后序遍历（递归\非递归)）

## 一.基本数据：

```C++
#include<iostream>
#include<stack>
#include<queue>
using std::cout;
using std::cin;
using std::endl;
using std::stack;
using std::queue;

template <typename T>
class Node 
{
public:
    T value;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
};

template <typename T>
class BinarySortTree :public Node<T>
{
private:
    Node<T>* root ;
public:
    BinarySortTree();
    ~BinarySortTree();
    bool BST_insert(const T value);
    bool BST_delete(T value);
    Node<T>* BST_search(T value);
    void BST_preorderI();
    void BST_preorderR(Node<T>*p);
    void BST_inorderI();
    void BST_inorderR(Node<T>* p);
    void BST_postorderI();
    void BST_postorderR(Node<T>* p);
    void BST_preorderR();
    void BST_inorderR();
    void BST_postorderR();
    void BST_levelOrder();
    void destroy(Node<T>* p);
    Node<T>* getParent(Node<T>* p);
};
```

## 二.函数实现：

### 1.创建排序二叉树

```c++
template <class T>
BinarySortTree<T>::BinarySortTree()
{
    this->root = nullptr;
}
```

### 2.销毁排序二叉树

```c++
template <class T>
BinarySortTree<T>::~BinarySortTree()
{
    destroy(root);
   
}
```

```c++
template <class T>
void BinarySortTree<T>::destroy(Node<T>* p)
{
    if (p != nullptr)
    {
        if (p->left != nullptr)
            destroy(p->left);
        if (p->right != nullptr)
            destroy(p->right);
        delete p;
        p = nullptr;
    }
   
}
```

### 3.插入元素

```c++
template <class T>
bool BinarySortTree<T>::BST_insert(const T value)
{

    Node<T>* ptr = new Node<T>;
    ptr->value = value;
    ptr->left = nullptr;
    ptr->right = nullptr;
    if (ptr == nullptr)
    {
        return false;
    }

    if (root == nullptr)
    {
       root = ptr;
       root->left = nullptr;
       root->right = nullptr;
        return true;
    }

    Node<T>* p = root;
    Node<T>* pParent =root;
    while (p != nullptr)
    {

        pParent = p;
          if (value > p->value)
        {
            p = p->right;
        }
        else if(value< p->value)
        {
            p = p->left;
        }
        else
          {
              
              delete ptr;
              ptr = nullptr;
              return false;
          }
    }

     if (value < pParent->value)
    {
        pParent->left = ptr;
    }
    if (value > pParent->value)
    {
        pParent->right = ptr;
    }
    return true;

}
```

### 4.删除元素

```c++
template <class T>
bool BinarySortTree<T>::BST_delete(T value)
{
    Node<T>* p = this->BST_search(value);
    if (p == nullptr)
    {
        return false;
    }
   
     if (p->left == nullptr )
    {

        Node<T>* pParent = getParent(p);
        if (pParent->left == p)
            pParent->left = p->right;
        else
            pParent->right = p->right;
        delete p;
        p = nullptr;
        return true;
    }
     else   if (p->right == nullptr)
     {

         Node<T>* pParent = getParent(p);
         if (pParent->left == p)
             pParent->left = p->left;
         else
             pParent->right = p->left;
         delete p;
         p = nullptr;
         return true;
     }
```

### 5.查找元素

```c++
template <typename T>
Node<T>* BinarySortTree<T>::BST_search(T value)
{

    Node<T>* ptr = root;

    while (ptr != nullptr)
    {
        if (ptr->value == value)
            return ptr;
        else  if (ptr->value > value)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return nullptr;
}
```

### 6.前序遍历(递归)

```c++
template <typename T>
void  BinarySortTree<T>::BST_preorderR()
{
    BST_preorderR(root);
}

template <typename T>
void  BinarySortTree<T>::BST_preorderR(Node<T>* p)
{
    if (p != nullptr)
    {
        cout << p->value << endl;
        BST_preorderR(p->left);
        BST_preorderR(p->right);
    }

}
```

### 7.前序遍历(非递归)

```c++
template <typename T>
void BinarySortTree<T>::BST_preorderI()
{
    stack<Node<T>*>s;
    Node<T>* p = root;
    while (p != nullptr || !s.empty())
    {
        while (p != nullptr)
        {
            cout << p->value <<endl;
            s.push(p);
            p = p->left;
        }
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
  
}
```

### 8.中序遍历(递归)

```c++
template<typename T>
void BinarySortTree<T>::BST_inorderR()
{
    BST_inorderR(root);
}

template<typename T>
void BinarySortTree<T>::BST_inorderR(Node<T>* p)
{
    if (p != nullptr)
    {
        BST_inorderR(p->left);
        cout << p->value <<endl;
        BST_inorderR(p->right);
    }
    
}
```

### 9.中序遍历(非递归)

```c++
template<typename T>
void BinarySortTree<T>::BST_inorderI()
{
    stack<Node<T>*> s;
    Node<T>* p = root;
    while (p != nullptr || !s.empty())
    {
        while (p != NULL)
        {
            s.push(p);
            p = p->left;
        }
        if (!s.empty())
        {
            p = s.top();
            cout << p->value << endl;
            s.pop();
            p = p->right;
        }
    }

}
```

### 10.后序遍历(递归)

```c++
template<typename T>
void BinarySortTree<T>::BST_postorderR()
{
    BST_postorderR(root);
}

template<typename T>
void BinarySortTree<T>::BST_postorderR(Node<T>* p)
{
    if (p != nullptr)
    {
        BST_postorderR(p->left);
        BST_postorderR(p->right);
        cout << p->value << endl;
    }

}
```

### 11.后序遍历(非递归)

```c++
template<typename T>
void BinarySortTree<T>::BST_postorderI()
{

    stack<Node<T>*> t;
    stack<Node<T>*> t1;
    t.push(root);
    while (!t.empty())
    {
       root = t.top();
        t1.push(t.top());
        t.pop();
        if (root->left != nullptr)
        {
            t.push(root->left);
        }
        if (root->right != nullptr)
        {
            t.push(root->right);
        }
    }
    //出栈
    while (!t1.empty())
    {
        cout << t1.top()->value<<endl;
        t1.pop();
    }


}
```

### 12.找到对应节点的父亲节点

```c++
template<class T>
Node<T>* BinarySortTree<T>::getParent(Node<T>* p)
{
    if (p == root)
        return NULL;
    Node<T>* ptr = root;
    Node<T>* ptf = ptr;
    while (ptr != NULL)
    {
        if (ptr->value == p->value)
            return ptf;
        if (ptr->value > p->value)
        {
            ptf = ptr;
            ptr = ptr->left;
        }
        else
        {
            ptf = ptr;
            ptr = ptr->right;
        }
    }
    cout << endl;
}
```

### 13.层序遍历

```c++
template<class T>
void BinarySortTree<T>::BST_levelOrder()
{

    queue < Node<T>*> q;
    q.push(root);   //根节点进队列

    while (q.empty() == false)  //队列不为空判断
    {
        cout << q.front()->value << " ";

        if (q.front()->left != nullptr)   //如果有左孩子，leftChild入队列
        {
            q.push(q.front()->left);
        }

        if (q.front()->right != nullptr)   //如果有右孩子，rightChild入队列
        {
            q.push(q.front()->right);
        }
        q.pop();  //已经遍历过的节点出队列
    }

}
```

## 三.测试案例

```c++
int main()
{
	BinarySortTree<int>bst;
	bst.BST_insert(20);
	bst.BST_insert(10);
	bst.BST_insert(30);
	if (bst.BST_search(20) != nullptr)
	{
		cout << "存在该元素" << endl;
	}
	else
		cout << "不存在该元素" << endl;
	cout << "层序遍历" << endl;
	bst.BST_levelOrder();
	cout << endl;
	cout << "前序遍历(递归)" << endl;
	bst.BST_preorderR();
	cout << "前序遍历(非递归)" << endl;
	bst.BST_preorderI();
	cout << "中序遍历(递归)" << endl;
	bst.BST_inorderR();
	cout << "中序遍历(非递归)" << endl;
	bst.BST_inorderI();
	cout << "后序遍历(递归)" << endl;
	bst.BST_postorderR();
	cout << "后序遍历(非递归)" << endl;
	bst.BST_postorderI();

	return 0;
}
```

- ![1619343367765.png](https://img13.360buyimg.com/ddimg/jfs/t1/172059/25/6481/56360/60853842E0d40da49/449392a39376244d.png)

