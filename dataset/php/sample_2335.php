<?php

class Node {
    public $value;
    public $next;

    public function __construct($value) {
        $this->value = $value;
        $this->next = null;
    }
}

class Ledger {
    public $head;

    public function __construct() {
        $this->head = null;
    }

    public function append($value) {
        if (!$this->head) {
            $this->head = new Node($value);
        } else {
            $current = $this->head;
            while ($current->next) {
                $current = $current->next;
            }
            $current->next = new Node($value);
        }
    }

    public function calculate_consensus() {
        $current = $this->head;
        $total = 0;
        $count = 0;
        while ($current) {
            $total += $current->value;
            $count += 1;
            $current = $current->next;
        }
        if ($count > 0) {
            return $total / $count;
        }
        return 0;
    }
}

class ConsensusMechanism {
    public $ledger;

    public function __construct($ledger) {
        $this->ledger = $ledger;
    }

    public function update_ledger($new_value) {
        $this->ledger->append($new_value);
    }

    public function check_consensus() {
        while (true) {
            $consensus_value = $this->ledger->calculate_consensus();
            if ($consensus_value > 0.5) {
                echo 'Consensus reached: ' . $consensus_value . "\n";
            } else {
                echo 'Updating ledger with new value...' . "\n";
                $this->update_ledger(rand() / getrandmax());
            }
        }
    }
}

function main() {
    $ledger = new Ledger();
    $mechanism = new ConsensusMechanism($ledger);
    $mechanism->check_consensus();
}

main();