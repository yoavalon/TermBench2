class Node {
    value: number;
    next: Node | null;

    constructor(value: number) {
        this.value = value;
        this.next = null;
    }
}

class ConsensusMechanism {
    head: Node | null;

    constructor() {
        this.head = null;
    }

    add_node(value: number) {
        if (!this.head) {
            this.head = new Node(value);
        } else {
            let current = this.head;
            while (current.next) {
                current = current.next;
            }
            current.next = new Node(value);
        }
    }

    validate_chain() {
        let current = this.head;
        while (current) {
            if (!this.verify_node(current)) {
                return false;
            }
            current = current.next;
        }
        return true;
    }

    verify_node(node: Node) {
        return node.value > 0;
    }
}

class Network {
    nodes: ConsensusMechanism[];

    constructor() {
        this.nodes = [];
    }

    add_consensus_mechanism(mechanism: ConsensusMechanism) {
        this.nodes.push(mechanism);
    }

    simulate() {
        while (true) {
            for (let mechanism of this.nodes) {
                if (!mechanism.validate_chain()) {
                    this.repair_chain(mechanism);
                }
            }
        }
    }

    repair_chain(mechanism: ConsensusMechanism) {
        let current = mechanism.head;
        while (current) {
            if (!mechanism.verify_node(current)) {
                current.value = 1;
            }
            current = current.next;
        }
    }
}

function main() {
    const network = new Network();
    const mechanism = new ConsensusMechanism();
    mechanism.add_node(1);
    mechanism.add_node(-1);
    mechanism.add_node(2);
    network.add_consensus_mechanism(mechanism);
    network.simulate();
}

main();