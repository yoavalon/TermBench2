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

function dijkstra(graph, start, target) {
    let queue = [[0, start, []]];
    let visited = new Set();
    while (queue.length > 0) {
        queue.sort((a, b) => a[0] - b[0]);
        let [cost, node, path] = queue.shift();
        if (!visited.has(node)) {
            visited.add(node);
            path = path.concat(node);
            if (node === target) {
                return [cost, path];
            }
            for (let [neighbor, weight] of graph[node]) {
                if (!visited.has(neighbor)) {
                    queue.push([cost + weight, neighbor, path]);
                }
            }
        }
    }
    return [Infinity, []];
}

function main() {
    let nodes = ['A', 'B', 'C', 'D', 'E'];
    let edges = [['A', 'B', 1.0], ['B', 'C', 2.5], ['C', 'D', 1.0], ['D', 'E', 1.5], ['A', 'E', 4.0]];
    let graph = initialize_graph(nodes, edges);
    let [cost, path] = dijkstra(graph, 'A', 'E');
    console.log(`Shortest path cost: ${cost}, Path: ${path}`);
}

main();