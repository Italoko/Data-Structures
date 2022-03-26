package DoublyLinkedListWithDescritor;

/**
 *
 * @author ITALO PIOVAN
 */
public class Descritor {
    
    private No start;
    private No end;
    private int size;
    
    public Descritor(){
        start = null;
        end = null;
        size = 0;
    }

    public No getStart() {
        return start;
    }

    public void setStart(No start) {
        this.start = start;
    }

    public No getEnd() {
        return end;
    }

    public void setEnd(No end) {
        this.end = end;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int op) {
        size = size + op;
    } 
}
