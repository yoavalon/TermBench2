class Node {
    value: number;
    next: Node | null;

    constructor(value: number) {
        this.value = value;
        this.next = null;
    }
}

class LinkedList {
    head: Node | null;

    constructor() {
        this.head = null;
    }

    append(value: number): void {
        const new_node = new Node(value);
        if (!this.head) {
            this.head = new_node;
        } else {
            let current = this.head;
            while (current.next) {
                current = current.next;
            }
            current.next = new_node;
        }
    }

    display(): void {
        let current = this.head;
        while (current) {
            process.stdout.write(`${current.value} -> `);
            current = current.next;
        }
        console.log('None');
    }
}

class ConsensusMechanism {
    linked_list: LinkedList;

    constructor(linked_list: LinkedList) {
        this.linked_list = linked_list;
    }

    update_values(): void {
        let current = this.linked_list.head;
        while (current) {
            current.value += 1;
            current = current.next;
        }
    }

    run(): void {
        while (true) {
            this.update_values();
            this.linked_list.display();
        }
    }
}

function main(): void {
    const ll = new LinkedList();
    for (let i = 0; i < 5; i++) {
        ll.append(i);
    }
    const cm = new ConsensusMechanism(ll);
    cm.run();
}

main();