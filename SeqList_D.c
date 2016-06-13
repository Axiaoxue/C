#include "SeqList_D.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void InitPseqList(pSeqList pSeq)
{
	assert(pSeq);
	pSeq->data = malloc((sizeof(DataType)* 5));
	pSeq->_capacity =5;
	pSeq->_size = 0;
	
}
void CheckCapacity(pSeqList pSeq)
{
	
	if (pSeq->_capacity ==  pSeq->_size)
	{
	   DataType * tmp = (DataType *)realloc(pSeq->data,sizeof(DataType)*(pSeq->_capacity*2+3));	
	   if (tmp == NULL)
	   {
		  return;
	   }
	  else
		{
			pSeq->data = tmp;
			pSeq->_capacity = pSeq->_capacity * 2 + 3;
		}
	}
	
}
void PushBack(pSeqList pSeq, DataType x)
{
	CheckCapacity(pSeq);
	pSeq->data[pSeq->_size] = x;
	pSeq->_size++;
}
void PrintfList(pSeqList pSeq)
{
	int i = 0;
	for (i = 0; i < pSeq->_size; i++)
	{
		printf("%d ", pSeq->data[i]);
	}
}
void PopBack(pSeqList pSeq)
{
	//int m = pSeq->_size;
	//if (m != 0)
	//{
	//	int i = 0;
	//	int j = m - 1;
	//	for (i = 0; i < m - 1; i++)
	//	{
	//		
	//		while(j)
	//		{
	//			pSeq->data[j] = pSeq->data[j-1];
	//			j--;
	//		}
	//	}
	//}
	pSeq->_size--;
}
void PopFront(pSeqList pSeq)
{
	int sz = pSeq->_size;
		int i = 0;
		for (i = 0; i < sz - 1; i++)
		{
			pSeq->data[i] = pSeq->data[i + 1];
		}
		pSeq->_size--;
}
void PushFront(pSeqList pSeq,DataType x)
{
	CheckCapacity(pSeq);
	pSeq->_size++;
	int sz = pSeq->_size;
	int i = 0;
	for (i = sz-1; i>0; i--)
	{
		pSeq->data[i+1] = pSeq->data[i];
	}
	pSeq->data[0] = x;
}
void Remove(pSeqList pSeq, DataType x)
{
	int sz = pSeq->_size;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		if(pSeq->data[i] == x)
		{
			int j = 0;
			for (j = i; j < sz; j++)
			{			
			pSeq->data[j] = pSeq->data[j + 1];
			}
			pSeq->_size--;
		}
	}
}
void RemoveAll(pSeqList pSeq, DataType x)
{
	int sz = pSeq->_size;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		while(pSeq->data[i] == x)
		{
			int j = 0;
			for (j = i; j < sz; j++)
			{
				pSeq->data[j] = pSeq->data[j + 1];
			}
			pSeq->_size--;
		}
	}
}
void DestoryList(pSeqList pSeq)
{
	pSeq->_size = 0;
}
void BubbleSort(pSeqList pSeq)
{
	int sz = pSeq->_size;
	int i = 0;
	int j = 0;
	for (i = 0; i < sz-1; i++)
	{
		for (j = 0; j<sz -1-i; j++)
		{
			if (pSeq->data[j]>pSeq->data[j + 1])
			{
				DataType tmp = pSeq->data[j];
				pSeq->data[j] = pSeq->data[j + 1];
				pSeq->data[j + 1] = tmp;
			}
		}
	}
}
void BinarySearch(pSeqList pSeq, DataType x)//ÓÐÎÊÌâ
{
	int sz = pSeq->_size;
	int l = 0;
	int r = sz-1;
	
	while (l <= r)
	{
		int mid = (l+r) / 2;
		if (pSeq->data[mid] == x)
		{
			return pSeq->data[mid];
		}
		if (pSeq->data[mid] < x)
		{
			l = mid-1;
		}
		if (pSeq->data[mid]>x)
		{
			r = mid+1;
		}

	}
}
void SelectSort(pSeqList pSeq)
{
	int sz = pSeq->_size;
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = i + 1; j < sz - 1; j++)
		{
			int tmp = 0;
			if (pSeq->data[i]>pSeq->data[j])
			{
				tmp = pSeq->data[i];
				pSeq->data[i] = pSeq->data[j];
				pSeq->data[j] = tmp;
			}
		}
	}
}
void Erase(pSeqList pSeq, int pos)
{
	int sz = pSeq->_size;
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		if (i = pos)
		{
			int j = 0;
			for (j = i; j < sz - 1; j++)
			{
				pSeq->data[j] = pSeq->data[j + 1];
			}
			pSeq->_size--;
			break;
		}
	}
}