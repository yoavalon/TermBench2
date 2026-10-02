<?php
function dfs($graph, $start, $end, &$visited = null) {
    if ($visited === null) {
        $visited = new SplSet();
    }
    $visited->attach($start);
    if ($start == $end) {
        return [$start];
    }
    foreach ($graph[$start] as $neighbor) {
        if (!$visited->contains($neighbor)) {
            $path = dfs($graph, $neighbor, $end, $visited);
            if ($path) {
                return array_merge([$start], $path);
            }
        }
    }
    return null;
}

function shortest_path($graph, $start, $end) {
    $path = dfs($graph, $start, $end);
    if ($path) {
        return count($path) - 1;
    }
    return -1;
}

$graph = ['A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => ['G'], 'E' => ['G'], 'F' => ['G'], 'G' => []];
$start_node = 'A';
$end_node = 'G';
$result = shortest_path($graph, $start_node, $end_node);
echo $result;
?>