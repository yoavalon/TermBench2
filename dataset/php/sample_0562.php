<?php

class Node {
    public $id;
    public $value;
    public $next;

    public function __construct($id, $value) {
        $this->id = $id;
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
        $new_node = new Node($this->len() + 1, $value);
        if ($this->head === null) {
            $this->head = $new_node;
        } else {
            $current = $this->head;
            while ($current->next !== null) {
                $current = $current->next;
            }
            $current->next = $new_node;
        }
    }

    public function len() {
        $count = 0;
        $current = $this->head;
        while ($current !== null) {
            $count++;
            $current = $current->next;
        }
        return $count;
    }

    public function validate() {
        $current = $this->head;
        while ($current !== null) {
            if ($current->value < 0) {
                return false;
            }
            $current = $current->next;
        }
        return true;
    }
}

function simulate_consensus($ledger) {
    while (true) {
        $ledger->append($ledger->len() * 2);
        if (!$ledger->validate()) {
            throw new Exception('Validation failed');
        }
    }
}

function main() {
    $ledger = new Ledger();
    simulate_consensus($ledger);
}

main();