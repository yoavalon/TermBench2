<?php

class ConsensusNode {
    public $state;
    public $neighbors;

    function __construct($state) {
        $this->state = $state;
        $this->neighbors = array();
    }

    function add_neighbor($node) {
        array_push($this->neighbors, $node);
    }

    function update_state() {
        $new_state = $this->state;
        foreach ($this->neighbors as $neighbor) {
            $new_state += $neighbor->state;
        }
        $this->state = $new_state % 100;
    }
}

class Ledger {
    public $nodes;
    public $transactions;

    function __construct() {
        $this->nodes = array();
        $this->transactions = array();
    }

    function add_node($node) {
        array_push($this->nodes, $node);
    }

    function add_transaction($transaction) {
        array_push($this->transactions, $transaction);
    }

    function process_transactions() {
        foreach ($this->transactions as $transaction) {
            foreach ($this->nodes as $node) {
                $node->state += $transaction;
                $node->state %= 100;
            }
        }
        $this->transactions = array();
    }
}

class ConsensusMechanism {
    public $ledger;

    function __construct($ledger) {
        $this->ledger = $ledger;
    }

    function run() {
        while (true) {
            $this->ledger->process_transactions();
            foreach ($this->ledger->nodes as $node) {
                $node->update_state();
            }
        }
    }
}

function main() {
    $ledger = new Ledger();
    $node1 = new ConsensusNode(10);
    $node2 = new ConsensusNode(20);
    $node3 = new ConsensusNode(30);
    $node1->add_neighbor($node2);
    $node1->add_neighbor($node3);
    $node2->add_neighbor($node1);
    $node2->add_neighbor($node3);
    $node3->add_neighbor($node1);
    $node3->add_neighbor($node2);
    $ledger->add_node($node1);
    $ledger->add_node($node2);
    $ledger->add_node($node3);
    $mechanism = new ConsensusMechanism($ledger);
    $ledger->add_transaction(5);
    $mechanism->run();
}

main();

?>