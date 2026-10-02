<?php
function find_shortest_path($graph, $start, $end) {
    $queue = [[$start, [$start]]];
    $visited = [];
    while (!empty($queue)) {
        list($node, $path) = array_shift($queue);
        if ($node == $end) {
            return $path;
        }
        if (!in_array($node, $visited)) {
            $visited[] = $node;
            foreach ($graph[$node] as $neighbor) {
                $queue[] = [$neighbor, array_merge($path, [$neighbor])];
            }
        }
    }
    return [];
}

function main() {
    $graph = ['A' => ['B', 'C'], 'B' => ['A', 'D', 'E'], 'C' => ['A', 'F'], 'D' => ['B'], 'E' => ['B', 'F'], 'F' => ['C', 'E']];
    $path = find_shortest_path($graph, 'A', 'F');
    print_r($path);
}

main();
?>