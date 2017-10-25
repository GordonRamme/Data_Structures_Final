/* 
 * File:   List.h
 * Author: o_o
 *
 * Created on October 8, 2017, 3:42 PM
 */

/*
 * DON'T INCLUDE THIS FILE
 */

#ifndef LIST_H
#define LIST_H

/*
 * List class template emulates the behavior of the STL list class for 
 * C++ but includes a built in iterator for accessing nodes in the list.
 *
 * List is initialized in the following ways
 * List < typename > [identifier]
 * List < typename > [identifier] ( size )
 * 
 * "typename" is the variable type used in the list
 * "size" is the number of nodes to make upon construction
 * 
 * Functions:
 *      Constructor
 *          
 *          List < typename > [identifier]
 *          List < typename > [identifier] ( int size )
 *      
 *      Insert
 *          [identifier].Insert ()
 *          [identifier].Insert ( Container in )
 *          [identifier] << ( Container in )
 *          inserts a node above the iterator
 *          "in" populates the new node
 * 
 *      Delete
 *          [identifier].Delete ()
 *          -[identifier]
 *          deletes the node at the iterator
 *          if the deleted node has children, they are assigned to the
 *          parent node
 * 
 *      Size
 *          [identifier].Resize ( int size )
 *          changes the size of the list
 * 
 *          [identifier].Size ()
 *          returns the size of the list in number of nodes
 * 
 *      Push/Pop
 *          [identifier].Push_front ()
 *          [identifier].Push_front ( Container in )
 *          adds a new node to the front of the list
 *          "in" populates the new node
 * 
 *          [identifier].Push_back ()
 *          [identifier].Push_back ( Container in )
 *          adds a new node to the back of the list
 *          "in" populates the new node
 * 
 *          [identifier].Pop_front ()
 *          returns the value stored in the first node and deletes it
 * 
 *          [identifier].Pop_back ()
 *          returns the value stored in the last node and deletes it
 * 
 *      Accessing
 *          ![identifier]
 *          returns a pointer to the value stored in the node
 * 
 *          ~[identifier]
 *          returns the value stored in the node
 * 
 *          [identifier].Head ()
 *          returns true if the iterator is at the first node
 * 
 *          [identifier].Tail ()
 *          returns true if the iterator is at the last node
 * 
 *      Iterator
 *          [identifier]++
 *          advances the iterator one node
 * 
 *          [identifier]--
 *          retreats the iterator one node
 * 
 *          [identifier][]
 *          moves the iterator to the specified node
 * 
 */

template < typename Container > class List
{
public:
    List ();
    List ( int size );
    ~List ();
    void Insert ();
    void Insert ( Container in );
    void Delete ();
    void Resize ( int size );
    int Size ();
    void Push_front ();
    void Push_front ( Container in );
    void Push_back ();
    void Push_back ( Container in );
    Container Pop_front ();
    Container Pop_back ();
    Container *operator ! ();
    Container operator ~ ();
    void operator ++ ();
    void operator -- ();
    bool Head ();
    bool Tail ();
    void operator << ( Container in );
    void operator - ();
    void operator [] ( int node );
    void init ();
    void init ( Container in );
    
private:
    
    struct node
    {
        Container nodeStorage;
        node *following = 0;
        node *preceding = 0;
    };
    
    int listSize;
    node *head, *tail, *iterator;

};

//class template function definitions go here

template < class Container > List < Container > ::List ()
{
	listSize = 0;

	head = 0;
	tail = 0;
	iterator = head;
}

template < class Container > List < Container > ::~List () {}

template < class Container  > List < Container > ::List ( int size ) 
{
	listSize = size; 
	node *listinit, *previous;
	for ( int i = 0; i < listSize; i ++ )
	{
		if ( i == 0 )
		{
			init ();
		}
		else
		{
			previous = iterator;
			iterator = new node;
			tail = iterator;
			previous -> following = iterator;
			iterator -> preceding = previous;
		}
	}
	iterator = head;
}

template < class Container  > void List < Container > ::Insert ()
{
	if ( listSize == 0 ) 
	{
		init ();
	}
	else
	{
		node *previous, *next;
		previous = iterator -> following;
		iterator = new node;
		iterator -> preceding = previous;
		iterator -> following = next;
		listSize ++;
	}
}

template < class Container > void List < Container > ::Insert ( Container in )
{
	if ( listSize == 0 )
	{
		init ( in );
	}
	else
	{
		node *previous, *next;
		previous = iterator -> preceding;
		next = iterator -> following;
		iterator = new node;
		iterator -> nodeStorage = in;
		iterator -> preceding = previous;
		iterator -> following = next;
		listSize ++;
	}
}template < class Container > void List < Container > ::Delete ()
{
	if ( listSize != 0 )
	{
		node *previous, *next;
		previous = iterator -> preceding;
		next = iterator -> following;
		delete iterator;
		previous -> following = next;
		next -> preceding = previous;
		listSize --;
	}
}

