package linkedlist;

/**
 *
 * @author ITALO PIOVAN
 */
public class No {
    
    private Object data;
    private No prox;
    
    public No(){
        data = null;
        prox = null;
    }

    public Object getData() {
        return data;
    }

    public void setData(Object data) {
        this.data = data;
    }

    public No getProx() {
        return prox;
    }

    public void setProx(No prox) {
        this.prox = prox;
    }
}
