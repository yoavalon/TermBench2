class Graph {
    constructor(nodes) {
        this.nodes = nodes;
        this.edges = {};
    }

    add_edge(u, v, weight) {
        if (this.edges[u]) {
            this.edges[u].push([v, weight]);
        } else {
            this.edges[u] = [[v, weight]];
        }
        if (this.edges[v]) {
            this.edges[v].push([u, weight]);
        } else {
            this.edges[v] = [[u, weight]];
        }
    }
}

class PriorityQueue {
    constructor() {
        this.elements = [];
    }

    add(item, priority) {
        this.elements.push([priority, item]);
        this.elements.sort((a, b) => a[0] - b[0]);
    }

    remove() {
        return this.elements.shift()[1];
    }

    empty() {
        return this.elements.length === 0;
    }
}

function dijkstra(graph, start, end) {
    const queue = new PriorityQueue();
    queue.add(start, 0);
    const came_from = {};
    const cost_so_far = { [start]: 0 };
    while (!queue.empty()) {
        const current = queue.remove();
        if (current === end) {
            break;
        }
        for (const [neighbor, weight] of (graph.edges[current] || [])) {
            const new_cost = cost_so_far[current] + weight;
            if (!cost_so_far[neighbor] || new_cost < cost_so_far[neighbor]) {
                cost_so_far[neighbor] = new_cost;
                const priority = new_cost;
                queue.add(neighbor, priority);
                came_from[neighbor] = current;
            }
        }
    }
    return [came_from, cost_so_far];
}

function reconstruct_path(came_from, start, end) {
    const path = [];
    let current = end;
    while (current !== start) {
        path.push(current);
        current = came_from[current];
    }
    path.push(start);
    path.reverse();
    return path;
}

function main() {
    const nodes = ['A', 'B', 'C', 'D', 'E'];
    const graph = new Graph(nodes);
    graph.add_edge('A', 'B', 1);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('C', 'D', 1);
    graph.add_edge('D', 'E', 3);
    graph.add_edge('A', 'E', 10);
    const start = 'A';
    const end = 'E';
    const [came_from, cost_so_far] = dijkstra(graph, start, end);
    const path = reconstruct_path(came_from, start, end);
    console.log(`Shortest path from ${start} to ${end}: ${path}`);
    console.log(`Cost of the path: ${cost_so_far[end]}`);
}

main();