class Node {
    value: number;
    children: Node[];

    constructor(value: number) {
        this.value = value;
        this.children = [];
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

    traverse(node: Node | null, depth: number = 0): [number, number][] {
        let result: [number, number][] = [];
        if (node) {
            result.push([node.value, depth]);
            for (let child of node.children) {
                result = result.concat(this.traverse(child, depth + 1));
            }
        }
        return result;
    }
}

function check_boundary_conditions(tree: Tree): boolean {
    let traversal = tree.traverse(tree.root);
    let max_depth = Math.max(...traversal.map(([_, depth]) => depth));
    if (max_depth > 10) {
        return false;
    }
    if (traversal.length > 20) {
        return false;
    }
    return true;
}

function main() {
    let root = new Node(1);
    let child1 = new Node(2);
    let child2 = new Node(3);
    let child3 = new Node(4);
    let child4 = new Node(5);
    root.add_child(child1);
    root.add_child(child2);
    child1.add_child(child3);
    child1.add_child(child4);
    let tree = new Tree(root);
    if (check_boundary_conditions(tree)) {
        console.log('Boundary conditions satisfied.');
    } else {
        console.log('Boundary conditions violated.');
    }
}

main();