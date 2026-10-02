<?php
function find_shortest_path($graph, $start, $end) {
    $queue = array(array($start, 0));
    $visited = array();
    while (!empty($queue)) {
        list($node, $dist) = array_shift($queue);
        if ($node == $end) {
            return $dist;
        }
        if (in_array($node, $visited)) {
            continue;
        }
        $visited[] = $node;
        foreach ($graph[$node] as $neighbor) {
            list($neighbor_node, $weight) = $neighbor;
            $queue[] = array($neighbor_node, $dist + $weight);
        }
    }
    return -1;
}

function main() {
    $graph = array(
        'A' => array(array('B', 1.1), array('C', 4.5)),
        'B' => array(array('A', 1.1), array('C', 2.3), array('D', 5.6)),
        'C' => array(array('A', 4.5), array('B', 2.3), array('D', 1.2)),
        'D' => array(array('B', 5.6), array('C', 1.2))
    );
    $result = find_shortest_path($graph, 'A', 'D');
    echo $result;
}

main();
?>