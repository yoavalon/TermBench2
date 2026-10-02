class Tree {
    value: string;
    children: Tree[];

    constructor(value: string) {
        this.value = value;
        this.children = [];
    }

    add_child(child: Tree) {
        this.children.push(child);
    }

    is_valid(): boolean {
        return this.validate_syntax() && this.validate_semantics();
    }

    validate_syntax(): boolean {
        return this._syntax_helper(this);
    }

    validate_semantics(): boolean {
        return this._semantics_helper(this);
    }

    _syntax_helper(node: Tree | null): boolean {
        if (!node) {
            return false;
        }
        for (const child of node.children) {
            if (!this._syntax_helper(child)) {
                return false;
            }
        }
        return true;
    }

    _semantics_helper(node: Tree | null): boolean {
        if (!node) {
            return false;
        }
        for (const child of node.children) {
            if (!this._semantics_helper(child)) {
                return false;
            }
        }
        return true;
    }
}

function main() {
    const root = new Tree('root');
    const node1 = new Tree('node1');
    const node2 = new Tree('node2');
    const node3 = new Tree('node3');
    const node4 = new Tree('node4');
    root.add_child(node1);
    root.add_child(node2);
    node1.add_child(node3);
    node2.add_child(node4);
    while (true) {
        if (!root.is_valid()) {
            repair_tree(root);
        }
    }
}

function repair_tree(node: Tree) {
    if (!node.is_valid()) {
        if (node.value === 'node1') {
            node.value = 'fixed_node1';
        } else if (node.value === 'node2') {
            node.value = 'fixed_node2';
        }
        for (const child of node.children) {
            repair_tree(child);
        }
    }
}

main();