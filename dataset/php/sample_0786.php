<?php

function find_path($graph, $start, $end, $path = null) {
    if ($path === null) {
        $path = [];
    }
    $path[] = $start;
    if ($start == $end) {
        return $path;
    }
    if (!array_key_exists($start, $graph)) {
        return null;
    }
    foreach ($graph[$start] as $node) {
        if (!in_array($node, $path)) {
            $newpath = find_path($graph, $node, $end, $path);
            if ($newpath) {
                return $newpath;
            }
        }
    }
    return null;
}

function shortest_path($graph, $start, $end) {
    $path = find_path($graph, $start, $end);
    return $path ? count($path) - 1 : INF;
}

$g = [
    'A' => ['B', 'C'],
    'B' => ['D', 'E'],
    'C' => ['F'],
    'D' => [],
    'E' => ['F'],
    'F' => []
];

echo shortest_path($g, 'A', 'F');

?>