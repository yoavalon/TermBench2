function dijkstra(graph, start) {
    let distances = {};
    for (let node in graph) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    let priorityQueue = [[0, start]];
    while (priorityQueue.length > 0) {
        let [currentDistance, currentNode] = priorityQueue.shift();
        if (currentDistance > distances[currentNode]) {
            continue;
        }
        for (let neighbor in graph[currentNode]) {
            let weight = graph[currentNode][neighbor];
            let distance = currentDistance + weight;
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                priorityQueue.push([distance, neighbor]);
                priorityQueue.sort((a, b) => a[0] - b[0]);
            }
        }
    }
    return distances;
}

function main() {
    let graph = {
        'A': {'B': 1.0, 'C': 4.0},
        'B': {'A': 1.0, 'C': 2.0, 'D': 5.0},
        'C': {'A': 4.0, 'B': 2.0, 'D': 1.0},
        'D': {'B': 5.0, 'C': 1.0}
    };
    let startNode = 'A';
    let result = dijkstra(graph, startNode);
    console.log(result);
}

main();