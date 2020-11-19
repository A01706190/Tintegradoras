//
//  Node.h
//  ActIntegral3
//
//  Created by Israel Arroyo on 31/10/20.
//

#ifndef Node_h
#define Node_h
#include <math.h>
#include <cmath>
enum COLORS{RED,BLACK};

class Node
{
public:
    Node(Location&);
    Node* add(Location&);
    Node* find(int);
    Node* remove(Location);
    void removeChilds();
    void inorder(std::vector<std::string>&);
    void inorderDistance(std::vector<std::string>&);
    void print_tree(std::stringstream&) const;
    void preorder(std::vector<std::string>&);
    Node* predecesor();
    int height() const;

private:
    int color;
    Location value;
    Node* left;
    Node* right;
    Node* parent;


    friend class Avl;
    friend class SplayTree;
    friend class Rbt;
};



Node::Node(Location& val): left(0), right(0), parent(0), value(val), color(0){}


Node* Node::add(Location& source)
{
    /*
     Precondition: nodo conectado a un arbol
     Postcontidion: arbol con nodo agregado
     Input: objeto a agregar
     Output: nodo agregado
     */
    int val = source.getDistance();
    int valueInt = value.getDistance();
    if(val == valueInt)
        return 0;

    if (val < valueInt)
    {
        if (left != 0)
        {
            return left->add(source);
        }
        else
        {
            left = new Node(source);
            if (left)

                left->parent = this;

            return left;
        }
    }
    else
    {
        if (right != 0)
        {
            return right->add(source);
        }
        else
        {
            right = new Node(source);
            if(right)

                right->parent = this;

            return right;
        }
    }
    return 0;

}

int Node::height() const
{
    /*
     Precondition:nodo conectado a arbol
     Postcontidion:
     Input:
     Output: entero altura maxima
     */
    int downLeft = 0;
    int downRight = 0;
        if (left)
    {
        downLeft = left->height()+1;
    }
    if (right != 0)
    {
        downRight = right->height()+1;
    }
    if (downLeft == 0 && downRight == 0)
        return 1;

    return downLeft>downRight? downLeft:downRight;

}


void Node::preorder(std::vector<string>& vec)
{
    /*
     Precondition: nodo conectado a arbol
     Postcontidion:
     Input:
     Output: arbol desplegado en pre orden
     */

//    root->left->right

    vec.push_back(value.toString());

    if (left != 0)
        left->preorder(vec);

    if (right != 0)
        right->preorder(vec);

}

void Node::inorder(std::vector<string>& vec)
{
    /*
     Precondition: nodo conectado a arbol
     Postcontidion:
     Input:
     Output: arbol desplegado en orden
     */
//    left->root->right

    if (left != 0)
        left->inorder(vec);

    vec.push_back(value.toString());

    if (right != 0)
        right->inorder(vec);

}
void Node::inorderDistance(std::vector<string>& vec)
{
    /*
     Precondition:nodo conectado a arbol
     Postcontidion:
     Input:
     Output: arbol desplegado con distancia
     */
//    left->root->right

    if (left != 0)
        left->inorderDistance(vec);

    std::stringstream aux;
    aux<<value.toString()<<"        Distancia: "<<value.getDistance()<<"m ";
    vec.push_back(aux.str());

    if (right != 0)
        right->inorderDistance(vec);

}

Node* Node::find(int val)
{
    /*
     Precondition: nodo conectado a arbol
     Postcontidion:
     Input: valor a buscar
     Output: nodo que contiene valor
     */

    int valueInt = value.getDistance();

    if(val == valueInt)
    {
        return this;
    }
    else if (val<valueInt)
    {
        if(left!=0)
            return left->find(val);
        else
            return this;
    }
    else if (val>valueInt)
    {
        if(right!=0)
            return right->find(val);
        else
            return this;
    }
    return 0;
}


Node* Node::predecesor()
{
    /*
     Precondition: nodo conectado a arbol
     Postcontidion:
     Input:
     Output: sucesor de nodo
     */
    Node *le, *ri;

    le = left;
    ri = right;

    if (left == 0)
    {
        if (right != 0)
            right = 0;
        return ri;
    }

    if (left->right == 0)
    {
        left = left->left;
        le->left = 0;
        return le;
    }

    Node *parent, *child;
    parent = left;
    child = left->right;
    while (child->right != 0)
    {
        parent = child;
        child = child->right;
    }
    parent->right = child->left;
    child->left = 0;
    return child;
}


Node* Node::remove(Location source)
{
    /*
     Precondition: nodo conectado a arbol
     Postcontidion: nodo eliminado
     Input: objeto a eliminar
     Output: nodo padre de eliminado
     */
    int val = source.getDistance();
    int valueInt = value.getDistance();
    Node * succ, *old;

    if (val < valueInt)
    {
        if (left != 0)
        {
            if (left->value.getDistance() == val)
            {
                old = left;
                succ = left->predecesor();
                if (succ != 0)
                {
                    succ->left = old->left;
                    succ->right = old->right;
                    succ->parent = old->parent;
                    if(succ->left)
                        succ->left->parent=succ;
                    if(succ->right)
                        succ->right->parent=succ;
                }
                left = succ;
                delete old;
                return this;
            }
            else
            {
                return left->remove(source);
            }
        }
    }

    else if (val > valueInt)
    {
        if (right != 0)
        {
            if (right->value.getDistance() == val)
            {
                old = right;
                succ = right->predecesor();
                if (succ != 0)
                {
                    succ->left = old->left;
                    succ->right = old->right;
                    succ->parent=old->parent;
                    if(succ->left)
                        succ->left->parent=succ;
                    if(succ->right)
                        succ->right->parent=succ;
                }
                right = succ;
                delete old;
                return this;
            }
            else
            {
                return right->remove(source);
            }
        }
    }
    return 0;
}




void Node::removeChilds()
{
    /*
     Precondition: nodo conectado a arbol
     Postcontidion: eliminacion de hijos
     Input:
     Output:
     */
    if (left != 0)
    {
        left->removeChilds();
        delete left;
        left = 0;
    }
    if (right != 0)
    {
        right->removeChilds();
        delete right;
        right = 0;
    }
}


#endif /* Node_h */
