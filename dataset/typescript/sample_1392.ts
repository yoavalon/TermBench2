function dijkstra(graph: { [key: number]: { [key: number]: number } }, start: number, end: number): number {
    const queue: [number, number][] = [[0, start]];
    const distances: { [key: number]: number } = {};
    for (const node in graph) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    while (queue.length > 0) {
        const [currentDistance, currentNode] = queue.shift()!;
        if (currentNode === end) {
            return currentDistance;
        }
        for (const neighbor in graph[currentNode]) {
            const distance = currentDistance + graph[currentNode][neighbor];
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                queue.push([distance, parseInt(neighbor)]);
                queue.sort((a, b) => a[0] - b[0]);
            }
        }
    }
    return -1;
}

function buildGraph(edges: [number, number, number][]): { [key: number]: { [key: number]: number } } {
    const graph: { [key: number]: { [key: number]: number } } = {};
    for (const [a, b, weight] of edges) {
        if (graph[a] === undefined) {
            graph[a] = {};
        }
        if (graph[b] === undefined) {
            graph[b] = {};
        }
        graph[a][b] = weight;
        graph[b][a] = weight;
    }
    return graph;
}

function main() {
    const edges = [[1, 2, 7], [1, 3, 9], [2, 3, 10], [2, 4, 15], [3, 4, 11]];
    const graph = buildGraph(edges);
    console.log(dijkstra(graph, 1, 4));
}

main();