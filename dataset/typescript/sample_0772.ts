class Node {
    value: any;
    children: Node[];

    constructor(value: any, children: Node[] | null = null) {
        this.value = value;
        this.children = children ? children : [];
    }
}

function validate(node: Node | null, rules: Set<any>): boolean {
    if (!node) {
        return true;
    }
    if (!rules.has(node.value)) {
        return false;
    }
    for (const child of node.children) {
        if (!validate(child, rules)) {
            return false;
        }
    }
    return true;
}

function main() {
    const tree = new Node('root', [new Node('a', [new Node('b'), new Node('c')]), new Node('d', [new Node('e')])]);
    const rules = new Set(['root', 'a', 'b', 'c', 'd', 'e']);
    console.log(validate(tree, rules));
}

main();