#include <cassert>
#include <iostream>
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


    struct tSol {
        int cont = 0;
        bool esZurdo = true;


    };



    tSol Zurdo(BinTree<char> b1) {

        if (b1.empty()) {

            return  { 0,true };
        }


        tSol izq, der, Valor_retornado;

        if (!b1.left().empty())
            izq = Zurdo(b1.left());

        if (!b1.right().empty())
            der = Zurdo(b1.right());


        if ((der.cont >= izq.cont && der.cont != 0) || !izq.esZurdo || !der.esZurdo) {

            Valor_retornado.esZurdo = false;


        }
        Valor_retornado.cont = 1 + izq.cont + der.cont;

        return Valor_retornado;
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










void ArbolDenso(BinTree<int> B1, int& ultimo_numero,bool & Denso,bool & Primero) {

    if (!Denso) {
        return;
    }
    if (B1.empty()) {
        return;
    }



    if(!B1.left().empty())
    ArbolDenso(B1.left(), ultimo_numero, Denso, Primero);

   
    if (!Primero && B1.root() != ultimo_numero + 1) {

        Denso = false;

    }
    Primero = false;
    ultimo_numero = B1.root();

    if (!B1.right().empty())
    ArbolDenso(B1.right(), ultimo_numero, Denso, Primero);






}
bool ArbolEsDenso(BinTree<int> B1) {
    bool Denso=true;
    int ultimo_numero=-1;
    bool Primero = true;
    ArbolDenso(B1, ultimo_numero, Denso, Primero);

   




    return Denso;
}





void tratar_caso() {

    BinTree<int> B1 = read_tree<int>(cin);  

    switch (ArbolEsDenso(B1)) {
    case true: cout << "SI" << endl; break;
    case false: cout << "NO" << endl; break;

    }
    


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
}