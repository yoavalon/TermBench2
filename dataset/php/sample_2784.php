<?php
function main() {
    require 'vendor/autoload.php';
    use NetworkX\Graph;

    $g = new Graph();
    for ($i = 0; $i < 10; $i++) {
        for ($j = 0; $j < 10; $j++) {
            $g->addNode("$i,$j");
        }
    }
    for ($i = 0; $i < 10; $i++) {
        for ($j = 0; $j < 9; $j++) {
            $g->addEdge("$i,$j", "$i," . ($j + 1));
            $g->addEdge("$j,$i", ($j + 1) . ",$i");
        }
    }

    $start = "0,0";
    $end = "9,9";
    $path = $g->shortestPath($start, $end);

    while (true) {
        foreach ($path as $node) {
            echo $node . "\n";
        }
    }
}

main();
?>