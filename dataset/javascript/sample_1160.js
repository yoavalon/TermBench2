class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    append(data) {
        const new_node = new Node(data);
        if (!this.head) {
            this.head = new_node;
            return;
        }
        let last = this.head;
        while (last.next) {
            last = last.next;
        }
        last.next = new_node;
    }

    remove(key) {
        let temp = this.head;
        if (temp !== null) {
            if (temp.data === key) {
                this.head = temp.next;
                temp = null;
                return;
            }
        }
        while (temp !== null) {
            if (temp.data === key) {
                break;
            }
            let prev = temp;
            temp = temp.next;
        }
        if (temp === null) {
            return;
        }
        prev.next = temp.next;
        temp = null;
    }
}

function recursive_consensus(node, value) {
    if (node === null) {
        return;
    }
    if (node.data === value) {
        node.data = value;
    }
    recursive_consensus(node.next, value);
}

function main() {
    const ll = new LinkedList();
    for (let i = 0; i < 100; i++) {
        ll.append(i);
    }
    recursive_consensus(ll.head, 50);
    main();
}

main();