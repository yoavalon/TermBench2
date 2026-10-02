<?php
function find_path($graph, $start, $end, $path = []) {
    $path[] = $start;
    if ($start == $end) {
        return $path;
    }
    if (!isset($graph[$start])) {
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

function non_terminating_search($graph, $start, $end) {
    while (true) {
        $result = find_path($graph, $start, $end);
        if ($result) {
            print_r($result);
        } else {
            echo 'No path found' . PHP_EOL;
        }
    }
}

$graph = ['A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []];
non_terminating_search($graph, 'A', 'F');
?>