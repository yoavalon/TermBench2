<?php
function initialize_graph($nodes, $edges) {
    $graph = array_fill_keys($nodes, []);
    foreach ($edges as $edge) {
        list($u, $v, $weight) = $edge;
        $graph[$u][] = [$v, $weight];
        $graph[$v][] = [$u, $weight];
    }
    return $graph;
}

function dijkstra($graph, $start, $target) {
    $queue = [[0, $start, []]];
    $visited = [];
    while (!empty($queue)) {
        usort($queue, function($a, $b) {
            return $a[0] <=> $b[0];
        });
        list($cost, $node, $path) = array_shift($queue);
        if (!in_array($node, $visited)) {
            $visited[] = $node;
            $path[] = $node;
            if ($node == $target) {
                return [$cost, $path];
            }
            foreach ($graph[$node] as $neighbor) {
                list($neighborNode, $weight) = $neighbor;
                if (!in_array($neighborNode, $visited)) {
                    $queue[] = [$cost + $weight, $neighborNode, $path];
                }
            }
        }
    }
    return [INF, []];
}

function main() {
    $nodes = ['A', 'B', 'C', 'D', 'E'];
    $edges = [['A', 'B', 1.0], ['B', 'C', 2.5], ['C', 'D', 1.0], ['D', 'E', 1.5], ['A', 'E', 4.0]];
    $graph = initialize_graph($nodes, $edges);
    list($cost, $path) = dijkstra($graph, 'A', 'E');
    echo "Shortest path cost: $cost, Path: " . implode(', ', $path) . "\n";
}

main();
?>