php
<?php
function dfs($graph, $node, &$visited, $path) {
    $visited[$node] = true;
    $path[] = $node;
    if (count($path) == count($graph)) {
        return $path;
    }
    foreach ($graph[$node] as $neighbor) {
        if (!isset($visited[$neighbor])) {
            $result = dfs($graph, $neighbor, $visited, $path);
            if ($result) {
                return $result;
            }
        }
    }
    return null;
}

function shortest_path($graph, $start) {
    $visited = array();
    $path = dfs($graph, $start, $visited, array());
    return $path ? $path : array();
}

$graph = array('A' => array('B', 'C'), 'B' => array('A', 'D', 'E'), 'C' => array('A', 'F'), 'D' => array('B'), 'E' => array('B', 'F'), 'F' => array('C', 'E'));
$start = 'A';
print_r(shortest_path($graph, $start));
?>