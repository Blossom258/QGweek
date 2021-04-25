//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H
#include<iostream>
#include<stack>
#include<queue>
using std::cout;
using std::cin;
using std::endl;
using std::stack;
using std::queue;


//typedef int ElemType;
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


template <class T>
BinarySortTree<T>::BinarySortTree()
{
    this->root = nullptr;
}

template <class T>
BinarySortTree<T>::~BinarySortTree()
{
    destroy(root);
   
}


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


    else if (p->left != nullptr && p->right != nullptr)
    {
        Node<T>* pParent = getParent(p);
        Node<T>* pPre = p->left;
        Node<T>* ptmp = pPre;
        while (pPre->right != nullptr)
        {
            ptmp = pPre;
            pPre = pPre->right;
        }
        if (ptmp != pPre)
        {
            ptmp->right = pPre->left;
            pPre->left = p->left;
            pPre->right = p->right;
        }
        else
            pPre->right = p->right;

        if (pParent == nullptr)
            root = pPre;
        else
            if (pParent->left == p)
                pParent->left = pPre;
            else
                pParent->right = pPre;

        delete p;
        p = nullptr;
        return true;

    }
    return true;
}


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

void menu();
#endif

