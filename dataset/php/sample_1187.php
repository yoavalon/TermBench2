<?php

class ConsensusNode {
    public $node_id;
    public $chain = [];
    public $neighbors = [];

    public function __construct($node_id) {
        $this->node_id = $node_id;
    }

    public function add_neighbor($neighbor) {
        array_push($this->neighbors, $neighbor);
    }

    public function broadcast_transaction($transaction) {
        array_push($this->chain, $transaction);
        foreach ($this->neighbors as $neighbor) {
            $neighbor->receive_transaction($transaction);
        }
    }

    public function receive_transaction($transaction) {
        array_push($this->chain, $transaction);
        $this->propagate_transaction($transaction);
    }

    public function propagate_transaction($transaction) {
        foreach ($this->neighbors as $neighbor) {
            $neighbor->receive_transaction($transaction);
        }
    }
}

function create_network($num_nodes) {
    $nodes = [];
    for ($i = 0; $i < $num_nodes; $i++) {
        $nodes[$i] = new ConsensusNode($i);
    }
    for ($i = 0; $i < $num_nodes; $i++) {
        for ($j = $i + 1; $j < $num_nodes; $j++) {
            $nodes[$i]->add_neighbor($nodes[$j]);
            $nodes[$j]->add_neighbor($nodes[$i]);
        }
    }
    return $nodes;
}

function start_consensus($nodes) {
    $transaction_counter = 0;
    while (true) {
        $transaction = 'Transaction-' . $transaction_counter;
        $nodes[0]->broadcast_transaction($transaction);
        $transaction_counter++;
    }
}

function main() {
    $nodes = create_network(5);
    start_consensus($nodes);
}

main();