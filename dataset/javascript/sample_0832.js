class LedgerNode {
    constructor(value, left = null, right = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

class ConsensusMechanics {
    constructor(root) {
        this.root = root;
    }

    validate(node) {
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

    update(node, new_value) {
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