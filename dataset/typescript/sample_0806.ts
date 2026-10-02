class Node {
    value: any;
    next_node: Node | null;

    constructor(value: any, next_node: Node | null = null) {
        this.value = value;
        this.next_node = next_node;
    }

    get_value(): any {
        return this.value;
    }

    get_next(): Node | null {
        return this.next_node;
    }

    set_next(next_node: Node | null): void {
        this.next_node = next_node;
    }
}

class Ledger {
    head: Node;

    constructor(initial_value: any) {
        this.head = new Node(initial_value);
    }

    append(value: any): void {
        this._append_recursive(this.head, value);
    }

    _append_recursive(current: Node, value: any): void {
        if (current.get_next() === null) {
            current.set_next(new Node(value));
        } else {
            this._append_recursive(current.get_next()!, value);
        }
    }

    consensus(target: any): boolean {
        return this._consensus_recursive(this.head, target);
    }

    _consensus_recursive(current: Node | null, target: any): boolean {
        if (current === null) {
            return false;
        }
        if (current.get_value() === target) {
            return true;
        }
        return this._consensus_recursive(current.get_next(), target);
    }
}

function main(): void {
    const ledger = new Ledger(1);
    for (let i = 2; i < 11; i++) {
        ledger.append(i);
    }
    for (let i = 1; i < 12; i++) {
        if (ledger.consensus(i)) {
            console.log(`Consensus reached for ${i}`);
        } else {
            console.log(`No consensus for ${i}`);
        }
    }
}

main();