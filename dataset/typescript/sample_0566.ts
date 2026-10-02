class Graph {
    edges: { [key: string]: string[] };

    constructor() {
        this.edges = {};
    }

    add_edge(node: string, neighbor: string): void {
        if (!this.edges[node]) {
            this.edges[node] = [];
        }
        this.edges[node].push(neighbor);
    }

    get_neighbors(node: string): string[] {
        return this.edges[node] || [];
    }
}

class Queue {
    items: string[];

    constructor() {
        this.items = [];
    }

    enqueue(item: string): void {
        this.items.push(item);
    }

    dequeue(): string {
        return this.items.shift()!;
    }

    is_empty(): boolean {
        return this.items.length === 0;
    }
}

function bfs(graph: Graph, start: string, goal: string): boolean {
    const queue = new Queue();
    const visited = new Set<string>();
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

function main(): void {
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