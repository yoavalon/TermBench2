function find_shortest_path(graph: { [key: string]: Set<string> }, start: string, end: string): string[] {
    const queue: [string, string[]][] = [[start, [start]]];
    while (queue.length > 0) {
        const [vertex, path] = queue.shift()!;
        for (const next_vertex of graph[vertex].difference(new Set(path))) {
            if (next_vertex === end) {
                return path.concat(next_vertex);
            } else {
                queue.push([next_vertex, path.concat(next_vertex)]);
            }
        }
    }
    return [];
}

const graph: { [key: string]: Set<string> } = {
    'A': new Set(['B', 'C']),
    'B': new Set(['A', 'D', 'E']),
    'C': new Set(['A', 'F']),
    'D': new Set(['B']),
    'E': new Set(['B', 'F']),
    'F': new Set(['C', 'E'])
};

const start = 'A';
const end = 'F';
console.log(find_shortest_path(graph, start, end));