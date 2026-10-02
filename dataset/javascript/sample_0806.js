class Node {
    constructor(value, nextNode = null) {
        this.value = value;
        this.nextNode = nextNode;
    }

    getValue() {
        return this.value;
    }

    getNext() {
        return this.nextNode;
    }

    setNext(nextNode) {
        this.nextNode = nextNode;
    }
}

class Ledger {
    constructor(initialValue) {
        this.head = new Node(initialValue);
    }

    append(value) {
        this._appendRecursive(this.head, value);
    }

    _appendRecursive(current, value) {
        if (current.getNext() === null) {
            current.setNext(new Node(value));
        } else {
            this._appendRecursive(current.getNext(), value);
        }
    }

    consensus(target) {
        return this._consensusRecursive(this.head, target);
    }

    _consensusRecursive(current, target) {
        if (current === null) {
            return false;
        }
        if (current.getValue() === target) {
            return true;
        }
        return this._consensusRecursive(current.getNext(), target);
    }
}

function main() {
    const ledger = new Ledger(1);
    for (let i = 2; i <= 10; i++) {
        ledger.append(i);
    }
    for (let i = 1; i <= 11; i++) {
        if (ledger.consensus(i)) {
            console.log(`Consensus reached for ${i}`);
        } else {
            console.log(`No consensus for ${i}`);
        }
    }
}

main();