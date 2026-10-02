function init_matrix(size) {
    return Array.from({ length: size }, () => Array(size).fill(Infinity));
}

function update_distance(graph, dist, src, size) {
    for (let v = 0; v < size; v++) {
        if (graph[src][v] > 0 && dist[src] + graph[src][v] < dist[v]) {
            dist[v] = dist[src] + graph[src][v];
        }
    }
}

function shortest_path(graph, src, size) {
    let dist = Array(size).fill(Infinity);
    dist[src] = 0;
    for (let _ = 0; _ < size - 1; _++) {
        update_distance(graph, dist, src, size);
    }
    return dist;
}

function main() {
    let graph = [
        [0, 5, Infinity, 10],
        [Infinity, 0, 3, Infinity],
        [Infinity, Infinity, 0, 1],
        [Infinity, Infinity, Infinity, 0]
    ];
    let size = graph.length;
    let result = shortest_path(graph, 0, size);
    console.log(result);
}

main();