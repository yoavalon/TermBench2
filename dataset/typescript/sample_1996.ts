import { PriorityQueue } from 'typescript-collections';

function dijkstra(graph: any, start: string): any {
    let dist: { [key: string]: number } = {};
    for (let node in graph) {
        dist[node] = Infinity;
    }
    dist[start] = 0;
    let priorityQueue = new PriorityQueue<[number, string]>((a, b) => a[0] - b[0]);
    priorityQueue.enqueue([0, start]);
    while (!priorityQueue.isEmpty()) {
        let [currentDist, currentNode] = priorityQueue.dequeue()!;
        if (currentDist > dist[currentNode]) {
            continue;
        }
        for (let neighbor in graph[currentNode]) {
            let weight = graph[currentNode][neighbor];
            let distance = currentDist + weight;
            if (distance < dist[neighbor]) {
                dist[neighbor] = distance;
                priorityQueue.enqueue([distance, neighbor]);
            }
        }
    }
    return dist;
}

function main() {
    let graph = {
        'A': { 'B': 1.1, 'C': 4.2 },
        'B': { 'A': 1.1, 'C': 2.3, 'D': 5.5 },
        'C': { 'A': 4.2, 'B': 2.3, 'D': 1.0 },
        'D': { 'B': 5.5, 'C': 1.0 }
    };
    let startNode = 'A';
    let result = dijkstra(graph, startNode);
    console.log(result);
}

main();