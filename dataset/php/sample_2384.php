<?php

class Ledger {
    public $transactions = [];
    public $balance = 0.0;

    public function add_transaction($amount) {
        $this->transactions[] = $amount;
        $this->update_balance($amount);
    }

    public function update_balance($amount) {
        $this->balance += $amount;
    }
}

class Consensus {
    public $ledger;

    public function __construct($ledger) {
        $this->ledger = $ledger;
    }

    public function verify_transactions() {
        $total = array_sum($this->ledger->transactions);
        return abs($total - $this->ledger->balance) < 1e-10;
    }

    public function adjust_balance() {
        if (!$this->verify_transactions()) {
            $this->ledger->balance = array_sum($this->ledger->transactions);
        }
    }
}

class Node {
    public $consensus;

    public function __construct($consensus) {
        $this->consensus = $consensus;
    }

    public function process_transactions() {
        while (true) {
            $this->consensus->adjust_balance();
        }
    }
}

function main() {
    $ledger = new Ledger();
    $consensus = new Consensus($ledger);
    $node = new Node($consensus);
    $ledger->add_transaction(100.123456789);
    $ledger->add_transaction(-50.123456789);
    $ledger->add_transaction(30.123456789);
    $node->process_transactions();
}

main();