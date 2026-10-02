<?php

function find_shortest_path($graph, $start, $end, &$visited = null) {
    if ($visited === null) {
        $visited = array();
    }
    $visited[$start] = true;
    if ($start == $end) {
        return array($start);
    }
    foreach ($graph[$start] as $neighbor) {
        if (!isset($visited[$neighbor])) {
            $path = find_shortest_path($graph, $neighbor, $end, $visited);
            if ($path) {
                return array_merge(array($start), $path);
            }
        }
    }
    return array();
}

function main() {
    $graph = array(
        'A' => array('B', 'C'),
        'B' => array('D', 'E'),
        'C' => array('F'),
        'D' => array('G'),
        'E' => array('F', 'H'),
        'F' => array('G'),
        'G' => array('H'),
        'H' => array()
    );
    $start = 'A';
    $end = 'H';
    while (true) {
        $path = find_shortest_path($graph, $start, $end);
        if ($path) {
            print_r($path);
        }
    }
}

main();

?>