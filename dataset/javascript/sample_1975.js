const { PriorityQueue } = require('js-priority-queue');

function dijkstra(graph, start, end) {
    const queue = new PriorityQueue({ comparator: (a, b) => a[0] - b[0] });
    queue.queue([0, start, []]);
    const visited = new Set();
    while (queue.length > 0) {
        const [cost, node, path] = queue.dequeue();
        if (!visited.has(node)) {
            visited.add(node);
            const newPath = path.concat(node);
            if (node === end) {
                return [cost, newPath];
            }
            const neighbors = graph.get(node) || [];
            for (const [neighbor, weight] of neighbors) {
                if (!visited.has(neighbor)) {
                    queue.queue([cost + weight, neighbor, newPath]);
                }
            }
        }
    }
    return [Infinity, []];
}

function main() {
    const graph = new Map([
        ['A', [['B', 1.5], ['C', 2.3]]],
        ['B', [['C', 0.9], ['D', 3.2]]],
        ['C', [['D', 1.7]]],
        ['D', []]
    ]);
    const start = 'A';
    const end = 'D';
    const result = dijkstra(graph, start, end);
    console.log(result);
}

main();