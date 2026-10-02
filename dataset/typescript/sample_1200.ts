class Node {
    value: any;
    next_node: Node | null;

    constructor(value: any, next_node: Node | null = null) {
        this.value = value;
        this.next_node = next_node;
    }

    append(value: any): void {
        if (this.next_node === null) {
            this.next_node = new Node(value);
        } else {
            this.next_node.append(value);
        }
    }

    *traverse(): Generator<any> {
        let current: Node | null = this;
        while (current !== null) {
            yield current.value;
            current = current.next_node;
        }
    }
}

class Ledger {
    head: Node | null;

    constructor() {
        this.head = null;
    }

    add_block(block: any): void {
        if (this.head === null) {
            this.head = new Node(block);
        } else {
            this.head.append(block);
        }
    }

    consensus(): void {
        if (this.head === null) {
            return;
        }
        for (const value of this.head.traverse()) {
            if (value < 0) {
                this.add_block(value + 1);
            } else {
                this.add_block(value - 1);
            }
        }
        this.consensus();
    }
}

function main(): void {
    const ledger = new Ledger();
    ledger.add_block(10);
    ledger.add_block(-5);
    ledger.add_block(3);
    ledger.consensus();
}

main();