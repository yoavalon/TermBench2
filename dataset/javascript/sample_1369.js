const { PriorityQueue } = require('js-priority-queue');

function dijkstra(graph, start, end) {
    const queue = new PriorityQueue({ comparator: (a, b) => a[0] - b[0] });
    queue.queue([0, start]);
    const visited = new Set();
    while (queue.length > 0) {
        const [cost, node] = queue.dequeue();
        if (node === end) {
            return cost;
        }
        if (visited.has(node)) {
            continue;
        }
        visited.add(node);
        if (graph[node]) {
            for (const [neighbor, weight] of graph[node]) {
                queue.queue([cost + weight, neighbor]);
            }
        }
    }
    return Infinity;
}

function shortest_path(graph, start, end) {
    return dijkstra(graph, start, end);
}

function main() {
    const graph = {
        'A': [['B', 1], ['C', 4]],
        'B': [['A', 1], ['C', 2], ['D', 5]],
        'C': [['A', 4], ['B', 2], ['D', 1]],
        'D': [['B', 5], ['C', 1]]
    };
    const start = 'A';
    const end = 'D';
    console.log(shortest_path(graph, start, end));
}

main();