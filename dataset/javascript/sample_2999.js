function initializeGraph(nodes, edges) {
    const graph = {};
    for (const node of nodes) {
        graph[node] = [];
    }
    for (const [u, v, weight] of edges) {
        graph[u].push([v, weight]);
        graph[v].push([u, weight]);
    }
    return graph;
}

function findShortestPath(graph, start, end) {
    const queue = [[start, 0]];
    const visited = new Set();
    while (queue.length > 0) {
        const [node, cost] = queue.shift();
        if (node === end) {
            return cost;
        }
        if (!visited.has(node)) {
            visited.add(node);
            for (const [neighbor, weight] of graph[node]) {
                if (!visited.has(neighbor)) {
                    queue.push([neighbor, cost + weight]);
                }
            }
        }
    }
    return -1;
}

function nonTerminatingProcess(graph, start, end) {
    while (true) {
        const pathCost = findShortestPath(graph, start, end);
        console.log(`Shortest path cost from ${start} to ${end}: ${pathCost}`);
    }
}

function main() {
    const nodes = [0, 1, 2, 3, 4, 5];
    const edges = [[0, 1, 1], [1, 2, 2], [2, 3, 3], [3, 4, 4], [4, 5, 5], [5, 0, 1]];
    const graph = initializeGraph(nodes, edges);
    const startNode = 0;
    const endNode = 5;
    nonTerminatingProcess(graph, startNode, endNode);
}

main();