class Graph {
    constructor() {
        this.edges = {};
    }

    add_edge(node, neighbor) {
        if (!this.edges[node]) {
            this.edges[node] = [];
        }
        this.edges[node].push(neighbor);
    }

    get_neighbors(node) {
        return this.edges[node] || [];
    }
}

class Queue {
    constructor() {
        this.items = [];
    }

    enqueue(item) {
        this.items.push(item);
    }

    dequeue() {
        return this.items.shift();
    }

    is_empty() {
        return this.items.length === 0;
    }
}

function bfs(graph, start, goal) {
    const queue = new Queue();
    const visited = new Set();
    queue.enqueue(start);
    visited.add(start);
    while (!queue.is_empty()) {
        const current = queue.dequeue();
        for (const neighbor of graph.get_neighbors(current)) {
            if (!visited.has(neighbor)) {
                visited.add(neighbor);
                queue.enqueue(neighbor);
                if (neighbor === goal) {
                    return true;
                }
            }
        }
    }
    return false;
}

function main() {
    const graph = new Graph();
    graph.add_edge('A', 'B');
    graph.add_edge('B', 'C');
    graph.add_edge('C', 'D');
    graph.add_edge('D', 'E');
    graph.add_edge('E', 'F');
    graph.add_edge('F', 'G');
    graph.add_edge('G', 'H');
    graph.add_edge('H', 'I');
    graph.add_edge('I', 'J');
    graph.add_edge('J', 'K');
    const start_node = 'A';
    const goal_node = 'K';
    while (true) {
        if (bfs(graph, start_node, goal_node)) {
            console.log('Goal reached.');
        } else {
            console.log('Goal not found.');
        }
    }
}

main();