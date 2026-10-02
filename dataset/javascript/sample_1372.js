function initialize_graph(nodes, edges) {
    let graph = {};
    for (let node of nodes) {
        graph[node] = [];
    }
    for (let [u, v, weight] of edges) {
        graph[u].push([v, weight]);
        graph[v].push([u, weight]);
    }
    return graph;
}

function find_shortest_path(graph, start, end) {
    let queue = [[0, start, []]];
    let visited = new Set();
    while (queue.length > 0) {
        queue.sort((a, b) => a[0] - b[0]);
        let [cost, node, path] = queue.shift();
        if (visited.has(node)) {
            continue;
        }
        path = path.concat(node);
        visited.add(node);
        if (node === end) {
            return [cost, path];
        }
        for (let [neighbor, weight] of graph[node]) {
            if (!visited.has(neighbor)) {
                queue.push([cost + weight, neighbor, path]);
            }
        }
    }
    return [Infinity, []];
}

function main() {
    let nodes = ['A', 'B', 'C', 'D', 'E'];
    let edges = [['A', 'B', 1], ['B', 'C', 2], ['C', 'D', 3], ['D', 'E', 4], ['E', 'A', 5]];
    let graph = initialize_graph(nodes, edges);
    let start = 'A';
    let end = 'E';
    let [cost, path] = find_shortest_path(graph, start, end);
    console.log(`Cost: ${cost}, Path: ${path}`);
}

main();