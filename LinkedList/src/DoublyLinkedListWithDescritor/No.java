package DoublyLinkedListWithDescritor;

/**
 *
 * @author ITALO PIOVAN
 */
public class No {
    
    private Object data;
    private No prev;
    private No prox;
    
    public No(){
        data = null;
        prev = null;
        prox = null;
    }

    public Object getData() {
        return data;
    }

    public void setData(Object data) {
        this.data = data;
    }
    
    public No getPrev() {
        return prev;
    }

    public void setPrev(No prev) {
        this.prev = prev;
    }

    public No getProx() {
        return prox;
    }

    public void setProx(No prox) {
        this.prox = prox;
    }
}
