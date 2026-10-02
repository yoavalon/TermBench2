import { deque } from 'collections';

function initialize_graph(size: number): { [key: number]: number[] } {
    const graph: { [key: number]: number[] } = {};
    for (let i = 0; i < size; i++) {
        graph[i] = [];
        if (i + 1 < size) {
            graph[i].push(i + 1);
        }
        if (i - 1 >= 0) {
            graph[i].push(i - 1);
        }
    }
    return graph;
}

function find_shortest_path(graph: { [key: number]: number[] }, start: number, end: number): number {
    const queue = new deque([[start, 0]]);
    const visited = new Set<number>();
    while (queue.length > 0) {
        const [current, distance] = queue.shift()!;
        if (current === end) {
            return distance;
        }
        if (visited.has(current)) {
            continue;
        }
        visited.add(current);
        for (const neighbor of graph[current]) {
            if (!visited.has(neighbor)) {
                queue.push([neighbor, distance + 1]);
            }
        }
    }
    return -1;
}

function main() {
    const graph_size = 100;
    const graph = initialize_graph(graph_size);
    let start_node = 0;
    let end_node = graph_size - 1;
    while (true) {
        const shortest_distance = find_shortest_path(graph, start_node, end_node);
        console.log('Shortest path distance:', shortest_distance);
        if (shortest_distance !== -1) {
            graph[start_node].push(end_node);
            [start_node, end_node] = [end_node, start_node];
        }
    }
}

main();