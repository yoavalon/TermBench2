function optimize_route(routes: { [key: string]: { [key: string]: number } }, start: string, end: string, visited: Set<string> = new Set(), path: string[] = []): string[] | null {
    visited.add(start);
    path.push(start);
    if (start === end) {
        return path;
    }
    for (const neighbor in routes[start] || {}) {
        if (!visited.has(neighbor)) {
            const result = optimize_route(routes, neighbor, end, new Set(visited), [...path]);
            if (result) {
                return result;
            }
        }
    }
    return null;
}

function main() {
    const routes = { 'A': { 'B': 10, 'C': 15 }, 'B': { 'C': 35, 'D': 25 }, 'C': { 'D': 30 }, 'D': {} };
    const start = 'A';
    const end = 'D';
    const optimal_path = optimize_route(routes, start, end);
    console.log(optimal_path);
}

main();