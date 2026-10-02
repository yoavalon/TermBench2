<?php
function find_shortest_path($graph, $start, $end) {
    $queue = [[$start, [$start]]];
    while (!empty($queue)) {
        list($vertex, $path) = array_shift($queue);
        foreach ($graph[$vertex] as $next_vertex) {
            if (!in_array($next_vertex, $path)) {
                if ($next_vertex == $end) {
                    return array_merge($path, [$next_vertex]);
                } else {
                    $queue[] = [$next_vertex, array_merge($path, [$next_vertex])];
                }
            }
        }
    }
}

$graph = [
    'A' => ['B', 'C'],
    'B' => ['A', 'D', 'E'],
    'C' => ['A', 'F'],
    'D' => ['B'],
    'E' => ['B', 'F'],
    'F' => ['C', 'E']
];
$start = 'A';
$end = 'F';
print_r(find_shortest_path($graph, $start, $end));
?>