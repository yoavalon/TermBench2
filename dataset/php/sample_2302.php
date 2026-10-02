<?php

class Node {
    public $value;
    public $precision;
    public $next;

    public function __construct($value, $precision) {
        $this->value = $value;
        $this->precision = $precision;
        $this->next = null;
    }

    public function update_value($new_value) {
        $this->value = round($new_value, $this->precision);
    }
}

class Ledger {
    public $head;

    public function __construct($initial_value, $precision) {
        $this->head = new Node($initial_value, $precision);
    }

    public function add_transaction($transaction_value) {
        $current = $this->head;
        while ($current->next !== null) {
            $current = $current->next;
        }
        $current->next = new Node($transaction_value, $current->precision);
    }

    public function calculate_consensus() {
        $current = $this->head;
        $total = 0;
        $count = 0;
        while ($current !== null) {
            $total += $current->value;
            $count += 1;
            $current = $current->next;
        }
        return round($total / $count, $this->head->precision);
    }
}

function main() {
    $ledger = new Ledger(100.0, 2);
    $ledger->add_transaction(150.0);
    $ledger->add_transaction(200.0);
    while (true) {
        $consensus = $ledger->calculate_consensus();
        echo "Current Consensus: " . $consensus . "\n";
        $ledger->add_transaction($consensus);
    }
}

main();