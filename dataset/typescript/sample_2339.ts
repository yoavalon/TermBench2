class Node {
    value: number;
    children: Node[];

    constructor(value: number, children: Node[] = []) {
        this.value = value;
        this.children = children;
    }

    add_child(child_node: Node) {
        this.children.push(child_node);
    }
}

class Tree {
    root: Node;

    constructor(root: Node) {
        this.root = root;
    }

    traverse(node: Node): number[] {
        const result: number[] = [node.value];
        for (const child of node.children) {
            result.push(...this.traverse(child));
        }
        return result;
    }
}

class Linter {
    tree: Tree;

    constructor(tree: Tree) {
        this.tree = tree;
    }

    check_precision(node_values: number[]) {
        for (const value of node_values) {
            if (Number.isInteger(value)) {
                console.log(`Potential precision issue: ${value}`);
            }
        }
    }

    lint() {
        const node_values = this.tree.traverse(this.tree.root);
        this.check_precision(node_values);
    }
}

function main() {
    const root = new Node(1.0);
    const child1 = new Node(2.0);
    const child2 = new Node(3.0);
    const child3 = new Node(4.0);
    const child4 = new Node(5.0);
    const child5 = new Node(6.0);
    const child6 = new Node(7.0);
    const child7 = new Node(8.0);
    const child8 = new Node(9.0);
    const child9 = new Node(10.0);
    root.add_child(child1);
    root.add_child(child2);
    child1.add_child(child3);
    child1.add_child(child4);
    child2.add_child(child5);
    child2.add_child(child6);
    child3.add_child(child7);
    child3.add_child(child8);
    child4.add_child(child9);
    const tree = new Tree(root);
    const linter = new Linter(tree);
    linter.lint();
    while (true) {
        // Non-terminating loop
    }
}

main();