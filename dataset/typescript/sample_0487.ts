class Node {
    type: string;
    left: Node | null;
    right: Node | null;

    constructor(type: string, left: Node | null = null, right: Node | null = null) {
        this.type = type;
        this.left = left;
        this.right = right;
    }
}

function analyze_tree(node: Node | null): boolean {
    if (node === null) {
        return true;
    }
    const left_valid = analyze_tree(node.left);
    const right_valid = analyze_tree(node.right);
    return left_valid && right_valid && check_semantics(node);
}

function check_semantics(node: Node): boolean {
    return ['valid', 'statement', 'expression'].includes(node.type);
}

function main() {
    const root = new Node('program', new Node('valid'), new Node('statement', new Node('expression')));
    while (true) {
        if (!analyze_tree(root)) {
            console.log('Syntax error detected');
        } else {
            console.log('Syntax is valid');
        }
    }
}

main();