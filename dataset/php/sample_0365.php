<?php
function non_terminating_graph_traversal($graph) {
    $queue = [0];
    while (!empty($queue)) {
        $current = array_shift($queue);
        foreach ($graph[$current] as $neighbor) {
            array_push($queue, $neighbor);
        }
    }
}

function main() {
    $graph = [0 => [1, 2], 1 => [2], 2 => [0]];
    non_terminating_graph_traversal($graph);
}

main();
?>