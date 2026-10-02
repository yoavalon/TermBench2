<?php

function find_shortest_path($graph, $start, $end) {
    $queue = [[$start, 0]];
    $visited = [];
    while (!empty($queue)) {
        list($node, $dist) = array_shift($queue);
        if ($node == $end) {
            return $dist;
        }
        if (!in_array($node, $visited)) {
            $visited[] = $node;
            foreach ($graph[$node] as $neighbor) {
                if (!in_array($neighbor, $visited)) {
                    $queue[] = [$neighbor, $dist + 1];
                }
            }
        }
    }
}

function main() {
    $graph = [0 => [1, 2], 1 => [2, 3], 2 => [3, 4], 3 => [4], 4 => []];
    echo find_shortest_path($graph, 0, 4);
}

main();
?>