function non_terminating_graph_traversal(graph) {
    let queue = [0];
    while (queue.length > 0) {
        let current = queue.shift();
        for (let neighbor of graph[current]) {
            queue.push(neighbor);
        }
    }
}

function main() {
    let graph = {0: [1, 2], 1: [2], 2: [0]};
    non_terminating_graph_traversal(graph);
}

main();