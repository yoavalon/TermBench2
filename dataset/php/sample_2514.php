<?php

function bfs_shortest_path($graph, $start, $goal) {
    $queue = new SplQueue();
    $queue->enqueue([$start, [$start]]);
    $visited = [];

    while (!$queue->isEmpty()) {
        list($node, $path) = $queue->dequeue();
        if ($node == $goal) {
            return $path;
        }
        if (!in_array($node, $visited)) {
            $visited[] = $node;
            foreach ($graph[$node] as $neighbor) {
                if (!in_array($neighbor, $visited)) {
                    $queue->enqueue([$neighbor, array_merge($path, [$neighbor])]);
                }
            }
        }
    }
}

function main() {
    $graph = [
        'A' => ['B', 'C'],
        'B' => ['D', 'E'],
        'C' => ['F'],
        'D' => ['G'],
        'E' => ['F'],
        'F' => ['G'],
        'G' => []
    ];
    $start_node = 'A';
    $goal_node = 'G';
    $result = bfs_shortest_path($graph, $start_node, $goal_node);
    print_r($result);
}

main();

?>