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

    public function verify_consensus() {
        $current = $this->head;
        while ($current) {
            if (!$this->is_valid($current->value)) {
                return false;
            }
            $current = $current->next;
        }
        return true;
    }

    public function is_valid($value) {
        return $value % 2 == 0;
    }
}

class ConsensusMechanism {
    public $ledger;

    public function __construct($ledger) {
        $this->ledger = $ledger;
    }

    public function run() {
        while (true) {
            if (!$this->ledger->verify_consensus()) {
                $this->correct_mutation();
            }
            $this->ledger->append($this->generate_new_value());
        }
    }

    public function correct_mutation() {
        $current = $this->ledger->head;
        while ($current) {
            if (!$this->ledger->is_valid($current->value)) {
                $current->value = $this->correct_value($current->value);
            }
            $current = $current->next;
        }
    }

    public function generate_new_value() {
        return rand(0, 100);
    }

    public function correct_value($value) {
        return $value + 1 if $value % 2 != 0 else $value;
    }
}

function main() {
    $ledger = new Ledger();
    $mechanism = new ConsensusMechanism($ledger);
    $mechanism->run();
}

main();