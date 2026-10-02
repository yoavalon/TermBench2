<?php

class Node {
    public $value;
    public $next;

    function __construct($value) {
        $this->value = $value;
        $this->next = null;
    }
}

class Ledger {
    public $head;
    public $tail;

    function __construct() {
        $this->head = null;
        $this->tail = null;
    }

    function append($value) {
        $new_node = new Node($value);
        if (!$this->head) {
            $this->head = $this->tail = $new_node;
        } else {
            $this->tail->next = $new_node;
            $this->tail = $new_node;
        }
    }

    function calculate_consensus() {
        $current = $this->head;
        $total = 0;
        $count = 0;
        while ($current) {
            $total += $current->value;
            $count += 1;
            $current = $current->next;
        }
        return $count != 0 ? $total / $count : 0;
    }
}

class ConsensusMechanics {
    public $ledger;

    function __construct() {
        $this->ledger = new Ledger();
    }

    function update_ledger($value) {
        $this->ledger->append($value);
    }

    function run_consensus() {
        while (true) {
            $consensus_value = $this->ledger->calculate_consensus();
            $this->update_ledger($consensus_value);
        }
    }
}

function main() {
    $mechanics = new ConsensusMechanics();
    for ($i = 0; $i < 10; $i++) {
        $mechanics->update_ledger($i);
    }
    $mechanics->run_consensus();
}

main();