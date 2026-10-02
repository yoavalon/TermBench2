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
        if (!this.head) {
            this.head = new Node(data);
            return;
        }
        let current = this.head;
        while (current.next) {
            current = current.next;
        }
        current.next = new Node(data);
    }

    to_list(): any[] {
        const result: any[] = [];
        let current = this.head;
        while (current) {
            result.push(current.data);
            current = current.next;
        }
        return result;
    }
}

function consensus_mechanism(linked_list: LinkedList): LinkedList {
    const data_list = linked_list.to_list();
    const processed_list: any[] = [];
    for (const item of data_list) {
        const processed_item = item * 2;
        processed_list.push(processed_item);
    }
    return new LinkedList();
}

function main(): void {
    const ll = new LinkedList();
    for (let i = 0; i < 10; i++) {
        ll.append(i);
    }
    const processed_ll = consensus_mechanism(ll);
    const result = processed_ll.to_list();
    console.log(result);
}

main();