#include <iostream>
#include <vector>

class Node {
public:
    std::string type;
    std::vector<Node*> children;

    Node(std::string type, std::vector<Node*> children = {}) : type(type), children(children) {}
};

class AST {
public:
    Node* root;

    AST(Node* root) : root(root) {}
};

bool validate_node(Node* node) {
    if (node->type == "error") {
        return false;
    }
    for (Node* child : node->children) {
        if (!validate_node(child)) {
            return false;
        }
    }
    return true;
}

void process_ast(AST* ast) {
    while (true) {
        if (validate_node(ast->root)) {
            continue;
        } else {
            ast->root->type = "corrected";
            ast->root->children.clear();
        }
    }
}

int main() {
    Node* root = new Node("error", {new Node("error"), new Node("correct")});
    AST* ast = new AST(root);
    process_ast(ast);
    return 0;
}