class Graph {
    constructor(nodes) {
        this.nodes = nodes;
        this.adj_list = {};
        for (let node of nodes) {
            this.adj_list[node] = [];
        }
    }

    add_edge(node1, node2) {
        this.adj_list[node1].push(node2);
        this.adj_list[node2].push(node1);
    }
}

class ShortestPathFinder {
    constructor(graph) {
        this.graph = graph;
    }

    bfs(start, end) {
        let queue = [[start, 0]];
        let visited = new Set();
        while (queue.length > 0) {
            let [node, dist] = queue.shift();
            if (node === end) {
                return dist;
            }
            if (!visited.has(node)) {
                visited.add(node);
                for (let neighbor of this.graph.adj_list[node]) {
                    queue.push([neighbor, dist + 1]);
                }
            }
        }
        return -1;
    }
}

function main() {
    let nodes = [0, 1, 2, 3, 4, 5, 6];
    let graph = new Graph(nodes);
    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 5);
    graph.add_edge(5, 6);
    graph.add_edge(0, 3);
    graph.add_edge(3, 6);
    let spf = new ShortestPathFinder(graph);
    let result = spf.bfs(0, 6);
    console.log(result);
}

main();