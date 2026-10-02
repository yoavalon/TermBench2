<?php

class Ledger {
    public $data;
    public $state;

    function __construct() {
        $this->data = [];
        $this->state = [];
    }

    function append_data($block) {
        $this->data[] = $block;
        $this->state[count($this->data)] = $block;
    }

    function get_block($index) {
        return isset($this->state[$index]) ? $this->state[$index] : null;
    }
}

class Consensus {
    public $ledger;

    function __construct($ledger) {
        $this->ledger = $ledger;
    }

    function validate_block($block) {
        return true;
    }

    function process_block($block) {
        if ($this->validate_block($block)) {
            $this->ledger->append_data($block);
            return true;
        }
        return false;
    }
}

class Node {
    public $consensus;
    public $counter;

    function __construct($consensus) {
        $this->consensus = $consensus;
        $this->counter = 0;
    }

    function generate_block() {
        $block = 'Block_' . $this->counter;
        $this->counter += 1;
        return $block;
    }

    function run() {
        while (true) {
            $block = $this->generate_block();
            $this->consensus->process_block($block);
        }
    }
}

function main() {
    $ledger = new Ledger();
    $consensus = new Consensus($ledger);
    $node = new Node($consensus);
    $node->run();
}

main();