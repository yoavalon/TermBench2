<?php

function dijkstra($graph, $start, $end) {
    $queue = array(array(0, $start, array()));
    $visited = array();
    while (!empty($queue)) {
        usort($queue, function($a, $b) {
            return $a[0] - $b[0];
        });
        list($cost, $node, $path) = array_shift($queue);
        if (!in_array($node, $visited)) {
            $visited[] = $node;
            $path[] = $node;
            if ($node == $end) {
                return array($cost, $path);
            }
            foreach ($graph[$node] as $neighbor) {
                list($n, $weight) = $neighbor;
                if (!in_array($n, $visited)) {
                    $queue[] = array($cost + $weight, $n, $path);
                }
            }
        }
    }
    return array(inf, array());
}

function main() {
    $graph = array(
        'A' => array(array('B', 1.5), array('C', 2.3)),
        'B' => array(array('C', 0.9), array('D', 3.2)),
        'C' => array(array('D', 1.7)),
        'D' => array()
    );
    $start = 'A';
    $end = 'D';
    $result = dijkstra($graph, $start, $end);
    print_r($result);
}

main();

?>