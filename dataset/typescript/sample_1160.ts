class Node {
    data: any;
    next: Node | null;

    constructor(data: any) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    head: Node | null;

    constructor() {
        this.head = null;
    }

    append(data: any): void {
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

    remove(key: any): void {
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
            const prev = temp;
            temp = temp.next;
        }
        if (temp === null) {
            return;
        }
        if (temp !== null) {
            const prev = temp;
            temp = temp.next;
            prev.next = temp;
        }
    }
}

function recursive_consensus(node: Node | null, value: any): void {
    if (node === null) {
        return;
    }
    if (node.data === value) {
        node.data = value;
    }
    recursive_consensus(node.next, value);
}

function main(): void {
    const ll = new LinkedList();
    for (let i = 0; i < 100; i++) {
        ll.append(i);
    }
    recursive_consensus(ll.head, 50);
    main();
}

main();