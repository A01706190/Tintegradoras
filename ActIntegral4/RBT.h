//
//  RBT.h
//  ActIntegral3
//
//  Created by Israel Arroyo on 17/11/20.
//  A01706190

#ifndef RBT_h
#define RBT_h

#include <sstream>
#include <vector>
#include <math.h>
#include <cmath>

#include "Location.h"
#include "Node.h"
#include "Splay.h"
//red = 0
//black = 1

class Rbt : public SplayTree
{
private:
    void rotHelper(Node*);
public:
    Location find(int);
    void remove(Location);
    void add(Location);
    void fix(Node*);
    void fixDelete(Node*);
};

void Rbt::fix(Node* source)
{
    /*
     Precondition: arbol desbalanceado con insercion
     Postcontidion: arbol balanceado
     Input: nodo a evaluar con reglas de RBtree
     Output:
     */
    while(source!=root&&source->parent->parent && source->color != BLACK)
    {
      //black insertion does not affect double red condition
      if(source->parent == source->parent->parent->left)
      {
        if(source->parent->color == RED)
        {
          if(source->parent->parent->right->color == RED)
          {
            //uncle is RED -> color swap
            source->parent->color = BLACK;
            source->parent->parent->right->color = BLACK;
            source->parent->parent->color = RED;
            source = source->parent->parent;
          }
          else
          {
            //uncle is BLACK -> rotate
              rotHelper(source);
            source = source->parent->parent;
          }
        }
      }
      else
      {
        if(source->parent->color == RED)
        {
          if(source->parent->parent->left->color == RED)
          {
            //uncle is RED -> color swap
            source->parent->color = BLACK;
            source->parent->parent->left->color = BLACK;
            source->parent->parent->color = RED;
            source = source->parent->parent;
          }
          else
          {
              //uncle is BLACK -> rotate
              rotHelper(source);
              source = source->parent->parent;
          }
        }
      }
    }

}
void Rbt::fixDelete(Node* source)
{
  /*
   Precondition: arbol desbalanceado por eliminacion
   Postcontidion: arbol balanceado
   Input: nodo a evaluar con reglas de RBtree
   Output:
   */
  int sourceColor = BLACK;
  if(source)
    sourceColor = source->color;

  while(source!=root&&sourceColor == BLACK)
  //red deletion does not affect black heights
  {
    if(source == source->parent->right)
    //deleted node was right child
    {
      Node* sibling = source->parent->left;
      int siblingColor = BLACK;
      if(sibling)
        siblingColor = sibling->color;
      else
        break;
      int siblingRightColor = BLACK;
      int siblingLeftColor = BLACK;
      if(sibling->right)
        siblingRightColor = sibling->right->color;
      if(sibling->left)
        siblingLeftColor = sibling->left->color;

      if(siblingColor == BLACK &&
      (siblingRightColor == RED ||siblingLeftColor == RED))
      {
        if(siblingLeftColor== BLACK)
        {
          leftRot(source->parent);
          rightRot(source->parent);
          source = source->parent;
        }
        else
        {
          rightRot(source->parent);
          source = source->parent;
        }
      }
      else if(siblingColor == BLACK &&
        siblingRightColor == BLACK && siblingLeftColor == BLACK)
      {
        sibling->color = RED;
        source = source->parent;
      }
      else if(siblingColor == RED)
      {
        sibling->color = BLACK;
        source->parent->color = (source->parent->color == RED)? BLACK:RED;
        rightRot(source->parent);
      }
//-----------------------
      if(source == source->parent->left)
      //deleted node was left child
      {
        sibling = source->parent->right;
        int siblingColor = BLACK;
        if(sibling)
          siblingColor = sibling->color;
        else
          break;
        int siblingRightColor = BLACK;
        int siblingLeftColor = BLACK;
        if(sibling->right)
          siblingRightColor = sibling->right->color;
        if(sibling->left)
          siblingLeftColor = sibling->left->color;

        if(siblingColor == BLACK &&
        (siblingRightColor == RED ||siblingLeftColor == RED))
        {
          if(siblingLeftColor== BLACK)
          {
            leftRot(source->parent);
            source = source->parent;
          }
          else
          {
            leftRot(source->parent);
            rightRot(source->parent);
            source = source->parent;
          }
        }
        else if(siblingColor == BLACK &&
          siblingRightColor == BLACK && siblingLeftColor == BLACK)
        {
          sibling->color = RED;
          source = source->parent;
        }
        else if(siblingColor == RED)
        {
          sibling->color = BLACK;
          source->parent->color = (source->parent->color == RED)? BLACK:RED;
          leftRot(source->parent);
        }
     }
   }
  }
}

void Rbt::rotHelper(Node* source)
{
    Node* grandparent = source->parent->parent;
    if(grandparent == 0)
    {
        if(source == source->parent->left)
            rightRot(source->parent);
        else
            leftRot(source->parent);
    }
    else if(source == source->parent->left && source->parent ==
      grandparent->left )
    {

        rightRot(grandparent);
        rightRot(source->parent);
    }
    else if(source == source->parent->right &&source->parent ==
      grandparent->right )
    {

        leftRot(grandparent);
        leftRot(source->parent);
    }
    else if(source == source->parent->left && source->parent ==
      grandparent->right )
    {

        rightRot(source->parent);
        leftRot(source->parent);
    }
    else
    {
        leftRot(source->parent);
        rightRot(source->parent);
    }
}
void Rbt::add(Location source)
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
        // fix(aux);
        root->color = BLACK;
    }
    else
        root = new Node(source);
        root->color = BLACK;
}

Location Rbt::find(int dis)
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


void Rbt::remove(Location source)
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
          Node* aux = root->find(source.getDistance());
          //string side;
          int sourceColor = aux->color;
          // if(aux == aux->parent->rigth)
          //   side = "right";
          //   // sibling = aux->parent->left;
          // else
          //   side = "left";
          //   // sibling = aux->parent->right;

          int parentColor = aux->parent->color;
          if(!(parentColor==RED)||!(sourceColor==RED))
          {
            fixDelete(aux);
          }

          root->remove(source);
        }
    }

}

#endif /* RBT_h */
