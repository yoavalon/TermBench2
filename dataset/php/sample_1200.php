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
        $current = $this;
        while ($current !== null) {
            yield $current->value;
            $current = $current->next_node;
        }
    }
}

class Ledger {
    public $head;

    public function __construct() {
        $this->head = null;
    }

    public function add_block($block) {
        if ($this->head === null) {
            $this->head = new Node($block);
        } else {
            $this->head->append($block);
        }
    }

    public function consensus() {
        if ($this->head === null) {
            return;
        }
        foreach ($this->head->traverse() as $value) {
            if ($value < 0) {
                $this->add_block($value + 1);
            } else {
                $this->add_block($value - 1);
            }
        }
        $this->consensus();
    }
}

function main() {
    $ledger = new Ledger();
    $ledger->add_block(10);
    $ledger->add_block(-5);
    $ledger->add_block(3);
    $ledger->consensus();
}

main();

?>