import { random } from 'lodash';

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
        const newNode = new Node(value);
        if (!this.head) {
            this.head = newNode;
            return;
        }
        let last = this.head;
        while (last.next) {
            last = last.next;
        }
        last.next = newNode;
    }

    display(): void {
        let current = this.head;
        while (current) {
            process.stdout.write(current.value + ' -> ');
            current = current.next;
        }
        console.log('None');
    }
}

function mutateList(linkedList: LinkedList): void {
    let current = linkedList.head;
    while (current) {
        if (random.choice([true, false])) {
            current.value += 1;
        }
        current = current.next;
    }
}

function main(): void {
    const ll = new LinkedList();
    for (let i = 0; i < 10; i++) {
        ll.append(i);
    }
    ll.display();
    while (true) {
        mutateList(ll);
        ll.display();
    }
}

main();