template < class Container > void List < Container > ::Resize ( int size )
{
	if ( listSize == 0 )
	{
		node *previous;
		for ( int i  = 0; i < size; i ++ )
		{
			if ( i == 0 )
			{
				init ();
			}
			else
			{
				previous = tail;
				tail = new node;
				tail -> preceding = previous;
				previous -> following = tail;
				listSize ++;
			}
		}
	}
	if ( listSize > size )
	{
		node *previous;
		for ( int i = 0; i < listSize - size; i ++ )
		{
			previous = tail -> preceding;
			delete tail;
			tail = previous;
		}
		listSize = size;
	}
	else if ( listSize < size )
	{
		node *previous;
		for ( int i = 0; i < size - listSize; i ++ )
		{ 
			previous = tail;
			tail = new node;
			previous -> following = tail;
			tail -> preceding = previous;
		}
		listSize = size;
	}
	else { }
}

template < class Container > int List < Container > ::Size () { return listSize; }

template < class Container > void List < Container > ::Push_front ()
{
	if ( listSize == 0 )
	{
		init ();
	}
	else
	{
		node *next;
		next = head;
		head = new node;
		next -> preceding = head;
		head -> following = next;
		listSize ++;
	}
}
template < class Container > void List < Container > ::Push_front ( Container in )
{
	if ( listSize == 0 )
	{
		init ( in );
	}
	else
	{
		node *next;
		next = head;
		head = new node;
		head -> nodeStorage = in;
		next -> preceding = head;
		head -> following = next;
		listSize ++;
	}
}

template < class Container > void List < Container > ::Push_back ()
{
	if ( listSize == 0 )
	{
		init ();
	}
	else
	{
		node *previous;
		previous = tail;
		tail = new node;
		previous -> following = tail;
		tail -> preceding = previous;
		listSize ++;
	}
}
template < class Container > void List < Container > ::Push_back ( Container in )
{
	if ( listSize == 0 )
	{
		init ( in );
	}
	else
	{
		node *previous;
		previous = tail;
		tail = new node;
		tail -> nodeStoarge = in;
		previous -> following = tail;
		tail -> preceding = previous;
		listSize ++;
	}
}

template < class Container > Container List < Container > ::Pop_front ()
{
	if ( listSize > 0 )
	{
		Container out;
		out = head -> nodeStorage;
		node *next;
		next = head -> following;
		delete head;
		head = next;
		listSize --;
		return out;
	}
}

template < class Container > Container List < Container > ::Pop_back ()
{
	if ( listSize > 0 )
	{
		Container out;
		out = tail -> nodeStorage;
		node *previous;
		previous = tail -> preceding;
		delete tail;
		tail = previous;
		listSize --;
		return out;
	}
}

template < class Container > Container* List < Container > ::operator ! ()
{
	Container *out;
	out = &iterator -> nodeStorage;
	return out;
}

template < class Container > Container List < Container > ::operator ~ ()
{
	Container out;
	out = iterator -> nodeStorage;
	return out;
}

template < class Container > void List < Container > ::operator ++ ( int ) 
{ iterator = iterator -> following; }

template < class Container > void List < Container > ::operator -- ( int ) 
{ iterator = iterator -> preceding; }

template < class Container > bool List < Container > ::Head ()
{
	if ( iterator == head )
	{
		return true;
	}
	else
	{
		return false;
	}
}

template < class Container > bool List < Container > ::Tail ()
{
	if ( iterator == tail )
	{
		return true;
	}
	else
	{
		return false;
	}
}

template < class Container > void List < Container > ::operator << ( Container in )
{
	node *previous, *next;
	if ( listSize == 0 )
	{
		init ( in );
	}
	else if ( iterator == head ) 
	{
		next = head;
		head = new node;
		head -> nodeStorage = in;
		head -> following = next;
		next -> preceding = head;
		iterator = head;
		listSize ++;
	}
	else if ( iterator == tail )
	{
		previous = tail;
		tail = new node;
		tail -> nodeStorage = in;
		previous -> following = tail;
		tail -> preceding = previous;
		iterator = tail;
		listSize ++;
	}
	else
	{
		next = iterator;
		iterator -> preceding = previous;
		iterator = new node;
		iterator -> nodeStorage = in;
		next -> preceding = iterator; 
		previous -> following = iterator;
		listSize ++;
	}
}

template < class Container > void List < Container > ::operator - ()
{
	node *next;
	next = head -> following;
	delete head;
	head = next;
	listSize --;
}

template < class Container > void List < Container > ::operator [] ( int node )
{
	iterator = head;
	for ( int i = 0; i < node; i ++ )
	{
		iterator = iterator -> following;
	}
}

template < class Container > void List < Container > ::init ()
{
	iterator = new node;
	head = iterator;
	tail = iterator;
	listSize ++;
}

template < class Container > void List < Container > ::init ( Container in )
{
	iterator = new node;
	iterator -> nodeStorage = in;
	head = iterator;
	tail = iterator;
	listSize ++;
}

#endif /* LIST_H */

