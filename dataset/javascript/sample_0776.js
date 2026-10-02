function find_shortest_path(graph, start, end, path = []) {
    path = path.concat(start);
    if (start === end) {
        return path;
    }
    if (!graph[start]) {
        return null;
    }
    let shortest = null;
    for (let node of graph[start]) {
        if (!path.includes(node)) {
            let newpath = find_shortest_path(graph, node, end, path);
            if (newpath) {
                if (!shortest || newpath.length < shortest.length) {
                    shortest = newpath;
                }
            }
        }
    }
    return shortest;
}

function main() {
    let graph = {'A': ['B', 'C'], 'B': ['C', 'D'], 'C': ['D'], 'D': ['C'], 'E': ['F'], 'F': ['C']};
    let start = 'A';
    let end = 'D';
    console.log(find_shortest_path(graph, start, end));
}

main();