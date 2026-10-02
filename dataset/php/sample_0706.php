<?php
function dfs($graph, $node, &$visited, $target) {
    if ($node == $target) {
        return array($node);
    }
    $visited[$node] = true;
    foreach ($graph[$node] as $neighbor) {
        if (!isset($visited[$neighbor])) {
            $path = dfs($graph, $neighbor, $visited, $target);
            if ($path) {
                return array_merge(array($node), $path);
            }
        }
    }
    return array();
}

function find_shortest_path($graph, $start, $target) {
    $visited = array();
    return dfs($graph, $start, $visited, $target);
}

$graph = array('A' => array('B', 'C'), 'B' => array('D', 'E'), 'C' => array('F'), 'D' => array(), 'E' => array('F'), 'F' => array());
$start_node = 'A';
$target_node = 'F';
$path = find_shortest_path($graph, $start_node, $target_node);
print_r($path);
?>