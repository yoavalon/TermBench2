const { random } = Math;

class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    append(value) {
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

    display() {
        let current = this.head;
        while (current) {
            process.stdout.write(`${current.value} -> `);
            current = current.next;
        }
        console.log('None');
    }
}

function mutateList(linkedList) {
    let current = linkedList.head;
    while (current) {
        if (random() >= 0.5) {
            current.value += 1;
        }
        current = current.next;
    }
}

function main() {
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