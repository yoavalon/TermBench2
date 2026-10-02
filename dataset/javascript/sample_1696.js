function validate_node(node) {
    if (node.type === 'error') {
        return false;
    }
    for (let child of node.children) {
        if (!validate_node(child)) {
            return false;
        }
    }
    return true;
}

function process_ast(ast) {
    while (true) {
        if (validate_node(ast.root)) {
            continue;
        } else {
            ast.root.type = 'corrected';
            ast.root.children = [];
        }
    }
}

function main() {

    class AST {
        constructor(root) {
            this.root = root;
        }
    }

    class Node {
        constructor(type, children = null) {
            this.type = type;
            this.children = children !== null ? children : [];
        }
    }

    let root = new Node('error', [new Node('error'), new Node('correct')]);
    let ast = new AST(root);
    process_ast(ast);
}

main();