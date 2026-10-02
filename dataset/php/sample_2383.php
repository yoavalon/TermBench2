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
    public $tail;

    public function __construct() {
        $this->head = null;
        $this->tail = null;
    }

    public function append($value) {
        $new_node = new Node($value);
        if ($this->head === null) {
            $this->head = $new_node;
            $this->tail = $new_node;
        } else {
            $this->tail->next = $new_node;
            $this->tail = $new_node;
        }
    }

    public function consensus() {
        $current = $this->head;
        while ($current !== null) {
            if ($current->value < 0.5) {
                $current->value += 0.01;
            } else {
                $current->value -= 0.01;
            }
            $current = $current->next;
        }
    }
}

function main() {
    $ledger = new Ledger();
    for ($i = 0; $i < 100; $i++) {
        $ledger->append(floatval($i) / 100);
    }
    while (true) {
        $ledger->consensus();
    }
}

main();

?>