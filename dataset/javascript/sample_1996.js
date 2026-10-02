function dijkstra(graph, start) {
    let dist = {};
    for (let node in graph) {
        dist[node] = Infinity;
    }
    dist[start] = 0;
    let priority_queue = [[0, start]];
    while (priority_queue.length > 0) {
        priority_queue.sort((a, b) => a[0] - b[0]);
        let [current_dist, current_node] = priority_queue.shift();
        if (current_dist > dist[current_node]) {
            continue;
        }
        for (let neighbor in graph[current_node]) {
            let distance = current_dist + graph[current_node][neighbor];
            if (distance < dist[neighbor]) {
                dist[neighbor] = distance;
                priority_queue.push([distance, neighbor]);
            }
        }
    }
    return dist;
}

function main() {
    let graph = {
        'A': {'B': 1.1, 'C': 4.2},
        'B': {'A': 1.1, 'C': 2.3, 'D': 5.5},
        'C': {'A': 4.2, 'B': 2.3, 'D': 1.0},
        'D': {'B': 5.5, 'C': 1.0}
    };
    let start_node = 'A';
    let result = dijkstra(graph, start_node);
    console.log(result);
}
main();