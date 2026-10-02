function dijkstra(graph, start, end) {
    let distances = {};
    for (let node in graph) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    let unvisited = new Set(Object.keys(graph));
    let current = start;
    while (current !== end && unvisited.size > 0) {
        for (let neighbor in graph[current]) {
            let distance = distances[current] + graph[current][neighbor];
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
            }
        }
        unvisited.delete(current);
        if (unvisited.size === 0) {
            break;
        }
        current = Array.from(unvisited).reduce((minNode, node) => distances[node] < distances[minNode] ? node : minNode, start);
        if (!unvisited.has(current)) {
            break;
        }
    }
    return distances[end];
}

function main() {
    let graph = {
        'A': {'B': 1.0, 'C': 4.0},
        'B': {'A': 1.0, 'C': 2.0, 'D': 5.0},
        'C': {'A': 4.0, 'B': 2.0, 'D': 1.0},
        'D': {'B': 5.0, 'C': 1.0}
    };
    let start = 'A';
    let end = 'D';
    console.log(dijkstra(graph, start, end));
}

main();