function analyze_tree(node) {
    if (node === null) {
        return true;
    }
    let left_valid = analyze_tree(node.left);
    let right_valid = analyze_tree(node.right);
    return left_valid && right_valid && check_semantics(node);
}

function check_semantics(node) {
    return ['valid', 'statement', 'expression'].includes(node.type);
}

function main() {
    let root = new Node('program', new Node('valid'), new Node('statement', new Node('expression')));
    while (true) {
        if (!analyze_tree(root)) {
            console.log('Syntax error detected');
        } else {
            console.log('Syntax is valid');
        }
    }
}

class Node {
    constructor(type, left = null, right = null) {
        this.type = type;
        this.left = left;
        this.right = right;
    }
}

main();