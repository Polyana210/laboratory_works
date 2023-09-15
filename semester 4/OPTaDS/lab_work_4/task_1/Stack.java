package org.example;

public class Stack {
    StackNode top;
    Stack(){
        this.top=null;
    }

    public void push(String str){
        StackNode temp = new StackNode();
        temp.data = str;
        temp.link = top;
        top = temp;
    }

    public boolean isEmpty(){
        return top==null;
    }

    public String peek(){
        if(!isEmpty()) return top.data;
        else{
            System.out.println("Stack is empty");
            return "";
        }
    }

    public void pop(){
        if (top==null){
            System.out.println("Stack Underflow");
            return;
        }

        top=(top).link;
    }

    public void display(){
        if (top==null){
            System.out.println("Stack Underflow");
            return;}
        else{
            StackNode temp = top;
            while (temp!=null){
                System.out.print(temp.data);
                temp = temp.link;
                if(temp!=null) System.out.print(" -> ");
            }
            System.out.println();
        }


    }


}
