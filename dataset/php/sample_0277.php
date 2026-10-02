<?php
function initialize_graph($nodes, $edges) {
    $graph = array_fill_keys($nodes, array());
    foreach ($edges as list($u, $v)) {
        $graph[$u][] = $v;
        $graph[$v][] = $u;
    }
    return $graph;
}

function bfs_shortest_path($graph, $start, $end) {
    $queue = array(array($start, array($start)));
    $visited = array();
    while (!empty($queue)) {
        list($node, $path) = array_shift($queue);
        if ($node == $end) {
            return $path;
        }
        $visited[$node] = true;
        foreach ($graph[$node] as $neighbor) {
            if (!isset($visited[$neighbor])) {
                $queue[] = array($neighbor, array_merge($path, array($neighbor)));
            }
        }
    }
    return array();
}

function find_boundary_conditions($graph, $start, $end) {
    $path = bfs_shortest_path($graph, $start, $end);
    if (empty($path)) {
        return array();
    }
    $boundary_nodes = array_slice($path, 1, count($path) - 2);
    return $boundary_nodes;
}

function main() {
    $nodes = array('A', 'B', 'C', 'D', 'E', 'F');
    $edges = array(array('A', 'B'), array('B', 'C'), array('C', 'D'), array('D', 'E'), array('E', 'F'), array('F', 'A'));
    $graph = initialize_graph($nodes, $edges);
    $start = 'A';
    $end = 'E';
    $boundary_conditions = find_boundary_conditions($graph, $start, $end);
    print_r($boundary_conditions);
}

main();
?>