package DoublyLinkedListWithDescritor;

import Application.Produto;

/**
 *
 * @author ITALO PIOVAN
 */
public class DoublyLinkedListDescritor {
    
    private  Descritor descritor;
    
    public DoublyLinkedListDescritor() {
        descritor = new Descritor();
    }
    
    public void insert(Object data){
        
        No no = new No();
        no.setData(data);
        
        if(descritor.getSize() == 0)
        {
            descritor.setStart(no);
            descritor.setEnd(no);
        }
        else
        {
            descritor.getEnd().setProx(no);
            no.setPrev(descritor.getEnd());
            descritor.setEnd(no);
        }
        descritor.setSize(1);
    }
    
    public boolean alter(int pos, Object data){
        
        No aux = descritor.getStart();
        
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
        
        if(descritor.getSize() > 0)
        {
            if(descritor.getSize() == 1)
            {
                descritor.setStart(null);
                descritor.setEnd(null);
            }
            else
            {
                No aux = descritor.getStart();
                for (int i = 0; aux != null && i < pos; i++) 
                    aux = aux.getProx();
                
                if(aux != null)
                {
                    if(aux == descritor.getStart())
                    {
                        descritor.setStart(aux.getProx());
                        descritor.getStart().setPrev(null);
                    }
                    else 
                    {   
                        if(aux == descritor.getEnd())
                        {
                            descritor.setEnd(aux.getPrev());
                            descritor.getEnd().setProx(null);
                        }
                        else
                        {
                            aux.getPrev().setProx(aux.getProx());
                            aux.getProx().setPrev(aux.getPrev());
                        }
                    }
                    descritor.setSize(-1);
                    return true;
                }
            }    
        }
        return false;
    } 
       
    public void printAll(){
        
        No aux = descritor.getStart();
        while(aux != null)
        {
            Produto prod = (Produto) aux.getData();
            System.out.println("Produto: " + prod.getName() + " Quantidade: " + prod.getQuantity());
            
            aux = aux.getProx();
        }
    }
    
    public int getSize(){
        return descritor.getSize();
    }
}
