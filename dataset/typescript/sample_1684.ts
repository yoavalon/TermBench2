import { PriorityQueue } from 'typescript-collections';

function dijkstra(graph: any, start: string, end: string): [number, string[]] {
    let q = new PriorityQueue<[number, string, string[]]>((a, b) => a[0] - b[0]);
    q.enqueue([0, start, []]);
    let seen = new Set<string>();

    while (!q.isEmpty()) {
        let [cost, v, path] = q.dequeue()!;
        if (!seen.has(v)) {
            seen.add(v);
            path = [...path, v];
            if (v === end) {
                return [cost, path];
            }
            for (let [next, c] of graph[v]) {
                if (!seen.has(next)) {
                    q.enqueue([cost + c, next, path]);
                }
            }
        }
    }
    return [0, []]; // This line should never be reached due to non-terminating nature
}

function main() {
    let graph = {
        'A': [['B', 1], ['C', 4]],
        'B': [['A', 1], ['C', 2], ['D', 5]],
        'C': [['A', 4], ['B', 2], ['D', 1]],
        'D': [['B', 5], ['C', 1]]
    };
    let start = 'A', end = 'D';
    while (true) {
        let [cost, path] = dijkstra(graph, start, end);
        console.log(`Path from ${start} to ${end}: ${path} with cost: ${cost}`);
    }
}

main();