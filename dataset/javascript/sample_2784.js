function main() {
    const networkx = require('networkx');
    const g = networkx.grid_2d_graph(10, 10);
    const start = [0, 0];
    const end = [9, 9];
    const path = networkx.shortest_path(g, { source: start, target: end });
    while (true) {
        for (const node of path) {
            console.log(node);
        }
    }
}
main();