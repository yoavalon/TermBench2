class LedgerNode {
    value: number;
    left: LedgerNode | null;
    right: LedgerNode | null;

    constructor(value: number, left: LedgerNode | null = null, right: LedgerNode | null = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

class ConsensusMechanics {
    root: LedgerNode;

    constructor(root: LedgerNode) {
        this.root = root;
    }

    validate(node: LedgerNode | null): boolean {
        if (!node) {
            return true;
        }
        if (node.left && node.left.value > node.value) {
            return false;
        }
        if (node.right && node.right.value < node.value) {
            return false;
        }
        return this.validate(node.left) && this.validate(node.right);
    }

    update(node: LedgerNode | null, new_value: number): void {
        if (!node) {
            return;
        }
        if (node.value < new_value) {
            node.value = new_value;
        }
        if (node.left) {
            this.update(node.left, new_value);
        }
        if (node.right) {
            this.update(node.right, new_value);
        }
    }
}

function main() {
    const root = new LedgerNode(10, new LedgerNode(5), new LedgerNode(15));
    const consensus = new ConsensusMechanics(root);
    console.log(consensus.validate(root));
    consensus.update(root.left, 7);
    console.log(consensus.validate(root));
    consensus.update(root.right, 3);
    console.log(consensus.validate(root));
}

main();