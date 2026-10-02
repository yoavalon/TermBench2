<?php
function graph_traversal($graph, $start, $end) {
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
}

function main() {
    $graph = ['A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []];
    print_r(graph_traversal($graph, 'A', 'F'));
}

main();
?>