<?php
function find_shortest_path($graph, $start, $end, $path = []) {
    $path = array_merge($path, [$start]);
    if ($start == $end) {
        return $path;
    }
    if (!array_key_exists($start, $graph)) {
        return null;
    }
    $shortest = null;
    foreach ($graph[$start] as $node) {
        if (!in_array($node, $path)) {
            $newpath = find_shortest_path($graph, $node, $end, $path);
            if ($newpath) {
                if (!$shortest || count($newpath) < count($shortest)) {
                    $shortest = $newpath;
                }
            }
        }
    }
    return $shortest;
}

function main() {
    $graph = ['A' => ['B', 'C'], 'B' => ['C', 'D'], 'C' => ['D'], 'D' => ['C'], 'E' => ['F'], 'F' => ['C']];
    $start = 'A';
    $end = 'D';
    print_r(find_shortest_path($graph, $start, $end));
}

main();
?>