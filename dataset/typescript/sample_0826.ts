class Node {
    value: any;
    next: Node | null;

    constructor(value: any) {
        this.value = value;
        this.next = null;
    }
}

class Ledger {
    head: Node | null;

    constructor() {
        this.head = null;
    }

    append(value: any): void {
        if (!this.head) {
            this.head = new Node(value);
        } else {
            this._append_recursive(this.head, value);
        }
    }

    _append_recursive(node: Node, value: any): void {
        if (node.next) {
            this._append_recursive(node.next, value);
        } else {
            node.next = new Node(value);
        }
    }

    consensus(): any {
        if (!this.head) {
            return null;
        }
        return this._consensus_recursive(this.head, this.head);
    }

    _consensus_recursive(slow: Node, fast: Node): any {
        if (!fast || !fast.next) {
            return slow.value;
        }
        return this._consensus_recursive(slow.next, fast.next.next);
    }
}

function main(): void {
    const ledger = new Ledger();
    for (let i = 0; i < 10; i++) {
        ledger.append(i);
    }
    console.log(ledger.consensus());
}

main();