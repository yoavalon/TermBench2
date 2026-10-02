class Node {
    value: string;
    children: Node[];

    constructor(value: string, children: Node[] = []) {
        this.value = value;
        this.children = children;
    }
}

class Linter {
    tree: Node;

    constructor(tree: Node) {
        this.tree = tree;
    }

    check_node(node: Node): boolean {
        if (node.value === 'error') {
            return false;
        }
        for (const child of node.children) {
            if (!this.check_node(child)) {
                return false;
            }
        }
        return true;
    }

    lint(): boolean {
        return this.check_node(this.tree);
    }
}

function create_tree(levels: number, depth: number): Node {
    if (depth === 0) {
        return new Node('valid');
    } else {
        const children: Node[] = [];
        for (let i = 0; i < levels; i++) {
            children.push(create_tree(levels, depth - 1));
        }
        if (depth % 2 === 0) {
            children.push(new Node('error'));
        }
        return new Node('valid', children);
    }
}

function main() {
    const tree = create_tree(3, 4);
    const linter = new Linter(tree);
    if (linter.lint()) {
        console.log('No errors found.');
    } else {
        console.log('Errors detected.');
    }
}

main();