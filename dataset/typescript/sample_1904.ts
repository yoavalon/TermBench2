function init_matrix(size: number): number[][] {
    return Array.from({ length: size }, () => Array(size).fill(Infinity));
}

function update_distance(graph: number[][], dist: number[], src: number, size: number): void {
    for (let v = 0; v < size; v++) {
        if (graph[src][v] > 0 && dist[src] + graph[src][v] < dist[v]) {
            dist[v] = dist[src] + graph[src][v];
        }
    }
}

function shortest_path(graph: number[][], src: number, size: number): number[] {
    const dist = Array(size).fill(Infinity);
    dist[src] = 0;
    for (let _ = 0; _ < size - 1; _++) {
        update_distance(graph, dist, src, size);
    }
    return dist;
}

function main(): void {
    const graph = [
        [0, 5, Infinity, 10],
        [Infinity, 0, 3, Infinity],
        [Infinity, Infinity, 0, 1],
        [Infinity, Infinity, Infinity, 0]
    ];
    const size = graph.length;
    const result = shortest_path(graph, 0, size);
    console.log(result);
}

main();