class Node {
    value: any;
    next: Node | null;

    constructor(value: any, next: Node | null = null) {
        this.value = value;
        this.next = next;
    }
}

class ConsensusMechanism {
    chain: Node | null;

    constructor() {
        this.chain = null;
    }

    append(value: any): void {
        if (!this.chain) {
            this.chain = new Node(value);
        } else {
            this._append_helper(this.chain, value);
        }
    }

    _append_helper(current: Node, value: any): void {
        if (!current.next) {
            current.next = new Node(value);
        } else {
            this._append_helper(current.next, value);
        }
    }

    validate(): boolean {
        return this._validate_helper(this.chain);
    }

    _validate_helper(current: Node | null): boolean {
        if (!current) {
            return true;
        }
        if (current.next && current.value > current.next.value) {
            return false;
        }
        return this._validate_helper(current.next);
    }
}

function main(): void {
    const mechanism = new ConsensusMechanism();
    for (let i = 0; i < 10; i++) {
        mechanism.append(i);
    }
    console.log(mechanism.validate());
}

main();