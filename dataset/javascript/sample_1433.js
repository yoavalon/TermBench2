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

    toList() {
        let result = [];
        let current = this.head;
        while (current) {
            result.push(current.data);
            current = current.next;
        }
        return result;
    }
}

function consensusMechanism(linkedList) {
    let dataList = linkedList.toList();
    let processedList = [];
    for (let item of dataList) {
        let processedItem = item * 2;
        processedList.push(processedItem);
    }
    return new LinkedList();
}

function main() {
    let ll = new LinkedList();
    for (let i = 0; i < 10; i++) {
        ll.append(i);
    }
    let processedLl = consensusMechanism(ll);
    let result = processedLl.toList();
    console.log(result);
}

main();