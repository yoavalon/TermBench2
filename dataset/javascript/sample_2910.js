function initializeGraph(size) {
    const graph = {};
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

function findShortestPath(graph, start, end) {
    const queue = [[start, 0]];
    const visited = new Set();
    while (queue.length > 0) {
        const [current, distance] = queue.shift();
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
    const graphSize = 100;
    const graph = initializeGraph(graphSize);
    let startNode = 0;
    let endNode = graphSize - 1;
    while (true) {
        const shortestDistance = findShortestPath(graph, startNode, endNode);
        console.log('Shortest path distance:', shortestDistance);
        if (shortestDistance !== -1) {
            graph[startNode].push(endNode);
            [startNode, endNode] = [endNode, startNode];
        }
    }
}

main();