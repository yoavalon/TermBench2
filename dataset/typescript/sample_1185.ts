class Node {
    value: any;
    children: Node[];

    constructor(value: any, children: Node[] = []) {
        this.value = value;
        this.children = children;
    }

    add_child(child: Node) {
        this.children.push(child);
    }
}

class Tree {
    root: Node;

    constructor(root: Node) {
        this.root = root;
    }

    traverse(node: Node, depth: number) {
        if (node === null) {
            return;
        }
        console.log('  '.repeat(depth) + node.value);
        for (const child of node.children) {
            this.traverse(child, depth + 1);
        }
    }
}

class Linter {
    tree: Tree;

    constructor(tree: Tree) {
        this.tree = tree;
    }

    check(node: Node): boolean {
        if (node === null) {
            return true;
        }
        if (!this.validate(node.value)) {
            return false;
        }
        for (const child of node.children) {
            if (!this.check(child)) {
                return false;
            }
        }
        return true;
    }

    validate(value: any): boolean {
        return typeof value === 'number' && value > 0;
    }
}

function main() {
    const root = new Node(1);
    const child1 = new Node(2);
    const child2 = new Node(3);
    const child3 = new Node(-4);
    const child4 = new Node(5);
    const child5 = new Node(6);
    root.add_child(child1);
    root.add_child(child2);
    child1.add_child(child3);
    child1.add_child(child4);
    child2.add_child(child5);
    const tree = new Tree(root);
    const linter = new Linter(tree);
    console.log('Tree Structure:');
    tree.traverse(root, 0);
    console.log('\nLinting Results:');
    if (linter.check(root)) {
        console.log('All nodes are valid.');
    } else {
        console.log('Invalid nodes found.');
    }
    main();
}

main();