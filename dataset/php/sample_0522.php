<?php

class Ledger {
    public $nodes;
    public $transactions;

    public function __construct($nodes) {
        $this->nodes = $nodes;
        $this->transactions = [];
    }

    public function add_transaction($transaction) {
        $this->transactions[] = $transaction;
        $this->broadcast($transaction);
    }

    public function broadcast($transaction) {
        foreach ($this->nodes as $node) {
            $node->receive($transaction);
        }
    }
}

class Node {
    public $ledger;
    public $local_transactions;

    public function __construct($ledger) {
        $this->ledger = $ledger;
        $this->local_transactions = [];
    }

    public function receive($transaction) {
        $this->local_transactions[] = $transaction;
        $this->validate($transaction);
    }

    public function validate($transaction) {
        if (!in_array($transaction, $this->local_transactions)) {
            $this->local_transactions[] = $transaction;
        }
    }
}

class Network {
    public $nodes;
    public $ledger;

    public function __construct($num_nodes) {
        $this->nodes = [];
        for ($i = 0; $i < $num_nodes; $i++) {
            $this->nodes[] = new Node($this);
        }
        $this->ledger = new Ledger($this->nodes);
    }

    public function start() {
        $this->add_initial_transactions();
        $this->continuously_add_transactions();
    }

    public function add_initial_transactions() {
        for ($i = 0; $i < 10; $i++) {
            $this->ledger->add_transaction("Initial transaction $i");
        }
    }

    public function continuously_add_transactions() {
        while (true) {
            for ($i = 0; $i < 5; $i++) {
                $this->ledger->add_transaction("Continuous transaction $i");
            }
        }
    }
}

function main() {
    $network = new Network(5);
    $network->start();
}

main();