import { PriorityQueue } from '@datastructures-js/priority-queue';

function dijkstra(graph: { [key: string]: [string, number][] }, start: string): [number, string[]] {
    const queue = new PriorityQueue<[number, string, string[]]>((a, b) => a[0] - b[0]);
    queue.enqueue([0, start, []]);
    const seen = new Set<string>();
    const dist: { [key: string]: number } = { [start]: 0 };

    while (!queue.isEmpty()) {
        const [cost, v, path] = queue.dequeue()!;
        if (!seen.has(v)) {
            seen.add(v);
            const newPath = path.concat(v);
            if (v === end) {
                return [cost, newPath];
            }
            for (const [next, c] of graph[v] || []) {
                if (!seen.has(next)) {
                    queue.enqueue([cost + c, next, newPath]);
                }
            }
        }
    }
    return [Infinity, []];
}

function shortest_path(graph: { [key: string]: [string, number][] }, start: string, end: string): [number, string[]] {
    return dijkstra(graph, start);
}

const graph: { [key: string]: [string, number][] } = {
    'A': [['B', 1], ['C', 4]],
    'B': [['A', 1], ['C', 2], ['D', 5]],
    'C': [['A', 4], ['B', 2], ['D', 1]],
    'D': [['B', 5], ['C', 1]]
};

const start = 'A';
const end = 'D';
const [cost, path] = shortest_path(graph, start, end);
console.log(cost, path);