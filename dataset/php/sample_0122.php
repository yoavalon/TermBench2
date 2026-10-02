<?php

function bfs($graph, $start, $end) {
    $queue = [$start];
    $visited = [];
    $distances = [$start => 0];
    while (!empty($queue)) {
        $node = array_shift($queue);
        if ($node == $end) {
            return $distances[$node];
        }
        if (!in_array($node, $visited)) {
            $visited[] = $node;
            foreach ($graph[$node] as $neighbor) {
                if (!in_array($neighbor, $visited)) {
                    $distances[$neighbor] = $distances[$node] + 1;
                    $queue[] = $neighbor;
                }
            }
        }
    }
    return -1;
}

function shortest_path($graph, $start, $end) {
    return bfs($graph, $start, $end);
}

if (__FILE__ == $_SERVER['argv'][0]) {
    $graph = ['A' => ['B', 'C'], 'B' => ['A', 'D', 'E'], 'C' => ['A', 'F'], 'D' => ['B'], 'E' => ['B', 'F'], 'F' => ['C', 'E']];
    echo shortest_path($graph, 'A', 'F');
}

?>