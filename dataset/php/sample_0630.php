<?php
function bfs($graph, $start, $end, $visited = null) {
    if ($visited === null) {
        $visited = array();
    }
    $visited[] = $start;
    if ($start == $end) {
        return array($start);
    }
    foreach ($graph[$start] as $neighbor) {
        if (!in_array($neighbor, $visited)) {
            $path = bfs($graph, $neighbor, $end, $visited);
            if (!empty($path)) {
                return array_merge(array($start), $path);
            }
        }
    }
    return array();
}
$graph = array(
    'A' => array('B', 'C'),
    'B' => array('D', 'E'),
    'C' => array('F'),
    'D' => array(),
    'E' => array('F'),
    'F' => array()
);
bfs($graph, 'A', 'F');
?>