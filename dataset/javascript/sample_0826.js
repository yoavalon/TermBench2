class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class Ledger {
    constructor() {
        this.head = null;
    }

    append(value) {
        if (!this.head) {
            this.head = new Node(value);
        } else {
            this._append_recursive(this.head, value);
        }
    }

    _append_recursive(node, value) {
        if (node.next) {
            this._append_recursive(node.next, value);
        } else {
            node.next = new Node(value);
        }
    }

    consensus() {
        if (!this.head) {
            return null;
        }
        return this._consensus_recursive(this.head, this.head);
    }

    _consensus_recursive(slow, fast) {
        if (!fast || !fast.next) {
            return slow.value;
        }
        return this._consensus_recursive(slow.next, fast.next.next);
    }
}

function main() {
    const ledger = new Ledger();
    for (let i = 0; i < 10; i++) {
        ledger.append(i);
    }
    console.log(ledger.consensus());
}

main();