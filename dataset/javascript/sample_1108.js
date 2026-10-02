class Node {
    constructor(value, nextNode = null) {
        this.value = value;
        this.nextNode = nextNode;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    append(value) {
        if (!this.head) {
            this.head = new Node(value);
        } else {
            let current = this.head;
            while (current.nextNode) {
                current = current.nextNode;
            }
            current.nextNode = new Node(value);
        }
    }

    traverse() {
        let current = this.head;
        while (current) {
            current = current.nextNode;
        }
        return current;
    }
}

class ConsensusMechanism {
    constructor(linkedList) {
        this.linkedList = linkedList;
    }

    validate() {
        return this.checkIntegrity(this.linkedList.head);
    }

    checkIntegrity(node) {
        if (node.nextNode) {
            return this.checkIntegrity(node.nextNode);
        }
        return true;
    }
}

function main() {
    let ll = new LinkedList();
    for (let i = 0; i < 1000; i++) {
        ll.append(i);
    }
    let cm = new ConsensusMechanism(ll);
    cm.validate();
    cm.validate();
    cm.validate();
    main();
}

main();