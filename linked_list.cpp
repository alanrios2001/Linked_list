#include <iostream>
using namespace std;

class Lista {

    typedef struct Node {
        int dado;
        struct Node* prox;
    }Node;

    Node* l;
    int n_elems = 0;

public:

    Lista() {
        l = NULL;
    }

    void display(void) {
        Node* head = l;
        cout << "[";
        while (head != NULL) {
            if (head->prox == NULL) {
                cout << head->dado;
                break;
            }
            else {
                cout << head->dado << ",";
            }
            head = head->prox;
        }
        cout << "]" << endl;
    }

    bool consulta(int num) {
        if (n_elems == 0) {
            return false;
        }

        Node* head = l;
        while (head != NULL && head->dado != num) {
            head = head->prox;
        }
        if (head != NULL) {
            return true;
        }
        return false;
    }

    bool insert(int num) {
        
        //caso não existam elementos na lista, não há necessidade de buscar elemento
        if (n_elems == 0) {
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->dado = num;
            new_node->prox = l;
            l = new_node;
            n_elems += 1;
            return true;
        }
        //caso exista mais de um elemento, busca elemento
        else if (consulta(num) == false) {
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->dado = num;
            new_node->prox = l;
            l = new_node;
            n_elems += 1;
            return true;
        }
        return false;

    }

    bool remove(int num) {
        Node* head = l;
        Node* head_ant = NULL;

        //busca elemento e salva elemento anterior
        while (head != NULL && head->dado != num) {
            head_ant = head;
            head = head->prox;
        }

        //não encontrou o elemento
        if (head == NULL) {
            return false;
        }

        //lista com somente um elemento encontrado
        else if (head_ant == NULL) {
            l = head->prox;
            n_elems -= 1;
        }
        //lista com mais de um elemento
        else {
            head_ant->prox = head->prox;
            head = l;
            while (head != head_ant) {
                head->prox = head_ant;
                head = head->prox;
            }
            n_elems -= 1;
        }
        return true;
    }

    void len(void) {
        cout << n_elems << endl;
    }
    
    
};
int main() {

}
