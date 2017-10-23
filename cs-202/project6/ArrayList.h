#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "DataType.h"

class ArrayList{
  public:
    ArrayList();							//(1)
    ArrayList(int size, const DataType& value);				//(2)
    ArrayList(const ArrayList& other);				    	//(3)
    ~ArrayList();							//(4)

    ArrayList& operator= (const ArrayList& other_arrayList);		//(5)
    friend std::ostream& operator<<(std::ostream& os,			//(6)
				    const ArrayList& arrayList); 

    DataType* first();							//(7a)
    const DataType* first() const;				        //(7b)
	
    DataType* last();						        //(8a)
    const DataType* last() const;					//(8b)
	
    DataType* find(const DataType& target,			        //(9a)
                   DataType* &previous);
    const DataType* find(const DataType& target,		        //(9b)
		 	 const DataType* &previous) const;	
	
    DataType* insertAfter(const DataType& target,               	//(10)
                          const DataType& value, int count=1);	    
    DataType* insertBefore(const DataType& target,              	//(11)
                           const DataType& value, int count=1);
    DataType* removeForward(const DataType& target,		    	//(12)
                            int count=1);   
    DataType* removeBackward(const DataType& target,            	//(13)
                             int count=1);   
	
    DataType& operator[] (int position);				//(14a)
    const DataType& operator[] (int position) const;		   	//(14b)
    
    int size() const;							//(15)
    bool empty() const;						  	//(16)
    void clear();							//(17)	

  private:
    void grow(int addsize);						//(18)
    void trim();							//(19)

    DataType *m_array;
    int m_size;
    int m_maxsize;
};

#endif
