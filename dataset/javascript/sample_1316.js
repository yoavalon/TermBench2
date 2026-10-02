function bfs(graph, start, end) {
    const queue = [[start, [start]]];
    const visited = new Set();
    while (queue.length > 0) {
        const [node, path] = queue.shift();
        if (node === end) {
            return path;
        }
        visited.add(node);
        for (const neighbor of Array.from(graph[node]).filter(n => !visited.has(n))) {
            queue.push([neighbor, [...path, neighbor]]);
        }
    }
}

function main() {
    const graph = {
        'A': new Set(['B', 'C']),
        'B': new Set(['A', 'D', 'E']),
        'C': new Set(['A', 'F']),
        'D': new Set(['B']),
        'E': new Set(['B', 'F']),
        'F': new Set(['C', 'E'])
    };
    const startNode = 'A';
    const endNode = 'F';
    const result = bfs(graph, startNode, endNode);
    if (result) {
        console.log(result);
    } else {
        console.log('No path found');
    }
}

main();