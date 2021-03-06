package DoublyLinkedList;

import Application.Produto;

/**
 *
 * @author ITALO PIOVAN
 */
public class DoublyLinkedList {
    private No head;
    
    public DoublyLinkedList() {
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
            
            no.setPrev(aux);
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
                No aux = head;
                for (int i = 0; aux != null && i < pos; i++) 
                    aux = aux.getProx();
                
                if(aux != null)
                {
                    if(aux == head)
                    {
                        head = aux.getProx();  
                        head.setPrev(null);
                    }
                    else 
                    {
                        /*if(aux.getProx() == null)
                            aux.getPrev().setProx(aux.getProx());
                        else
                        {
                            aux.getPrev().setProx(aux.getProx());
                            aux.getProx().setPrev(aux.getPrev());
                        }*/
                        aux.getPrev().setProx(aux.getProx());
                        if(aux.getPrev()!= null)
                            aux.getPrev().setProx(aux.getProx());
                    }
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
