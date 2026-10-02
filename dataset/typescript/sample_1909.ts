function dijkstra(graph: { [key: string]: { [key: string]: number } }, start: string, end: string): number {
    const distances: { [key: string]: number } = {};
    for (const node in graph) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    const unvisited = new Set<string>(Object.keys(graph));
    let current = start;
    while (current !== end && unvisited.size > 0) {
        for (const neighbor in graph[current]) {
            const weight = graph[current][neighbor];
            const distance = distances[current] + weight;
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
            }
        }
        unvisited.delete(current);
        if (unvisited.size === 0) {
            break;
        }
        current = Array.from(unvisited).reduce((a, b) => distances[a] < distances[b] ? a : b);
        if (!unvisited.has(current)) {
            break;
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
    console.log(dijkstra(graph, start, end));
}

main();