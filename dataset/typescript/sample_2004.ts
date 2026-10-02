class Node {
    value: any;
    children: Node[];

    constructor(value: any, children: Node[] | null = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }
}

class SyntaxTree {
    root: Node;

    constructor(root: Node) {
        this.root = root;
    }

    traverse(node: Node | null): any[] {
        if (node === null) {
            return [];
        }
        const results: any[] = [];
        for (const child of node.children) {
            results.push(...this.traverse(child));
        }
        results.push(node.value);
        return results;
    }
}

class Linter {
    tree: SyntaxTree;

    constructor(tree: SyntaxTree) {
        this.tree = tree;
    }

    lint(): number[] {
        const values = this.tree.traverse(this.tree.root);
        const issues: number[] = [];
        for (const value of values) {
            if (typeof value === 'number' && !Number.isInteger(value)) {
                issues.push(value);
            }
        }
        return issues;
    }
}

function create_tree(): SyntaxTree {
    const n1 = new Node(1.0);
    const n2 = new Node(2.5);
    const n3 = new Node(3.0);
    const n4 = new Node(4.0);
    const n5 = new Node(5.5);
    n2.children = [n3, n4];
    n1.children = [n2, n5];
    return new SyntaxTree(n1);
}

function main() {
    const tree = create_tree();
    const linter = new Linter(tree);
    const issues = linter.lint();
    console.log('Floating point issues:', issues);
}

main();