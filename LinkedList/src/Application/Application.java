package Application;

import linkedlist.LinkedList;
import DoublyLinkedList.DoublyLinkedList;

/**
 *
 * @author ITALO PIOVAN
 */
public class Application {
    public static void main(String[] args) {
        
        DoublyLinkedList produtos = new DoublyLinkedList();
        //LinkedList produtos = new LinkedList();
        
        
        produtos.insert(new Produto("PRODUTO_1", 10));
        produtos.insert(new Produto("PRODUTO_2", 20));
        produtos.insert(new Produto("PRODUTO_3", 30));
        produtos.insert(new Produto("PRODUTO_4", 40));
        produtos.insert(new Produto("PRODUTO_5", 50));
          
        if(produtos.alter(0, new Produto("PRODUTO_Alterado", 5)))
            System.out.println("Alterado com sucesso.");
        else
            System.out.println("Erro na alteração");
        
        if(produtos.remove(2))
            System.out.println("Removido com sucesso");
        else
            System.out.println("Erro na remoção");
        
        produtos.printAll();
    }  
}
