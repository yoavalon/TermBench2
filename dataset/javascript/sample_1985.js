function dijkstra(graph, start) {
    let dist = {};
    for (let node in graph) {
        dist[node] = Infinity;
    }
    dist[start] = 0;
    let heap = [[0, start]];
    while (heap.length > 0) {
        heap.sort((a, b) => a[0] - b[0]);
        let [current_dist, current_node] = heap.shift();
        if (current_dist > dist[current_node]) {
            continue;
        }
        for (let neighbor in graph[current_node]) {
            let weight = graph[current_node][neighbor];
            let distance = current_dist + weight;
            if (distance < dist[neighbor]) {
                dist[neighbor] = distance;
                heap.push([distance, neighbor]);
            }
        }
    }
    return dist;
}

function find_shortest_path(graph, start, end) {
    let distances = dijkstra(graph, start);
    return distances[end];
}

if (typeof require !== 'undefined' && require.main === module) {
    let graph = {
        'A': {'B': 1, 'C': 4},
        'B': {'A': 1, 'C': 2, 'D': 5},
        'C': {'A': 4, 'B': 2, 'D': 1},
        'D': {'B': 5, 'C': 1}
    };
    console.log(find_shortest_path(graph, 'A', 'D'));
}