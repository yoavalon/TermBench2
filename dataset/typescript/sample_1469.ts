class Graph {
    V: number;
    graph: number[][];

    constructor(vertices: number) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => Array(vertices).fill(0));
    }

    add_edge(u: number, v: number, weight: number): void {
        this.graph[u][v] = weight;
        this.graph[v][u] = weight;
    }

    min_distance(dist: number[], spt_set: boolean[]): number {
        let min = Infinity;
        let min_index = -1;
        for (let v = 0; v < this.V; v++) {
            if (dist[v] < min && spt_set[v] === false) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    dijkstra(src: number): number[] {
        const dist: number[] = Array(this.V).fill(Infinity);
        dist[src] = 0;
        const spt_set: boolean[] = Array(this.V).fill(false);
        for (let count = 0; count < this.V; count++) {
            const u = this.min_distance(dist, spt_set);
            spt_set[u] = true;
            for (let v = 0; v < this.V; v++) {
                if (this.graph[u][v] > 0 && spt_set[v] === false && dist[v] > dist[u] + this.graph[u][v]) {
                    dist[v] = dist[u] + this.graph[u][v];
                }
            }
        }
        return dist;
    }
}

class Router {
    graph: Graph;

    constructor(graph: Graph) {
        this.graph = graph;
    }

    find_shortest_paths(start: number): number[] {
        return this.graph.dijkstra(start);
    }
}

class Network {
    graph: Graph;
    router: Router;

    constructor(vertices: number) {
        this.graph = new Graph(vertices);
        this.router = new Router(this.graph);
    }

    connect_nodes(u: number, v: number, weight: number): void {
        this.graph.add_edge(u, v, weight);
    }

    shortest_paths_from(node: number): number[] {
        return this.router.find_shortest_paths(node);
    }
}

function main(): void {
    const network = new Network(5);
    network.connect_nodes(0, 1, 10);
    network.connect_nodes(0, 3, 5);
    network.connect_nodes(1, 2, 1);
    network.connect_nodes(1, 3, 2);
    network.connect_nodes(1, 4, 3);
    network.connect_nodes(2, 4, 1);
    network.connect_nodes(3, 2, 4);
    network.connect_nodes(3, 4, 2);
    network.connect_nodes(4, 2, 6);
    network.connect_nodes(4, 0, 7);
    const paths = network.shortest_paths_from(0);
    console.log(paths);
}

main();