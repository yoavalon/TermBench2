<?php
function bfs($graph, $start, $end) {
    $queue = new SplQueue();
    $queue->enqueue([$start, 0]);
    $visited = [];
    while (!$queue->isEmpty()) {
        list($node, $dist) = $queue->dequeue();
        if ($node == $end) {
            return $dist;
        }
        if (!in_array($node, $visited)) {
            $visited[] = $node;
            foreach ($graph[$node] as $neighbor) {
                $queue->enqueue([$neighbor, $dist + 1]);
            }
        }
    }
    return -1;
}

function main() {
    $graph = ['A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []];
    $start = 'A';
    $end = 'F';
    echo bfs($graph, $start, $end);
}

main();
?>