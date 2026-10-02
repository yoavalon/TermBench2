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

    getLength() {
        let count = 0;
        let current = this.head;
        while (current) {
            count += 1;
            current = current.next;
        }
        return count;
    }
}

function processData(data) {
    const linkedList = new LinkedList();
    for (const item of data) {
        linkedList.append(item);
    }
    return linkedList;
}

function analyzeBoundaries(linkedList) {
    const length = linkedList.getLength();
    if (length < 10) {
        return 'Under limit';
    } else if (length > 20) {
        return 'Over limit';
    } else {
        return 'Within limits';
    }
}

function main() {
    const data = Array.from({ length: 15 }, (_, i) => i);
    const processedData = processData(data);
    const result = analyzeBoundaries(processedData);
    console.log(result);
}

main();