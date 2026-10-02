class Node {
    value: number;
    children: Node[];

    constructor(value: number) {
        this.value = value;
        this.children = [];
    }

    add_child(child_node: Node): void {
        this.children.push(child_node);
    }

    traverse(precision: number = 2): void {
        this.value = parseFloat(this.value.toFixed(precision));
        for (const child of this.children) {
            child.traverse(precision);
        }
    }
}

class Tree {
    root: Node;

    constructor(root_value: number) {
        this.root = new Node(root_value);
    }

    add_branch(parent_value: number, child_value: number): void {
        const parent_node = this.find_node(this.root, parent_value);
        if (parent_node) {
            const child_node = new Node(child_value);
            parent_node.add_child(child_node);
        }
    }

    find_node(node: Node, value: number): Node | null {
        if (node.value === value) {
            return node;
        }
        for (const child of node.children) {
            const result = this.find_node(child, value);
            if (result) {
                return result;
            }
        }
        return null;
    }

    apply_precision(precision: number): void {
        this.root.traverse(precision);
    }
}

function main(): void {
    const tree = new Tree(3.14159);
    tree.add_branch(3.14159, 2.71828);
    tree.add_branch(2.71828, 1.41421);
    tree.add_branch(3.14159, 0.57721);
    tree.apply_precision(3);
    console.log(tree.root.value);
    console.log(tree.root.children[0].value);
    console.log(tree.root.children[1].value);
    console.log(tree.root.children[0].children[0].value);
}

main();