//
//  AVL.h
//  ActIntegral3
//
//  Created by Israel Arroyo on 31/10/20.
//

#ifndef AVL_h
#define AVL_h

#include <sstream>
#include <vector>
#include <math.h>
#include <cmath>

#include "Location.h"
#include "Node.h"
#include "Splay.h"


class Avl : public SplayTree
{
public:
    Location find(int);
    void remove(Location);
    void add(Location);
    void check(Node*);
    void balance(Node*);
};

void Avl::check(Node* source)
{
    /*
     Precondition: arbol valido
     Postcontidion: arbol balanceado o nada
     Input: nodo comienzo a checar
     Output:
     */
    if(!source||!source->left||!source->right)
        return;
    int balanceFactor = (source->left->height()) - (source->right->height());
    if(balanceFactor>1||balanceFactor<-1)
    {
        balance(source);
    }
    if(!source->parent)
        return;
    check(source->parent);
    
}
void Avl::balance(Node* source)
{
    /*
     Precondition: arbol desbalanceado
     Postcontidion: arbol balanceado
     Input: nodo a balancear
     Output:
     */
    int bf = (source->left->height()) - (source->right->height());
    if(bf>0)//cargado a la izquierda
    {
        if(source->left->left->height() > source->left->right->height())
            rightRot(source);
        else // source->left->left->height() < source->left->right->height()
        {
            leftRot(source->left);
            rightRot(source);
        }
    }
    if(bf<0)//cargado a la derecha
    {
        
        if(source->right->right->height() > source->left->right->height())
            leftRot(source);
        else 
        {
            rightRot(source->left);
            leftRot(source);
        }
    }
    
    if(!source->parent)
        root = source;
}
void Avl::add(Location source)
{
    /*
     Precondition: arbol valido
     Postcontidion: arbol modificado
     Input: objeto a añadir
     Output:
     */
    if (root)
    {
        Node* aux=root->add(source);
        check(aux);
    }
    else
        root = new Node(source);
    
    
}

Location Avl::find(int dis)
{
    /*
     Precondition: arbol valido
     Postcontidion:
     Input: entero a buscar
     Output: objeto encontrado
     */
    
    Location fail;
    if (root)
    {
        Node* aux = root->find(dis);
        
        if(aux)
            return aux->value;
        else
            return fail;
    }
    return fail;
}


void Avl::remove(Location source)
{
    /*
     Precondition: arbol valido
     Postcontidion: arbol modificado
     Input: objeto a eliminar
     Output:
     */
    
    int val = source.getDistance();
    
    if (root)
    {
        if (val == root->value.getDistance())
        {
            Node *succ = root->predecesor();
            if (succ != 0)
            {
                succ->left = root->left;
                succ->right = root->right;
                succ->parent=0;
                if(succ->left)
                    succ->left->parent=succ;
                if(succ->right)
                    succ->right->parent=succ;
            }
            delete root;
            root = succ;
        }
        else
        {
            Node*p = root->remove(source);
            check(p);
        }
    }

}

#endif /* AVL_h */
