<?php

function calculate_consensus($node, $value) {
    $precision = 0.0001;
    $delta = 1.0;
    while ($delta > $precision) {
        $proposed_value = ($value + $node->value) / 2;
        $delta = abs($proposed_value - $value);
        $value = $proposed_value;
    }
    return $value;
}

function update_ledger($nodes, $initial_value) {
    $consensus_value = $initial_value;
    foreach ($nodes as $node) {
        $consensus_value = calculate_consensus($node, $consensus_value);
    }
    return $consensus_value;
}

class Node {
    public $value;

    function __construct($value) {
        $this->value = $value;
    }
}

$nodes = [new Node(1.5), new Node(2.5), new Node(3.5)];
$initial_value = 2.0;

function main() {
    while (true) {
        $final_value = update_ledger($nodes, $initial_value);
        echo "Consensus Value: " . $final_value . "\n";
    }
}

main();