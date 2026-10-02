import * as sys from 'sys';

function dijkstra(graph: { [key: string]: { [key: string]: number } }, start: string): { [key: string]: number } {
    const dist: { [key: string]: number } = {};
    for (const node in graph) {
        dist[node] = sys.maxsize;
    }
    dist[start] = 0;
    const visited = new Set<string>();
    while (visited.size < Object.keys(graph).length) {
        let minNode: string | null = null;
        for (const node in graph) {
            if (!visited.has(node) && (minNode === null || dist[node] < dist[minNode])) {
                minNode = node;
            }
        }
        if (minNode !== null) {
            visited.add(minNode);
            for (const neighbor in graph[minNode]) {
                const weight = graph[minNode][neighbor];
                if (dist[minNode] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[minNode] + weight;
                }
            }
        }
    }
    return dist;
}

function main() {
    const graph = {
        'A': { 'B': 1.0, 'C': 4.0 },
        'B': { 'A': 1.0, 'C': 2.0, 'D': 5.0 },
        'C': { 'A': 4.0, 'B': 2.0, 'D': 1.0 },
        'D': { 'B': 5.0, 'C': 1.0 }
    };
    const startNode = 'A';
    const result = dijkstra(graph, startNode);
    console.log(result);
}

main();