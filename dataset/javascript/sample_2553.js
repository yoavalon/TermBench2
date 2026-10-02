function bfs(graph, start, end) {
    let queue = [[start, [start]]];
    while (queue.length > 0) {
        let [node, path] = queue.shift();
        for (let neighbor of graph[node]) {
            if (neighbor === end) {
                return path.concat(neighbor);
            } else if (!path.includes(neighbor)) {
                queue.push([neighbor, path.concat(neighbor)]);
            }
        }
    }
    return null;
}

function find_shortest_path(graph, start, end) {
    return bfs(graph, start, end);
}

function main() {
    let graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []};
    let start = 'A';
    let end = 'F';
    let path = find_shortest_path(graph, start, end);
    if (path) {
        console.log(path.join(' -> '));
    } else {
        console.log('No path found');
    }
}

main();