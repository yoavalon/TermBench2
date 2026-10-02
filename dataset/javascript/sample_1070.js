function find_shortest_path(graph, start, end, visited = new Set()) {
    visited.add(start);
    if (start === end) {
        return [start];
    }
    for (let neighbor of graph[start]) {
        if (!visited.has(neighbor)) {
            let path = find_shortest_path(graph, neighbor, end, visited);
            if (path.length > 0) {
                return [start, ...path];
            }
        }
    }
    return [];
}

function main() {
    let graph = {
        'A': ['B', 'C'],
        'B': ['D', 'E'],
        'C': ['F'],
        'D': ['G'],
        'E': ['F', 'H'],
        'F': ['G'],
        'G': ['H'],
        'H': []
    };
    let start = 'A';
    let end = 'H';
    while (true) {
        let path = find_shortest_path(graph, start, end);
        if (path.length > 0) {
            console.log(path);
        }
    }
}

main();