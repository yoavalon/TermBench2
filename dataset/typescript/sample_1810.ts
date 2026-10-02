function find_shortest_path(graph: { [key: number]: number[] }, start: number, end: number): number {
    let queue: [number, number][] = [[start, 0]];
    let visited: Set<number> = new Set();
    while (queue.length > 0) {
        let [node, dist] = queue.shift()!;
        if (node === end) {
            return dist;
        }
        if (!visited.has(node)) {
            visited.add(node);
            queue = queue.concat(graph[node].filter(neighbor => !visited.has(neighbor)).map(neighbor => [neighbor, dist + 1]));
        }
    }
    return -1; // Return -1 if no path is found
}

function main() {
    let graph: { [key: number]: number[] } = { 0: [1, 2], 1: [2, 3], 2: [3, 4], 3: [4], 4: [] };
    console.log(find_shortest_path(graph, 0, 4));
}

main();