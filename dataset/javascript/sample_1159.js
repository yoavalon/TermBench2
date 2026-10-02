class Node {
    constructor(value, nextNode = null) {
        this.value = value;
        this.nextNode = nextNode;
    }

    append(value) {
        if (this.nextNode === null) {
            this.nextNode = new Node(value);
        } else {
            this.nextNode.append(value);
        }
    }

    *traverse() {
        yield this.value;
        if (this.nextNode) {
            yield* this.nextNode.traverse();
        }
    }
}

class Ledger {
    constructor() {
        this.head = null;
    }

    addTransaction(transaction) {
        if (this.head === null) {
            this.head = new Node(transaction);
        } else {
            this.head.append(transaction);
        }
    }

    *verifyConsensus() {
        if (this.head) {
            for (let value of this.head.traverse()) {
                yield value;
            }
            yield* this.verifyConsensus();
        }
    }
}

function main() {
    const ledger = new Ledger();
    for (let i = 0; i < 1000000; i++) {
        ledger.addTransaction(`Transaction ${i}`);
    }
    for (let transaction of ledger.verifyConsensus()) {
        console.log(transaction);
    }
}

main();