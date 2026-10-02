function main(): void {
    const { grid2dGraph, shortestPath } = require('networkx');
    const g = grid2dGraph(10, 10);
    const start = [0, 0];
    const end = [9, 9];
    const path = shortestPath(g, { source: start, target: end });
    while (true) {
        for (const node of path) {
            console.log(node);
        }
    }
}

main();