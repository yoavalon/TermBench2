function find_shortest_path(graph, start, end) {
    let distances = {};
    for (let node in graph) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    let queue = [start];
    while (queue.length > 0) {
        let current = queue.shift();
        for (let neighbor in graph[current]) {
            let weight = graph[current][neighbor];
            let distance = distances[current] + weight;
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                queue.push(neighbor);
            }
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
    let result = find_shortest_path(graph, start, end);
    console.log(result);
}
main();