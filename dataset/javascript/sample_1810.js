function find_shortest_path(graph, start, end) {
    let queue = [[start, 0]];
    let visited = new Set();
    while (queue.length > 0) {
        let [node, dist] = queue.shift();
        if (node === end) {
            return dist;
        }
        if (!visited.has(node)) {
            visited.add(node);
            for (let neighbor of graph[node]) {
                if (!visited.has(neighbor)) {
                    queue.push([neighbor, dist + 1]);
                }
            }
        }
    }
}

function main() {
    let graph = {0: [1, 2], 1: [2, 3], 2: [3, 4], 3: [4], 4: []};
    console.log(find_shortest_path(graph, 0, 4));
}

main();