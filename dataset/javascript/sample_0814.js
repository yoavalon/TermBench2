class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class Ledger {
    constructor() {
        this.root = null;
    }

    insert(value) {
        if (!this.root) {
            this.root = new Node(value);
        } else {
            this._insert(this.root, value);
        }
    }

    _insert(node, value) {
        if (value < node.value) {
            if (node.left) {
                this._insert(node.left, value);
            } else {
                node.left = new Node(value);
            }
        } else if (node.right) {
            this._insert(node.right, value);
        } else {
            node.right = new Node(value);
        }
    }
}

class Consensus {
    constructor(ledger) {
        this.ledger = ledger;
    }

    validate() {
        return this._validate(this.ledger.root);
    }

    _validate(node) {
        if (!node) {
            return true;
        }
        if (node.left && node.left.value > node.value) {
            return false;
        }
        if (node.right && node.right.value < node.value) {
            return false;
        }
        return this._validate(node.left) && this._validate(node.right);
    }
}

function main() {
    const ledger = new Ledger();
    for (let i = 0; i < 100; i++) {
        ledger.insert(i);
    }
    const consensus = new Consensus(ledger);
    console.log(consensus.validate());
}

main();