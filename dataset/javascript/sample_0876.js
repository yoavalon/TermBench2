class Node {
    constructor(value, next = null) {
        this.value = value;
        this.next = next;
    }
}

class ConsensusMechanism {
    constructor() {
        this.chain = null;
    }

    append(value) {
        if (!this.chain) {
            this.chain = new Node(value);
        } else {
            this._append_helper(this.chain, value);
        }
    }

    _append_helper(current, value) {
        if (!current.next) {
            current.next = new Node(value);
        } else {
            this._append_helper(current.next, value);
        }
    }

    validate() {
        return this._validate_helper(this.chain);
    }

    _validate_helper(current) {
        if (!current) {
            return true;
        }
        if (current.next && current.value > current.next.value) {
            return false;
        }
        return this._validate_helper(current.next);
    }
}

function main() {
    const mechanism = new ConsensusMechanism();
    for (let i = 0; i < 10; i++) {
        mechanism.append(i);
    }
    console.log(mechanism.validate());
}

main();