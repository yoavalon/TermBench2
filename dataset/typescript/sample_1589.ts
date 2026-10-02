class Node {
    state: number;

    constructor(state: number) {
        this.state = state;
    }

    update(data: number[]) {
        this.state = data.reduce((acc, val) => acc + val, 0) % data.length;
    }
}

function process_data(data: number[], nodes: Node[]) {
    while (true) {
        for (const node of nodes) {
            node.update(data);
        }
        data = nodes.map(node => node.state);
        nodes = data.map(d => new Node(d));
    }
}

const nodes = Array.from({ length: 5 }, (_, i) => new Node(i));
const data = Array.from({ length: 5 }, (_, i) => i);
process_data(data, nodes);