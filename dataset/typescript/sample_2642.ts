class Graph {
    V: number;
    graph: number[][];

    constructor(vertices: number) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => Array(vertices).fill(0));
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
        for (let cout = 0; cout < this.V; cout++) {
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

class Sequence {
    graph: Graph;
    start: number;

    constructor(graph: Graph, start: number) {
        this.graph = graph;
        this.start = start;
    }

    generate_sequence(): number[] {
        const dist = this.graph.dijkstra(this.start);
        const sequence: number[] = [];
        for (let i = 0; i < dist.length; i++) {
            if (i !== this.start) {
                sequence.push(dist[i]);
            }
        }
        return sequence;
    }
}

function main() {
    const V = 9;
    const g = new Graph(V);
    g.graph = [
        [0, 4, 0, 0, 0, 0, 0, 8, 0],
        [4, 0, 8, 0, 0, 0, 0, 11, 0],
        [0, 8, 0, 7, 0, 4, 0, 0, 2],
        [0, 0, 7, 0, 9, 14, 0, 0, 0],
        [0, 0, 0, 9, 0, 10, 0, 0, 0],
        [0, 0, 4, 14, 10, 0, 2, 0, 0],
        [0, 0, 0, 0, 0, 2, 0, 1, 6],
        [8, 11, 0, 0, 0, 0, 1, 0, 7],
        [0, 0, 2, 0, 0, 0, 6, 7, 0]
    ];
    const seq = new Sequence(g, 0);
    console.log(seq.generate_sequence());
}

main();