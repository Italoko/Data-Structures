package linkedlist;

import Application.Produto;

/**
 *
 * @author ITALO PIOVAN
 */
public class LinkedList {
    private No head;
    
    public LinkedList() {
        head = null;
    }
    
    public No getHead() {
        return head;
    }
    
    public void insert(Object data){
        
        No no = new No();
        no.setData(data);
        
        if(head == null)
            head = no;           
        else
        {
            No aux = head;
            while(aux.getProx() != null)
                aux = aux.getProx();
            
            aux.setProx(no);
        }
    }
    
    public boolean alter(int pos, Object data){
        
        No aux = head;
        for (int i = 0; aux != null && i < pos; i++) 
            aux = aux.getProx();
        
        if(aux != null)
        {
            aux.setData(data);
            return true;
        }
        return false;
    }
    
    public boolean remove(int pos){

        if(head != null)
        {
            if(head.getProx() == null)
                head = null;
            else
            {
                No ant = head;
                No aux = head;
                for (int i = 0; aux != null && i < pos; i++)
                {
                    ant = aux;
                    aux = aux.getProx();
                }
                if(aux != null)
                {
                    ant.setProx(aux.getProx());   
                    return true;
                }  
            } 
        }
        return false;
    }
    
    public void printAll(){
        
        No aux = head;
        while(aux != null)
        {
            Produto prod = (Produto) aux.getData();
            System.out.println("Produto: " + prod.getName() + " Quantidade: " + prod.getQuantity());
            
            aux = aux.getProx();
        }
    }
}
