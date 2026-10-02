function dijkstra(graph: { [key: string]: { [key: string]: number } }, start: string): { [key: string]: number } {
    const dist: { [key: string]: number } = {};
    for (const node in graph) {
        dist[node] = Infinity;
    }
    dist[start] = 0;
    const heap: [number, string][] = [[0, start]];
    while (heap.length > 0) {
        const [current_dist, current_node] = heap.shift()!;
        if (current_dist > dist[current_node]) {
            continue;
        }
        for (const neighbor in graph[current_node]) {
            const weight = graph[current_node][neighbor];
            const distance = current_dist + weight;
            if (distance < dist[neighbor]) {
                dist[neighbor] = distance;
                heap.push([distance, neighbor]);
                heap.sort((a, b) => a[0] - b[0]);
            }
        }
    }
    return dist;
}

function find_shortest_path(graph: { [key: string]: { [key: string]: number } }, start: string, end: string): number {
    const distances = dijkstra(graph, start);
    return distances[end];
}

if (require.main === module) {
    const graph = {
        'A': { 'B': 1, 'C': 4 },
        'B': { 'A': 1, 'C': 2, 'D': 5 },
        'C': { 'A': 4, 'B': 2, 'D': 1 },
        'D': { 'B': 5, 'C': 1 }
    };
    console.log(find_shortest_path(graph, 'A', 'D'));
}