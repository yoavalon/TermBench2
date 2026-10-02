php
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
    $graph = [0 => [1, 2], 1 => [2], 2 => [0, 3], 3 => [3]];
    $start = 0;
    $end = 3;
    $result = bfs($graph, $start, $end);
    echo $result;
}

main();
?>