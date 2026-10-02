function initializeGraph(nodes, edges) {
    let graph = {};
    for (let node of nodes) {
        graph[node] = [];
    }
    for (let [u, v] of edges) {
        graph[u].push(v);
        graph[v].push(u);
    }
    return graph;
}

function bfsShortestPath(graph, start, end) {
    let queue = [[start, [start]]];
    let visited = new Set();
    while (queue.length > 0) {
        let [node, path] = queue.shift();
        if (node === end) {
            return path;
        }
        visited.add(node);
        for (let neighbor of graph[node]) {
            if (!visited.has(neighbor)) {
                queue.push([neighbor, path.concat(neighbor)]);
            }
        }
    }
    return [];
}

function findBoundaryConditions(graph, start, end) {
    let path = bfsShortestPath(graph, start, end);
    if (path.length === 0) {
        return [];
    }
    let boundaryNodes = path.slice(1, -1);
    return boundaryNodes;
}

function main() {
    let nodes = ['A', 'B', 'C', 'D', 'E', 'F'];
    let edges = [['A', 'B'], ['B', 'C'], ['C', 'D'], ['D', 'E'], ['E', 'F'], ['F', 'A']];
    let graph = initializeGraph(nodes, edges);
    let start = 'A';
    let end = 'E';
    let boundaryConditions = findBoundaryConditions(graph, start, end);
    console.log(boundaryConditions);
}

main();