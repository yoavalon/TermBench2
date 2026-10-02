function optimize_route(routes, start, end, visited = new Set(), path = []) {
    visited.add(start);
    path.push(start);
    if (start === end) {
        return path;
    }
    for (let neighbor in routes[start] || {}) {
        if (!visited.has(neighbor)) {
            let result = optimize_route(routes, neighbor, end, new Set(visited), path.slice());
            if (result) {
                return result;
            }
        }
    }
    return null;
}

function main() {
    let routes = {'A': {'B': 10, 'C': 15}, 'B': {'C': 35, 'D': 25}, 'C': {'D': 30}, 'D': {}};
    let start = 'A';
    let end = 'D';
    let optimal_path = optimize_route(routes, start, end);
    console.log(optimal_path);
}

main();