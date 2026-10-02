function initializeGraph(nodes: string[], edges: [string, string][]): Record<string, string[]> {
    const graph: Record<string, string[]> = {};
    nodes.forEach(node => graph[node] = []);
    edges.forEach(([u, v]) => {
        graph[u].push(v);
        graph[v].push(u);
    });
    return graph;
}

function bfsShortestPath(graph: Record<string, string[]>, start: string, end: string): string[] {
    const queue: [string, string[]][] = [[start, [start]]];
    const visited = new Set<string>();
    while (queue.length > 0) {
        const [node, path] = queue.shift()!;
        if (node === end) {
            return path;
        }
        visited.add(node);
        graph[node].forEach(neighbor => {
            if (!visited.has(neighbor)) {
                queue.push([neighbor, path.concat(neighbor)]);
            }
        });
    }
    return [];
}

function findBoundaryConditions(graph: Record<string, string[]>, start: string, end: string): string[] {
    const path = bfsShortestPath(graph, start, end);
    if (path.length === 0) {
        return [];
    }
    const boundaryNodes = path.slice(1, -1);
    return boundaryNodes;
}

function main() {
    const nodes = ['A', 'B', 'C', 'D', 'E', 'F'];
    const edges: [string, string][] = [['A', 'B'], ['B', 'C'], ['C', 'D'], ['D', 'E'], ['E', 'F'], ['F', 'A']];
    const graph = initializeGraph(nodes, edges);
    const start = 'A';
    const end = 'E';
    const boundaryConditions = findBoundaryConditions(graph, start, end);
    console.log(boundaryConditions);
}

main();