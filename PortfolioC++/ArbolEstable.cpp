#include <cassert>
#include <iostream>
#include <utility>
#include <string>
#include <fstream>
using namespace std;



template<typename T>
class BinTree {
public:
    BinTree() : root_node(nullptr) {}
    BinTree(const T& elem) : root_node(new TreeNode(nullptr, elem, nullptr)) {}
    BinTree(const BinTree& left, const T& elem, const BinTree& right)
        : root_node(new TreeNode(left.root_node, elem, right.root_node)) {}

    bool empty() const { return root_node == nullptr; }

    const T& root() const {
        assert(root_node != nullptr);
        return root_node->elem;
    }

    BinTree left() const {
        assert(root_node != nullptr);
        BinTree result;
        result.root_node = root_node->left;
        return result;
    }

    BinTree right() const {
        assert(root_node != nullptr);
        BinTree result;
        result.root_node = root_node->right;
        return result;
    }

    void display(std::ostream& out) const { display_node(root_node, out); }




    void  altura(BinTree<int> b1,int cont,int& mayor) {



        if (b1.right().empty() && b1.left().empty()) {

            if (cont > mayor) {
                mayor = cont;
            }
            return;
        }

        if (!b1.left().empty())
        altura(b1.left(), cont + 1, mayor);

        if (!b1.right().empty())
        altura(b1.right(), cont + 1, mayor);
    }

    

    void EstableEnAltura( BinTree<int>  b1,int& cont,int altura1,int altura_max) {

        if (b1.right().empty() && b1.left().empty()) {
            if (altura1 == altura_max) {
                cont++;
           }
            return;
        }



        if(!b1.left().empty())
        EstableEnAltura(b1.left(), cont, altura1 + 1, altura_max);

        if(!b1.right().empty())
        EstableEnAltura(b1.right(), cont, altura1 + 1, altura_max);




    }

    bool ArbolEstableEnAltura(BinTree<int> b1) {
        if (b1.empty()) {
            return true;
        }

        int altura1 = 0;
        altura(b1, 0, altura1);
        int cont = 0;
        EstableEnAltura(b1, cont, 0, altura1);

        return cont > 1;

    }






private:
    struct TreeNode {
        T elem;
        TreeNode* left, * right;

        TreeNode(TreeNode* left, const T& elem, TreeNode* right)
            : elem(elem), left(left), right(right) {}
    };

    TreeNode* root_node;

    static void display_node(const TreeNode* root, std::ostream& out) {
        if (root == nullptr) {
            out << ".";
        }
        else {
            out << "(";
            display_node(root->left, out);
            out << " " << root->elem << " ";
            display_node(root->right, out);
            out << ")";
        }
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const BinTree<T>& tree) {
    tree.display(out);
    return out;
}

template <typename T> BinTree<T> read_tree(std::istream& in) {
    char c;
    in >> c;
    if (c == '.') {
        return BinTree<T>();
    }
    else {
        assert(c == '(');
        BinTree<T> left = read_tree<T>(in);
        T elem;
        in >> elem;
        BinTree<T> right = read_tree<T>(in);
        in >> c;
        assert(c == ')');
        BinTree<T> result(left, elem, right);
        return result;
    }
};


void tratar_caso() {
    // Escribe aquí el código para leer y tratar un caso de prueba.

    BinTree<int> T;

    T = read_tree<int>(cin);

    switch (T.ArbolEstableEnAltura(T)) {
    case true: cout << "SI" << endl; break;
    case false:cout << "NO" << endl; break;




 }



    // La función debe devolver false si no se puede leer ningún caso de prueba
    // porque se ha llegado al fin de la entrada, o true en caso contrario.


}

int main() {
#ifndef DOMJUDGE
    
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    
#endif

    int num_casos;
    cin >> num_casos;
    for (int i = 0; i < num_casos; i++) {



        tratar_caso();





    }

#ifndef DOMJUDGE
    
    std::cin.rdbuf(cinbuf);
    
#endif
    return 0;
}
