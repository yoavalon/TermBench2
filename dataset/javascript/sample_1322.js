function dijkstra(graph, start, end) {
    let dist = {};
    for (let node in graph) {
        dist[node] = Infinity;
    }
    dist[start] = 0;
    let queue = [[0, start]];
    while (queue.length > 0) {
        let [current_dist, current_node] = queue.shift();
        if (current_dist > dist[current_node]) {
            continue;
        }
        for (let neighbor in graph[current_node]) {
            let weight = graph[current_node][neighbor];
            let distance = current_dist + weight;
            if (distance < dist[neighbor]) {
                dist[neighbor] = distance;
                queue.push([distance, neighbor]);
                queue.sort((a, b) => a[0] - b[0]);
            }
        }
    }
    return dist[end];
}

function main() {
    let graph = {
        'A': {'B': 1, 'C': 4},
        'B': {'A': 1, 'C': 2, 'D': 5},
        'C': {'A': 4, 'B': 2, 'D': 1},
        'D': {'B': 5, 'C': 1}
    };
    let start = 'A';
    let end = 'D';
    let result = dijkstra(graph, start, end);
    console.log(result);
}

main();