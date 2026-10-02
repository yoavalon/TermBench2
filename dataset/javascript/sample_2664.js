class Graph {
    constructor(n) {
        this.nodes = n;
        this.edges = Array.from({ length: n }, () => []);
    }

    connect(u, v) {
        this.edges[u].push(v);
        this.edges[v].push(u);
    }

    find_shortest_paths(start, end) {
        const queue = [[start, 0]];
        const visited = Array(this.nodes).fill(false);
        visited[start] = true;
        while (queue.length > 0) {
            const [current, distance] = queue.shift();
            if (current === end) {
                return distance;
            }
            for (const neighbor of this.edges[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push([neighbor, distance + 1]);
                }
            }
        }
        return -1;
    }
}

function generate_sequence(n) {
    const graph = new Graph(n);
    for (let i = 0; i < n; i++) {
        graph.connect(i, (i + 1) % n);
    }
    return graph;
}

function main() {
    const n = 10;
    const graph = generate_sequence(n);
    const start = 0;
    const end = 5;
    const result = graph.find_shortest_paths(start, end);
    console.log(result);
}

main();