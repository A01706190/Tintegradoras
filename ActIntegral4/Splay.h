//
//  Splay.h
//  ActIntegral3
//
//  Created by Israel Arroyo on 31/10/20.
//

#ifndef Splay_h
#define Splay_h

#include <sstream>
#include <vector>
#include <math.h>
#include <cmath>

#include "Location.h"
#include "Node.h"


class SplayTree
{
public:
    SplayTree();
    void Splay(Node*);
    void rightRot(Node*);
    void leftRot(Node*);
    virtual bool find(Location);
    virtual void remove(Location);
    virtual void add(Location);
    std::string inorder() const;
    std::string inorderList() const;
    std::string inorderListDistance() const;
    std::string preorder() const;
    bool empty();
protected:
    Node* root;
};

SplayTree::SplayTree(): root(0){}
bool SplayTree::empty()
{
    if(root)
        return false;
    return true;
}

void SplayTree::Splay(Node* source)
{
    /*
     Precondition: arbol valido
     Postcontidion: input como raiz de arbol
     Input: nodo a desplegar
     Output:
     */

    if(!root)
        return;

    while(source->parent)
    {
        Node* grandparent = source->parent->parent;
        if(grandparent == 0)
        {
            if(source == source->parent->left)
                rightRot(source->parent);
            else
                leftRot(source->parent);
        }
        else if(source == source->parent->left &&source->parent ==
          grandparent->left )
        {
//            o
//           /
//          o
//         /
//        o
            rightRot(grandparent);
            rightRot(source->parent);
        }
        else if(source == source->parent->right &&source->parent ==
           grandparent->right )
        {
//            o
//             \
//              o
//               \
//                o
            leftRot(grandparent);
            leftRot(source->parent);
        }
        else if(source == source->parent->left && source->parent ==
          grandparent->right )
        {
//            o
//             \
//              o
//             /
//            o
            rightRot(source->parent);
            leftRot(source->parent);
        }
        else
        {
//            o
//           /
//          o
//           \
//            o
            leftRot(source->parent);
            rightRot(source->parent);
        }
    }
}

void SplayTree::leftRot(Node* source)
{
    /*
     Precondition: arbol/subarbol con hijo derecho
     Postcontidion:  arbol/subarbol rotado
     Input: nodo a rotar
     Output:
     */
    Node* p;
    p = source->right;
    source -> right = source -> right -> left;
    if(p -> left!= 0)
        p->left->parent = source;

    p -> parent = source -> parent;
    p->left = source;
    source->parent = p;

    if(p->parent==0)
        this->root = p;
    else if(source == p->parent->left)
        p->parent->left = p;
    else
        p->parent->right = p;



}

void SplayTree::rightRot(Node* source)
{
    /*
     Precondition: arbol/subarbol con hijo izquierdo
     Postcontidion: arbol/subarbol rotado
     Input: nodo a rotar
     Output:
     */

    Node* p;
    p = source->left;
    source -> left = p -> right;
    if(p -> right)
        p->right->parent = source;

    p -> parent = source -> parent;
    p->right = source;
    source->parent = p;

    if(p->parent == 0)
        this->root = p;
    else if(source == p->parent->right)
        p->parent->right = p;
    else
        p->parent->left = p;



}


void SplayTree::add(Location source)
{   /*
       Precondition: arbol valido
       Postcontidion: arbol con nodo aladido
       Input: objeto a insertar
       Output:
       */
    if (root)
    {
        Node* aux = root->add(source);
        Splay(aux);
    }
    else
        root = new Node(source);

}

bool SplayTree::find(Location source)
{
    /*
         Precondition: arbol valido
         Postcontidion: arbol desplegado con objeto buscado
         Input: objeto a buscar
         Output: bool encontrado
         */

    if (root)
    {
        Node* aux = root->find(source.getDistance());
        Splay(aux);
        if(aux)
            return true;
        else
            return false;
    }
    return false;
}


std::string SplayTree::inorder() const
{
    /*
         Precondition: arbol valido
         Postcontidion:
         Input:
         Output: desplegado en orden
         */
    std::vector<string> vec;

    if (root!= 0)
        root->inorder(vec);

    std::stringstream aux;
    aux<<"[";
    for(int i = 0; i<vec.size();i++)
    {
        if(i!=vec.size()-1)
            aux<<vec[i]<<" , ";
        else
            aux<<vec[i];
    }
    aux<<"]";
    return aux.str();
}

std::string SplayTree::inorderList() const
{
    /*
         Precondition: arbol valido
         Postcontidion:
         Input:
         Output: desplegado en orden en lista
         */
    std::vector<string> vec;

    if (root!= 0)
        root->inorder(vec);

    std::stringstream aux;
    aux<<"\n";
    for(int i = 0; i<vec.size();i++)
    {
        if(i!=vec.size()-1)
            aux<<vec[i]<<endl;
        else
            aux<<vec[i];
    }
    aux<<"\n";
    return aux.str();
}
std::string SplayTree::inorderListDistance() const
{
    /*
         Precondition: arbol valido
         Postcontidion:
         Input:
         Output: desplegado en orden en lista con distancia
         */
    std::vector<string> vec;

    if (root!= 0)
        root->inorderDistance(vec);

    std::stringstream aux;
    aux<<"\n";
    for(int i = 0; i<vec.size();i++)
    {
        if(i!=vec.size()-1)
            aux<<vec[i]<<endl;
        else
            aux<<vec[i];
    }
    aux<<"\n";
    return aux.str();
}

std::string SplayTree::preorder() const
{
    /*
         Precondition: arbol valido
         Postcontidion:
         Input:
         Output: string de desplegado pre orden
         */
    std::vector<string> vec;
    if (root!= 0)
        root->preorder(vec);

    std::stringstream aux;
    aux<<"[";
    for(int i = 0; i<vec.size();i++)
    {
        if(i!=vec.size()-1)
            aux<<vec[i]<<" , ";
        else{aux<<vec[i];}
    }
    aux<<"]";
    return aux.str();
}



void SplayTree::remove(Location source)
{
    /*
         Precondition:arbol valido
         Postcontidion: arbol desplegado bottom up con nodo eliminado
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
            if (p != 0)
                Splay(p);
        }
    }

}

#endif /* Splay_h */
