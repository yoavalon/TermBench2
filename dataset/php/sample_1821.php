<?php
function find_shortest_path($graph, $start, $end) {
    $queue = [[$start, 0, [$start]]];
    while (!empty($queue)) {
        list($node, $cost, $visited) = array_shift($queue);
        if ($node == $end) {
            return $cost;
        }
        foreach ($graph[$node] ?? [] as $neighbor => $weight) {
            if (!in_array($neighbor, $visited)) {
                $queue[] = [$neighbor, $cost + $weight, array_merge($visited, [$neighbor])];
            }
        }
    }
    return -1;
}
$graph = [
    'A' => ['B' => 1.0, 'C' => 4.0],
    'B' => ['A' => 1.0, 'D' => 2.0],
    'C' => ['A' => 4.0, 'D' => 1.0],
    'D' => ['B' => 2.0, 'C' => 1.0]
];
echo find_shortest_path($graph, 'A', 'D');
?>