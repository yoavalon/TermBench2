function bfs(graph: any, start: string, goal: string): string[] | null {
    let queue: [string, string[]][] = [[start, [start]]];
    while (queue.length > 0) {
        let [vertex, path] = queue.shift()!;
        for (let next of new Set(graph[vertex]).difference(new Set(path))) {
            if (next === goal) {
                return path.concat([next]);
            } else {
                queue.push([next, path.concat([next])]);
            }
        }
    }
    return null;
}

function find_path(graph: any, start: string, goal: string): string[] {
    let path = bfs(graph, start, goal);
    return path ? path : [];
}

function main() {
    let graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []};
    let start_node = 'A';
    let goal_node = 'F';
    let result = find_path(graph, start_node, goal_node);
    console.log(result);
}

main();