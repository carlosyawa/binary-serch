#include <cstdlib>
#include<stdio.h>
#include "iostream"

using namespace std;
struct Node{
int data;
struct Node*left;
struct Node*right;
};



void menu(){
	cout<<"\nMenu\n";
	
	cout<<"1.Insertar"<<"\n";
	cout<<"2.Eliminar"<<"\n";
	cout<<"3.Inorder"<<"\n";
	cout<<"4.Preorder"<<"\n";
	cout<<"5.Postorder"<<"\n";
	cout<<"6.Salir"<<"\n";
	
	cout<<"\n Que deseas hacer: "<<"\n";
	
}

Node*createNode(int data){
	
Node*newNode=new Node;
	newNode->data=data;
	newNode->right=NULL;
	newNode->left=NULL;
	return newNode;
}
int size(struct Node*node){
	if(node==NULL){
		return 0;
	}else{
		return size(node->left)+1+size(node->right);
	}
}
int maxDepth(struct Node*node){
	if(node==NULL){
		return 0;
	}else{
		int lDepth=maxDepth(node->left);
		int rDepth=maxDepth(node->right);
		if(lDepth>rDepth){
			return lDepth+1;	
		}else{
		return rDepth+1;
		}
	}
}
int minimoDepth(struct Node*node){
	if(node==NULL){
		return 0;
	}else{
		int lDepth=minimoDepth(node->left);
		int rDepth=minimoDepth(node->right);
		if(lDepth<rDepth){
			return lDepth+1;	
		}else{
		return rDepth+1;
		}
	}
}
int suma(struct Node*node){
	if(node==NULL){
		return 0;
	}
	else{
		 return node->data + suma(node->left) + suma (node->right);
	}
}
int maximo(struct Node*node){
		if(node==NULL){
		return 0;
	}else{
		int res=node->data;
		int lres=maximo(node->left);
		int rres=maximo(node->right);
		if(lres>res){
			res=lres;
		}if(rres>res){
			res=rres;
		}
		return res;
	}
}
int minimo(struct Node*node){
		if(node==NULL){
		return 0;
	}else{
		int res=node->data;
		int lres=maximo(node->left);
		int rres=maximo(node->right);
		if(lres<res){
			res=lres;
		}if(rres<res){
			res=rres;
		}
		return res;
	}
}
void add(int data,struct Node* &node){
	if(node==NULL){
		cout<<"Root creado"<<"\n";
		node = createNode(data);
	}else if(node->data == data){
		cout<<"El elemento ya existe"<<"\n";
	}else if(data > node->data){
		add(data,node->right);
		cout<<"Nodo agregado a la derecha"<<"\n";
	}else if(data < node->data){
		add(data,node->left);
		cout<<"Nodo agregado a la izquierda"<<"\n";
	}
}


void Inorder(Node *node){
  if(node == NULL) {
  return;
  }
  Inorder(node->left);
cout<<(node->data)<<"\n";
  Inorder(node->right);
}

void Preorder(Node *node){
  if(node == NULL) {
  return;
  }
  cout<<node->data<<"\n";
  Preorder(node->left);
  Preorder(node->right);
}


void Postorder(Node *node){
  if(node == NULL) {
  	return;	
  }
  Postorder(node->left);
  Postorder(node->right);
  cout<<(node->data)<<"\n";
}


Node* EncontrarMinimo(Node*node){
  while(node->left != NULL){
   node = node->left;
}
  return node;
}	

struct Node* Delete(struct Node *&node, int data){
  if(node == NULL){
  	return node;
  } 
  else if(data < node->data){
  node->left = Delete(node->left,data);
  cout<<"Eliminado"<<"\n";
}
  else if(data > node->data){
   node->right = Delete(node->right, data);
  cout<<"Eliminado"<<"\n";
  }else {
    
    if(node->left == NULL && node->right == NULL){
      delete node;
      node = NULL;
   
    } else if(node->left == NULL){
      struct Node *temp = node;
      node = node->right;
      delete temp;
      cout<<"Eliminado"<<"\n";
    } else if(node->right == NULL){
      struct Node *temp = node;
      node = node->left;
      delete temp;
      cout<<"Eliminado"<<"\n";
    } else{
      struct Node *temp = EncontrarMinimo(node->right);
      node->data = temp->data;
      node->right = Delete(node->right, temp->data);
      cout<<"Eliminado"<<"\n";
    }
  }
  return node;
}
	
int main(){
	struct Node*root=NULL;
	int opcion;
	int value;

	do{
		menu(); 
		cin>>opcion;
		
		switch(opcion){
			
			case 1:
				cout<<"\n Nuevo valor"<<"\n";
				cin>>value;
				add(value,root);
				break;
				
			case 2:
			    cout<<"\nNumero a eliminar?"<<"\n";
				cin>>value;
				Delete(root,value);
				break;	

            case 3:
            	cout<<"Inorder-> "<<"\n";
            	Inorder(root);
                break;	
					   
			  case 4:
            	cout<<"Preorder-> "<<"\n";
            	Preorder(root);
                break;
				
			case 5:
            	cout<<"Postorder-> "<<"\n";
            	Postorder(root);
                break;
						   
					   
			case 6:
			opcion==6;
			break;	
		}
		
	}while(opcion!=6);
	return 0;	
	

}

