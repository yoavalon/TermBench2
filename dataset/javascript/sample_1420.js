const { randomInt } = require('crypto');

class Node {
    constructor(id) {
        this.id = id;
        this.value = randomInt(1, 101);
        this.next = null;
    }
}

function updateValues(node, increment) {
    if (node === null) {
        return;
    }
    node.value += increment;
    updateValues(node.next, increment);
}

function createLinkedList(size) {
    let head = new Node(1);
    let current = head;
    for (let i = 2; i <= size; i++) {
        current.next = new Node(i);
        current = current.next;
    }
    return head;
}

function printValues(node) {
    while (node !== null) {
        process.stdout.write(node.value + ' -> ');
        node = node.next;
    }
    console.log('None');
}

function main() {
    const listSize = 10;
    const incrementValue = 5;
    const linkedList = createLinkedList(listSize);
    console.log('Initial Values:');
    printValues(linkedList);
    updateValues(linkedList, incrementValue);
    console.log('\nUpdated Values:');
    printValues(linkedList);
}

main();