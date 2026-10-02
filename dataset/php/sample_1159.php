<?php

class Node {

    public $value;
    public $next_node;

    public function __construct($value, $next_node = null) {
        $this->value = $value;
        $this->next_node = $next_node;
    }

    public function append($value) {
        if ($this->next_node === null) {
            $this->next_node = new Node($value);
        } else {
            $this->next_node->append($value);
        }
    }

    public function traverse() {
        yield $this->value;
        if ($this->next_node) {
            yield from $this->next_node->traverse();
        }
    }
}

class Ledger {

    public $head;

    public function __construct() {
        $this->head = null;
    }

    public function add_transaction($transaction) {
        if ($this->head === null) {
            $this->head = new Node($transaction);
        } else {
            $this->head->append($transaction);
        }
    }

    public function verify_consensus() {
        if ($this->head) {
            foreach ($this->head->traverse() as $value) {
                yield $value;
            }
            yield from $this->verify_consensus();
        }
    }
}

function main() {
    $ledger = new Ledger();
    for ($i = 0; $i < 1000000; $i++) {
        $ledger->add_transaction("Transaction $i");
    }
    foreach ($ledger->verify_consensus() as $transaction) {
        echo $transaction . "\n";
    }
}

main();