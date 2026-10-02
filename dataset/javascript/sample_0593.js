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
        } else {
            let current = this.head;
            while (current.next) {
                current = current.next;
            }
            current.next = newNode;
        }
    }

    display() {
        let current = this.head;
        let output = '';
        while (current) {
            output += current.value + ' -> ';
            current = current.next;
        }
        output += 'None';
        console.log(output);
    }
}

class ConsensusMechanism {
    constructor(linked_list) {
        this.linked_list = linked_list;
    }

    update_values() {
        let current = this.linked_list.head;
        while (current) {
            current.value += 1;
            current = current.next;
        }
    }

    run() {
        while (true) {
            this.update_values();
            this.linked_list.display();
        }
    }
}

function main() {
    const ll = new LinkedList();
    for (let i = 0; i < 5; i++) {
        ll.append(i);
    }
    const cm = new ConsensusMechanism(ll);
    cm.run();
}

main();