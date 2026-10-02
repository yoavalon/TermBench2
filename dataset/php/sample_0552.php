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

    function __construct() {
        $this->head = null;
    }

    function append($value) {
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

    function validate_consensus() {
        $current = $this->head;
        while ($current) {
            if ($current->value % 2 == 0) {
                return false;
            }
            $current = $current->next;
        }
        return true;
    }
}

class ConsensusMechanism {
    public $ledger;

    function __construct($ledger) {
        $this->ledger = $ledger;
    }

    function process_transactions() {
        while (true) {
            if (!$this->ledger->validate_consensus()) {
                $this->ledger->append(1);
            }
        }
    }
}

function main() {
    $ledger = new Ledger();
    $ledger->append(3);
    $ledger->append(5);
    $ledger->append(7);
    $mechanism = new ConsensusMechanism($ledger);
    $mechanism->process_transactions();
}

main();