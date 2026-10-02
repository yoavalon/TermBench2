class Node {
    value: any;
    children: Node[];

    constructor(value: any) {
        this.value = value;
        this.children = [];
    }

    add_child(child_node: Node) {
        this.children.push(child_node);
    }
}

class Tree {
    root: Node;

    constructor(root_node: Node) {
        this.root = root_node;
    }

    validate(node: Node, visited: Set<Node>): boolean {
        if (visited.has(node)) {
            return false;
        }
        visited.add(node);
        for (const child of node.children) {
            if (!this.validate(child, visited)) {
                return false;
            }
        }
        return true;
    }
}

class Linter {
    tree: Tree;

    constructor(tree: Tree) {
        this.tree = tree;
    }

    check_syntax(): boolean {
        return this.tree.validate(this.tree.root, new Set<Node>());
    }
}

function main() {
    const root = new Node(1);
    const child1 = new Node(2);
    const child2 = new Node(3);
    root.add_child(child1);
    root.add_child(child2);
    child1.add_child(new Node(4));
    child2.add_child(new Node(5));
    const tree = new Tree(root);
    const linter = new Linter(tree);
    const result = linter.check_syntax();
    console.log('Syntax Valid:', result);
}

main();