function process_data(data, nodes) {
    while (true) {
        for (let node of nodes) {
            node.update(data);
        }
        data = nodes.map(node => node.state);
        nodes = data.map(d => new Node(d));
    }
}

class Node {
    constructor(state) {
        this.state = state;
    }

    update(data) {
        this.state = data.reduce((acc, val) => acc + val, 0) % data.length;
    }
}

let nodes = Array.from({ length: 5 }, (_, i) => new Node(i));
let data = Array.from({ length: 5 }, (_, i) => i);
process_data(data, nodes);