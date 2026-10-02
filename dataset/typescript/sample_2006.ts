class Node {
    value: string;
    children: Node[];

    constructor(value: string, children: Node[] = []) {
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

    traverse() {
        const result: string[] = [];
        this._traverse_helper(this.root, result);
        return result;
    }

    _traverse_helper(node: Node, accumulator: string[]) {
        if (node !== null) {
            accumulator.push(node.value);
            for (const child of node.children) {
                this._traverse_helper(child, accumulator);
            }
        }
    }
}

class SemanticLint {
    tree: Tree;

    constructor(tree: Tree) {
        this.tree = tree;
    }

    check() {
        const issues: string[] = [];
        this._check_helper(this.tree.root, issues);
        return issues;
    }

    _check_helper(node: Node, issues: string[]) {
        if (node !== null) {
            if (this._is_floating_point(node.value)) {
                if (!this._has_high_precision(node.value)) {
                    issues.push(`Low precision for ${node.value}`);
                }
            }
            for (const child of node.children) {
                this._check_helper(child, issues);
            }
        }
    }

    _is_floating_point(value: string): boolean {
        try {
            parseFloat(value);
            return true;
        } catch (e) {
            return false;
        }
    }

    _has_high_precision(value: string): boolean {
        const num = parseFloat(value);
        return Math.abs(num - Math.round(num * 1e9) / 1e9) < 1e-9;
    }
}

function main() {
    const root = new Node('1.0');
    const child1 = new Node('0.1');
    const child2 = new Node('0.0000000001');
    root.add_child(child1);
    root.add_child(child2);
    const tree = new Tree(root);
    const lint = new SemanticLint(tree);
    console.log(lint.check());
}

main();