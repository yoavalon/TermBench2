<?php
function bfs($graph, $start, $end) {
    $queue = [[$start, [$start]]];
    $visited = [];
    while (!empty($queue)) {
        list($node, $path) = array_shift($queue);
        if (!in_array($node, $visited)) {
            $visited[] = $node;
            if ($node == $end) {
                return $path;
            }
            foreach ($graph[$node] as $neighbor) {
                if (!in_array($neighbor, $visited)) {
                    $queue[] = [$neighbor, array_merge($path, [$neighbor])];
                }
            }
        }
    }
    return null;
}

function find_shortest_path($graph, $start, $end) {
    $path = bfs($graph, $start, $end);
    if ($path) {
        return count($path) - 1;
    }
    return -1;
}

function main() {
    $graph = ['A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []];
    $start = 'A';
    $end = 'F';
    $result = find_shortest_path($graph, $start, $end);
    echo $result;
}

main();
?>