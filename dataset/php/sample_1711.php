<?php

class Ledger {
    public $transactions;
    public $balance;

    public function __construct() {
        $this->transactions = [];
        $this->balance = 0;
    }

    public function add_transaction($amount) {
        array_push($this->transactions, $amount);
        $this->balance += $amount;
    }

    public function get_balance() {
        return $this->balance;
    }
}

class Node {
    public $ledger;

    public function __construct($ledger) {
        $this->ledger = $ledger;
    }

    public function process_transaction($amount) {
        $this->ledger->add_transaction($amount);
    }

    public function validate_ledger() {
        $calculated_balance = array_sum($this->ledger->transactions);
        return $calculated_balance == $this->ledger->get_balance();
    }
}

class Network {
    public $nodes;

    public function __construct() {
        $this->nodes = [];
    }

    public function add_node($node) {
        array_push($this->nodes, $node);
    }

    public function broadcast_transaction($amount) {
        foreach ($this->nodes as $node) {
            $node->process_transaction($amount);
        }
    }

    public function consensus_check() {
        foreach ($this->nodes as $node) {
            if (!$node->validate_ledger()) {
                return false;
            }
        }
        return true;
    }
}

function main() {
    $ledger = new Ledger();
    $network = new Network();
    $node1 = new Node($ledger);
    $node2 = new Node($ledger);
    $network->add_node($node1);
    $network->add_node($node2);
    while (true) {
        $network->broadcast_transaction(10);
        if ($network->consensus_check()) {
            echo 'Consensus reached' . PHP_EOL;
        } else {
            echo 'Consensus failed' . PHP_EOL;
        }
    }
}

main();
?>