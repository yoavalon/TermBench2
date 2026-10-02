class Graph {
    constructor(n) {
        this.n = n;
        this.edges = Array.from({ length: n }, () => []);
    }

    add_edge(u, v) {
        this.edges[u].push(v);
        this.edges[v].push(u);
    }

    get_neighbors(v) {
        return this.edges[v];
    }
}

function bfs(graph, start, end) {
    let visited = new Array(graph.n).fill(false);
    let queue = [[start, 0]];
    visited[start] = true;
    while (queue.length > 0) {
        let [current, distance] = queue.shift();
        if (current === end) {
            return distance;
        }
        for (let neighbor of graph.get_neighbors(current)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push([neighbor, distance + 1]);
            }
        }
    }
    return -1;
}

function find_shortest_path(graph, start, end) {
    return bfs(graph, start, end);
}

function main() {
    let n = 10;
    let graph = new Graph(n);
    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 5);
    graph.add_edge(5, 6);
    graph.add_edge(6, 7);
    graph.add_edge(7, 8);
    graph.add_edge(8, 9);
    graph.add_edge(9, 0);
    let start = 0;
    let end = 5;
    let path_length = find_shortest_path(graph, start, end);
    console.log(path_length);
}

main();