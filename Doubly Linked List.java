package Rohit;
import java.util.Scanner;

//import java.nio.file.AccessDeniedException;

public class DoubleLinkedList {
    class Node{
        int data;
        Node previous;
        Node next;

        public Node(int data){
            this.data=data;
     }
    }
    
Node head,tail=null;

public void addNode(int data){

    Node newNode=new Node(data);
    if(head==null){
        head=tail=newNode;
        head.previous=null;

        tail.next=null;
    }
    else{
        tail.next=newNode;

        newNode.previous=tail;

        tail=newNode;

        tail.next=null;
    }
}  
    
public void display(){
    Node current=head;
    if(head==null){
        System.out.println("List is empty");
        return;
    }
    System.out.println("Nodes of Doubly Linked List :");
        while(current!=null){
            System.out.println(current.data+"->");
            current=current.next;

        }    
}
    public static void main(String[] args){
     int n=0;
     int a=0;

     System.out.println("Enter tHE Numbers to be input:");  
     Scanner input=new Scanner(System.in);
     a=input.nextInt();
//        System.out.println("Enter tHE Numbers to be input:");        

        DoubleLinkedList dList=new DoubleLinkedList();
        
        for(int i=1;i<=a;i++){
            System.out.print(i +"th Index ");
            n=input.nextInt();
            dList.addNode(n);
        
    }
          //  dList.addNode(5);
            
            dList.display();
    }

}
