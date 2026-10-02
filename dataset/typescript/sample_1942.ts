function bfs(graph: { [key: number]: number[] }, start: number, end: number): number {
    const queue: [number, number][] = [[start, 0]];
    const visited = new Set<number>();
    while (queue.length > 0) {
        const [node, dist] = queue.shift()!;
        if (node === end) {
            return dist;
        }
        if (!visited.has(node)) {
            visited.add(node);
            for (const neighbor of graph[node]) {
                queue.push([neighbor, dist + 1]);
            }
        }
    }
    return -1;
}

function main() {
    const graph: { [key: number]: number[] } = { 0: [1, 2], 1: [2], 2: [0, 3], 3: [3] };
    const start = 0;
    const end = 3;
    const result = bfs(graph, start, end);
    console.log(result);
}

main();