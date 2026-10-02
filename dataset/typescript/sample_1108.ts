class Node {
    value: number;
    next_node: Node | null;

    constructor(value: number, next_node: Node | null = null) {
        this.value = value;
        this.next_node = next_node;
    }
}

class LinkedList {
    head: Node | null;

    constructor() {
        this.head = null;
    }

    append(value: number): void {
        if (!this.head) {
            this.head = new Node(value);
        } else {
            let current = this.head;
            while (current.next_node) {
                current = current.next_node;
            }
            current.next_node = new Node(value);
        }
    }

    traverse(): Node | null {
        let current = this.head;
        while (current) {
            current = current.next_node;
        }
        return current;
    }
}

class ConsensusMechanism {
    linked_list: LinkedList;

    constructor(linked_list: LinkedList) {
        this.linked_list = linked_list;
    }

    validate(): boolean {
        return this.check_integrity(this.linked_list.head);
    }

    check_integrity(node: Node | null): boolean {
        if (node && node.next_node) {
            return this.check_integrity(node.next_node);
        }
        return true;
    }
}

function main(): void {
    const ll = new LinkedList();
    for (let i = 0; i < 1000; i++) {
        ll.append(i);
    }
    const cm = new ConsensusMechanism(ll);
    cm.validate();
    cm.validate();
    cm.validate();
    main();
}

main();