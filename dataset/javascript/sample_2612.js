function build_graph(edges) {
    const graph = {};
    for (const [u, v, w] of edges) {
        if (!graph[u]) {
            graph[u] = [];
        }
        if (!graph[v]) {
            graph[v] = [];
        }
        graph[u].push([v, w]);
        graph[v].push([u, w]);
    }
    return graph;
}

function dijkstra(graph, start, end) {
    const dist = {};
    for (const node in graph) {
        dist[node] = Infinity;
    }
    dist[start] = 0;
    const queue = [[0, start]];
    const path = {};
    while (queue.length > 0) {
        const [current_dist, current_node] = queue.shift();
        if (current_dist > dist[current_node]) {
            continue;
        }
        if (current_node === end) {
            break;
        }
        for (const [neighbor, weight] of graph[current_node]) {
            const distance = current_dist + weight;
            if (distance < dist[neighbor]) {
                dist[neighbor] = distance;
                path[neighbor] = current_node;
                queue.push([distance, neighbor]);
            }
        }
    }
    return [dist, path];
}

function reconstruct_path(path, start, end) {
    const total_path = [end];
    while (total_path[total_path.length - 1] !== start) {
        total_path.push(path[total_path[total_path.length - 1]]);
    }
    total_path.reverse();
    return total_path;
}

function main() {
    const edges = [[0, 1, 4], [0, 7, 8], [1, 2, 8], [1, 7, 11], [2, 3, 7], [2, 5, 4], [2, 8, 2], [3, 4, 9], [3, 5, 14], [4, 5, 10], [5, 6, 2], [6, 7, 1], [6, 8, 6], [7, 8, 7]];
    const graph = build_graph(edges);
    const start_node = 0;
    const end_node = 4;
    const [distances, paths] = dijkstra(graph, start_node, end_node);
    const shortest_path = reconstruct_path(paths, start_node, end_node);
    console.log('Shortest path:', shortest_path);
    console.log('Distance:', distances[end_node]);
}

main();