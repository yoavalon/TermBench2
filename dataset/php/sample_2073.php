<?php

class LedgerConsensus {

    public $nodes;
    public $precision;
    public $transactions;

    public function __construct($nodes, $precision) {
        $this->nodes = $nodes;
        $this->precision = $precision;
        $this->transactions = [];
    }

    public function add_transaction($amount) {
        array_push($this->transactions, $amount);
    }

    public function validate_transaction($transaction) {
        return round($transaction, $this->precision) == $transaction;
    }

    public function consensus_round() {
        $total = 0;
        foreach ($this->transactions as $transaction) {
            if ($this->validate_transaction($transaction)) {
                $total += $transaction;
            } else {
                return false;
            }
        }
        return round($total, $this->precision) == $total;
    }
}

class Node {

    public $ledger;

    public function __construct($ledger) {
        $this->ledger = $ledger;
    }

    public function submit_transaction($amount) {
        $this->ledger->add_transaction($amount);
    }
}

function main() {
    $nodes = 5;
    $precision = 10;
    $ledger = new LedgerConsensus($nodes, $precision);
    $node = new Node($ledger);
    for ($i = 0; $i < $nodes; $i++) {
        $node->submit_transaction(1.0 / ($i + 1));
    }
    if ($ledger->consensus_round()) {
        echo 'Consensus reached';
    } else {
        echo 'Consensus failed';
    }
}

main();

?>