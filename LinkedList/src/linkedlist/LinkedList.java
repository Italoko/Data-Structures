package linkedlist;

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
        
        No aux = searchNo(pos);
        if(aux != null)
        {
            aux.setData(data);
            return true;
        }
        return false;
    }
    
    public boolean remove(int pos){
    
        No aux = searchNo(pos-1);
        if(aux != null)
        {
            aux.setProx(aux.getProx().getProx());
            return true;
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
    
    private No searchNo(int pos){
        
        No aux = head;
        for (int i = 0; aux != null && i < pos ; aux = aux.getProx(),i++) {}
      
        return aux;
    }
}
