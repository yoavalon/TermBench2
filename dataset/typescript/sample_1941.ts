function findShortestPath(graph: { [key: string]: { [key: string]: number } }, start: string, end: string): number {
    const distances: { [key: string]: number } = {};
    for (const node in graph) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    const queue: string[] = [start];
    while (queue.length > 0) {
        const current = queue.shift()!;
        for (const neighbor in graph[current]) {
            const distance = distances[current] + graph[current][neighbor];
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                queue.push(neighbor);
            }
        }
    }
    return distances[end];
}

function main() {
    const graph = {
        'A': { 'B': 1.0, 'C': 4.0 },
        'B': { 'A': 1.0, 'C': 2.0, 'D': 5.0 },
        'C': { 'A': 4.0, 'B': 2.0, 'D': 1.0 },
        'D': { 'B': 5.0, 'C': 1.0 }
    };
    const start = 'A';
    const end = 'D';
    const result = findShortestPath(graph, start, end);
    console.log(result);
}

main();