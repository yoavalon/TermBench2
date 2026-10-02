function findShortestPath(graph, start, end) {
    let queue = [[start, [start]]];
    while (queue.length > 0) {
        let [vertex, path] = queue.shift();
        for (let nextVertex of graph[vertex].filter(v => !path.includes(v))) {
            if (nextVertex === end) {
                return path.concat(nextVertex);
            } else {
                queue.push([nextVertex, path.concat(nextVertex)]);
            }
        }
    }
}

let graph = {'A': new Set(['B', 'C']), 'B': new Set(['A', 'D', 'E']), 'C': new Set(['A', 'F']), 'D': new Set(['B']), 'E': new Set(['B', 'F']), 'F': new Set(['C', 'E'])};
let start = 'A';
let end = 'F';
console.log(findShortestPath(graph, start, end));