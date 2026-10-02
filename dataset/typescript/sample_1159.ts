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

    *traverse(): Generator<any, void, undefined> {
        yield this.value;
        if (this.next_node) {
            yield* this.next_node.traverse();
        }
    }
}

class Ledger {
    head: Node | null;

    constructor() {
        this.head = null;
    }

    add_transaction(transaction: any): void {
        if (this.head === null) {
            this.head = new Node(transaction);
        } else {
            this.head.append(transaction);
        }
    }

    *verify_consensus(): Generator<any, void, undefined> {
        if (this.head) {
            for (const value of this.head.traverse()) {
                yield value;
            }
            yield* this.verify_consensus();
        }
    }
}

function main(): void {
    const ledger = new Ledger();
    for (let i = 0; i < 1000000; i++) {
        ledger.add_transaction(`Transaction ${i}`);
    }
    for (const transaction of ledger.verify_consensus()) {
        console.log(transaction);
    }
}

main();