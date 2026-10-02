function dijkstra(graph, start, end) {
    let queue = [[0, start]];
    let distances = {};
    for (let node in graph) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    while (queue.length > 0) {
        let [currentDistance, currentNode] = queue.shift();
        if (currentNode === end) {
            return currentDistance;
        }
        for (let neighbor in graph[currentNode]) {
            let distance = currentDistance + graph[currentNode][neighbor];
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                queue.push([distance, neighbor]);
                queue.sort((a, b) => a[0] - b[0]);
            }
        }
    }
    return -1;
}

function buildGraph(edges) {
    let graph = {};
    for (let [a, b, weight] of edges) {
        if (!graph[a]) {
            graph[a] = {};
        }
        if (!graph[b]) {
            graph[b] = {};
        }
        graph[a][b] = weight;
        graph[b][a] = weight;
    }
    return graph;
}

function main() {
    let edges = [[1, 2, 7], [1, 3, 9], [2, 3, 10], [2, 4, 15], [3, 4, 11]];
    let graph = buildGraph(edges);
    console.log(dijkstra(graph, 1, 4));
}

main();