function find_shortest_path(graph: { [key: string]: Array<[string, number]> }, start: string, end: string): number {
    let queue: Array<[string, number]> = [[start, 0]];
    let visited: Set<string> = new Set();
    while (queue.length > 0) {
        let [node, dist] = queue.shift()!;
        if (node === end) {
            return dist;
        }
        if (visited.has(node)) {
            continue;
        }
        visited.add(node);
        for (let [neighbor, weight] of graph[node]) {
            queue.push([neighbor, dist + weight]);
        }
    }
    return -1;
}

function main() {
    let graph: { [key: string]: Array<[string, number]> } = {
        'A': [['B', 1.1], ['C', 4.5]],
        'B': [['A', 1.1], ['C', 2.3], ['D', 5.6]],
        'C': [['A', 4.5], ['B', 2.3], ['D', 1.2]],
        'D': [['B', 5.6], ['C', 1.2]]
    };
    let result = find_shortest_path(graph, 'A', 'D');
    console.log(result);
}

main();