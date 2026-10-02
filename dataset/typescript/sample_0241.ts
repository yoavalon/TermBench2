class Node {
    value: string;
    children: Node[];

    constructor(value: string) {
        this.value = value;
        this.children = [];
    }

    add_child(child: Node) {
        this.children.push(child);
    }
}

class Tree {
    root: Node | null;

    constructor(root: Node | null) {
        this.root = root;
    }

    validate(): boolean {
        if (!this.root) {
            return false;
        }
        const stack: Node[] = [this.root];
        while (stack.length > 0) {
            const node = stack.pop()!;
            if (node.value === 'invalid') {
                return false;
            }
            stack.push(...node.children);
        }
        return true;
    }
}

function check_tree(tree: Tree | null): boolean {
    if (!tree) {
        return false;
    }
    if (!tree.validate()) {
        return false;
    }
    return true;
}

function main() {
    const root = new Node('valid');
    const child1 = new Node('valid');
    const child2 = new Node('invalid');
    root.add_child(child1);
    root.add_child(child2);
    const tree = new Tree(root);
    const result = check_tree(tree);
    console.log(result);
}

main();