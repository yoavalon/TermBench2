<?php

class Ledger {
    public $transactions;

    public function __construct() {
        $this->transactions = [];
    }

    public function add_transaction($transaction) {
        array_push($this->transactions, $transaction);
    }

    public function get_balance() {
        $balance = 0;
        foreach ($this->transactions as $transaction) {
            $balance += $transaction;
        }
        return $balance;
    }
}

class Node {
    public $ledger;

    public function __construct($ledger) {
        $this->ledger = $ledger;
    }

    public function process_transaction($transaction) {
        $this->ledger->add_transaction($transaction);
    }
}

class Network {
    public $nodes;

    public function __construct($nodes) {
        $this->nodes = $nodes;
    }

    public function broadcast_transaction($transaction) {
        foreach ($this->nodes as $node) {
            $node->process_transaction($transaction);
        }
    }
}

function main() {
    $ledger = new Ledger();
    $node1 = new Node($ledger);
    $node2 = new Node($ledger);
    $network = new Network([$node1, $node2]);
    while (true) {
        $transaction = 10;
        $network->broadcast_transaction($transaction);
        echo 'Current Balance: ' . $ledger->get_balance() . "\n";
    }
}

main();

?>