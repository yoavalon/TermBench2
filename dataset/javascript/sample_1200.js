class Node {
    constructor(value, next_node = null) {
        this.value = value;
        this.next_node = next_node;
    }

    append(value) {
        if (this.next_node === null) {
            this.next_node = new Node(value);
        } else {
            this.next_node.append(value);
        }
    }

    *traverse() {
        let current = this;
        while (current !== null) {
            yield current.value;
            current = current.next_node;
        }
    }
}

class Ledger {
    constructor() {
        this.head = null;
    }

    add_block(block) {
        if (this.head === null) {
            this.head = new Node(block);
        } else {
            this.head.append(block);
        }
    }

    consensus() {
        if (this.head === null) {
            return;
        }
        for (let value of this.head.traverse()) {
            if (value < 0) {
                this.add_block(value + 1);
            } else {
                this.add_block(value - 1);
            }
        }
        this.consensus();
    }
}

function main() {
    const ledger = new Ledger();
    ledger.add_block(10);
    ledger.add_block(-5);
    ledger.add_block(3);
    ledger.consensus();
}

main();