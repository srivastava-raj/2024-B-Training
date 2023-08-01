package Implementation.LinkedList;


class LinkedList_Doubly{
	
	class Node{
		int data;
		Node prev;
		Node next;
		
		public Node(int data) {
			this.data = data;
			this.prev = null;
			this.next = null;
		}
	}
	
	Node head = null;
	Node tail = null;
	
/**************************************************************************/
	
	void insertBeginning(int data)
	{
		Node n = new Node(data);
		
		if(head==null)
		{
			head = n;
			tail = n;
		}
		else
		{
			n.next = head;
			head.prev = n;
			head = n;
		}
	}
	
	void insertEnd(int data)
	{
		Node n = new Node(data);
		if(head == null)
		{
			head = n;
			tail = n;
		}
		else
		{
			tail.next = n;
			n.prev = tail;
			tail = n;
		}
	}
	
	void insertIndex(int data, int index)
	{
		Node n = new Node(data);
		if(index<0)
		{
			System.out.println("Enter inidex >= 0");
			return ;
		}
		if(index == 0)
		{
			insertBeginning(data);
			return;
		}
		Node temp = head;
		while(index>1 && temp.next!=null)
		{
			index--;
			temp = temp.next;
		}
		if(temp.next==null)
		{
			insertEnd(data);
			return;
		}
		if(index==1)
		{
			n.next = temp.next;
			n.prev = temp;
			if(temp.next!=null)
				temp.next.prev = n;
			temp.next = n;
		}
		else
			System.out.println("Enter index < size");
	}
	
/******************************************************************************************/
	
	int deleteFront()
	{
		if(head == null)
		{
			System.out.println("Empty LL");
			return -1;
		}
		Node temp = head;
		head = head.next;
		temp.next = null;
		if(head!=null)
			head.prev = null;
		if(head==null)
			tail = null;
		return temp.data;
	}
	
	int deleteEnd()
	{
		if(tail==null)
		{
			System.out.println("Empty LL");
			return -1;
		}
		Node temp = tail;
		tail = tail.prev;
		temp.prev = null;
		if(tail!=null)
			tail.next=null;
		if(tail==null)
			head = null;
		return temp.data;
	}
	
	int deleteIndex(int index)
	{
		if(index<0)
			System.out.println("enter index >= 0");
		
		if(index==0)
			return deleteFront();
		
		int i=0;
		Node temp = head;
		Node prev=null;
		while(i!=index && temp.next!=null)
		{
			i++;
			prev = temp;
			temp = temp.next;
		}
		if(i!=index)
		{
			System.out.println("enter index <= LL size");
			return -1;
		}
		prev.next = temp.next;
		if(temp.next==null)
			tail = prev;
		if(temp.next!=null)
			temp.next.prev = prev;
		return temp.data;
	}
	
/**********************************************************************/
	
	void traverseFront()
	{
		Node temp = head;
		while(temp!=null)
		{
			System.out.print(temp.data + "->");
			temp = temp.next;
		}
		System.out.println();
	}
	
	void traverseBack()
	{
		Node temp = tail;
		while(temp!=null)
		{
			System.out.print(temp.data + "<-");
			temp = temp.prev;
		}
		System.out.println();
	}
}

/***************************************************************************************/

public class Doubly_LL {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		LinkedList_Doubly ll = new LinkedList_Doubly();
		
		ll.insertBeginning(0);
		ll.insertBeginning(1);
		ll.insertBeginning(2);
		ll.insertBeginning(3);
		ll.insertBeginning(4);
		
		ll.insertEnd(0);
		ll.insertEnd(10);
		
		ll.insertIndex(0, 2);
		
		ll.deleteEnd();
		
		ll.deleteFront();
		
		ll.deleteIndex(2);
		ll.deleteIndex(4);
//		ll.deleteIndex(4);
		
		ll.traverseFront();
		ll.traverseBack();
		

	}

}
