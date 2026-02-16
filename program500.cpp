////////////////////////////////////////////////////////////////
//
// Generalised Data Structure Library
//
////////////////////////////////////////////////////////////////

/*
------------------------------------------------------------------------------------------------------------------------
Type                    Name of class for node                  Name of class for Functionality
------------------------------------------------------------------------------------------------------------------------
Singly Linear           SinglyLLLnode                           SinglyLLL                               Done
Singly Circular         SinglyCLLnode                           SinglyCLL                               Done
Doubly Linear           DoublyLLLnode                           DoublyLLL                               Done
Doubly Circular         DoublyCLLnode                           DoublyCLL                               Done
Stack                   Stacknode                               Stack                                   Done
Queue                   Queuenode                               Queue                                   Done
------------------------------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Singly Linked List using Generic Approach
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode
{
    public :
        T data;
        SinglyLLLnode <T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyLLL
{
    private:                            
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

template <class T>
SinglyLLL<T>::SinglyLLL()
{
    cout<<"Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertFirst
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to insert node at first Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertFirst(T no)    
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertLast
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to insert node at Last Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)     
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteFirst
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Delete node at first Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)    
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteLast
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Delete node at Last Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)    
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Display
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Display node 
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::Display()
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)   
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Count
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Count node
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLLL<T>::Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertAtPos
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to insert node at Given Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteAtPos
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Delete node at Given Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Doubly Linked List using Generic Approach
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public :
        T data;
        DoublyLLLnode * prev;
        DoublyLLLnode * next;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyLLL 
{
    private :
        DoublyLLLnode<T> *first;
        int iCount;

    public :
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        
        void Display();
        int Count();
};

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked List Gets Created\n";
    
    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertFirst
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to insert node at first Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T>* newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertLast
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to insert node at Last Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T>* newn = NULL;
    DoublyLLLnode<T>* temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertAtPos
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to insert node at Given Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> * temp = NULL;
    DoublyLLLnode<T> * newn = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount + 1))
    {
        cout<<"Invalide Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);
        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;

        newn->next->prev = newn;
        temp->next = newn;

        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteFirst
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Delele node at first Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)                     
    {
        return;
    }
    else if(this->first->next == NULL)          
    {
        delete this->first;
        this->first = NULL;
    }
    else                                        
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteLast
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Delete node at Last Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> * temp = NULL;

    if(this->first == NULL)                     
    {
        return;
    }
    else if(this->first->next == NULL)          
    {
        delete this->first;
        this->first = NULL;
    }
    else                                        
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteAtPos
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Delete node at Given Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalide Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        
        this->iCount--;
    }   
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Display
//  Input   :           Nothing
//  Output  :           Nothing
//  Description :       Used to Display node
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    cout<<"\nNULL <=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Count
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Count nodes 
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Doubly Circular Linked List using Generic Approach
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyCLLnode
{
    public :
        T data;
        DoublyCLLnode * next;
        DoublyCLLnode * prev;

    DoublyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

template<class T>
class DoublyCLL
{
    private : 
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;

    public :
        DoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Inside Constructer of DoublyCLL\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertFirst
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Insert nodes first position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertLast
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to insert node at Last Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> *newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = last;
        last = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteFirst
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Delete node at first Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {   
        this->first = this->first->next;
        delete this->first->prev;

        this->first->prev = this->last;
        this->last->next = this->first;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteLast
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Delete node at Last Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;

        this->last->next = this->first;
        this->first->prev = this->last;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertAtPos
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to insert node at Given Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *newn = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteAtPos
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Delete node at Given Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *target = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;

        delete target;
        this->iCount--;
    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Display
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Display node
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::Display()
{
    if(this->first == NULL)
    {
        return;
    }

    DoublyCLLnode<T> *temp = this->first;

    cout<<"<=>";
    do
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }while(temp != this->first);
    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Count
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Count node
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCLL<T>::Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Singly Circular Linked List using Generic Approach
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyCLLnode
{
    public :
        T data;
        SinglyCLLnode<T> * next;

    SinglyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template<class T>
class SinglyCLL
{
    private :
        SinglyCLLnode<T> *first;
        SinglyCLLnode<T> *last;
        int iCount;

    public :
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int); 
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertFirst
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to insert node at first Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside Constructer of SinglyCLL\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = NULL;
    
    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
        this->last->next = this->first;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
        this->last->next = this->first;   
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertLast
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to insert node at Last Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
        this->last->next = this->first;  
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
        this->last->next = this->first;
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteFirst
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Delete node at first Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->last->next;
        this->last->next = this->first;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteLast
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Delete node at Last Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next != this->last)
        {
            temp = temp->next;
        }
        delete this->last;
        this->last = temp;
        this->last->next = this->first;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Display
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Display node 
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::Display()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }

    SinglyCLLnode<T> *temp = NULL;

    temp = this->first;

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }while(temp != this->last->next);
    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Count
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Count nodes
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertAtPos
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to insert node at Given Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *newn = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteAtPos
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Delete node at Given Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           06-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *target = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Stack Using Generic Approach
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class stacknode
{
    public :
        T data;
        stacknode<T>*next;

        stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class stack
{
    private :
        stacknode<T> *first;
        int iCount;

    public :
        stack();
        void push(T);             
        T pop();                
        T peep();
        void Display();
        int Count();
};

template<class T>
stack<T> :: stack()
{
    cout<<"Stack gets created Succefully...\n";

    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Push
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to insert node at first Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           07-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void stack<T> :: push(T no)
{
    stacknode<T> *newn = NULL;

    newn = new stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   pop
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Delete node at Last Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           07-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T stack<T> :: pop()
{
    T Value = 0;
    stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"stack is Empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   peep
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       used to view the top element of a stack without removing it
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           07-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"stack is Empty\n";
        return -1;
    }

    Value = this->first->data;
    return Value;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Display
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Display nodes
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           07-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void stack<T> :: Display()
{
    stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Count
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Count nodes
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           07-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int stack<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Queue using Generic Approach
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Queuenode
{
    public :
        T data;
        Queuenode<T> *next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Queue
{
    private :
        Queuenode<T> *first;
        Queuenode<T> *last;
        int iCount;

    public :
        Queue();
        void enqueue(T);             
        T dequeue();                 
        void Display();
        int Count();
};

template<class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created Succefully...\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   enqueuue
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Insert node at Last Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           07-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T> *newn = NULL;

    newn = new Queuenode<T>(no);
    
    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   dequeue
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Delete node at First Position
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           07-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is Empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Display
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Display nodes
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           07-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T>:: Display()
{
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }

    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Count
//  Input   :           Data of node
//  Output  :           Nothing
//  Description :       Used to Count nodes
//  Auther  :           Sanyam BhupendraKumar Ravne
//  Date    :           07-01-2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int Queue<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////// End of Library ////////////////////////////////////////////////////////////////

int main()
{
    SinglyLLL<int> *obj = new SinglyLLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);
    
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->DeleteFirst();
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->DeleteLast();

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->InsertAtPos(105,4);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->DeleteAtPos(4);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    delete obj; 

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();
    
    cout<<"NUmber of Elements are : "<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();
    
    cout<<"NUmber of Elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();

    dobj->Display();
    
    cout<<"NUmber of Elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteLast();

    dobj->Display();
    
    cout<<"NUmber of Elements are : "<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$', 4);

    dobj->Display();
    
    cout<<"NUmber of Elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);

    dobj->Display();
    
    cout<<"NUmber of Elements are : "<<dobj->Count()<<"\n";

    delete dobj;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    DoublyCLL<int> *dcobj = new DoublyCLL<int>();

    dcobj->InsertFirst(51);
    dcobj->InsertFirst(21);
    dcobj->InsertFirst(11);

    dcobj->Display();

    iRet = dcobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dcobj->InsertLast(101);
    dcobj->InsertLast(111);
    dcobj->InsertLast(121);
    
    dcobj->Display();

    iRet = dcobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    dcobj->DeleteFirst();
    dcobj->Display();

    iRet = dcobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    dcobj->DeleteLast();

    dcobj->Display();

    iRet = dcobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    dcobj->InsertAtPos(105,4);

    dcobj->Display();

    iRet = dcobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    dcobj->DeleteAtPos(4);

    dcobj->Display();

    iRet = dcobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    delete dcobj; 

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    SinglyCLL<int> *scobj = new SinglyCLL<int>();

    scobj->InsertFirst(51);
    scobj->InsertFirst(21);
    scobj->InsertFirst(11);

    scobj->Display();

    iRet = scobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    scobj->InsertLast(101);
    scobj->InsertLast(111);
    scobj->InsertLast(121);
    
    scobj->Display();

    iRet = scobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    scobj->DeleteFirst();
    scobj->Display();

    iRet = scobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    scobj->DeleteLast();

    scobj->Display();

    iRet = scobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    scobj->InsertAtPos(105,4);

    scobj->Display();

    iRet = scobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    scobj->DeleteAtPos(4);

    scobj->Display();

    iRet = scobj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    delete scobj;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    stack<char> *sobj = new stack<char>();

    sobj->push('a');
    sobj->push('b');
    sobj->push('c');
    sobj->push('d');

    sobj->Display();
    cout<<"Number of Elements int Stack Are : "<<sobj->Count()<<"\n";

    cout<<"Return Value of Peep is : "<<sobj->peep()<<"\n";
    
    sobj->Display();
    cout<<"Number of Elements int Stack Are : "<<sobj->Count()<<"\n";

    cout<<"Poped Element is : "<<sobj->pop()<<"\n";

    sobj->Display();
    cout<<"Number of Elements int Stack Are : "<<sobj->Count()<<"\n";

    cout<<"Poped Element is : "<<sobj->pop()<<"\n";

    sobj->Display();
    cout<<"Number of Elements int Stack Are : "<<sobj->Count()<<"\n";

    sobj->push('e');

    sobj->Display();
    cout<<"Number of Elements int Stack Are : "<<sobj->Count()<<"\n";
    
    delete sobj;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.54685);
    qobj->enqueue(21.54685);
    qobj->enqueue(51.54685);
    qobj->enqueue(101.54685);

    qobj->Display();
    cout<<"Number of Elements int Queue Are : "<<qobj->Count()<<"\n";

    cout<<"Removed Element is : "<<qobj->dequeue()<<"\n";

    qobj->Display();
    cout<<"Number of Elements int Queue Are : "<<qobj->Count()<<"\n";

    cout<<"Removed Element is : "<<qobj->dequeue()<<"\n";

    qobj->Display();
    cout<<"Number of Elements int Queue Are : "<<qobj->Count()<<"\n";

    qobj->enqueue(121.54685);

    qobj->Display();
    cout<<"Number of Elements int Queue Are : "<<qobj->Count()<<"\n";
    
    delete qobj;

    return 0;
}