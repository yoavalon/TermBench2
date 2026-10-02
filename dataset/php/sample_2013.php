<?php

class LedgerNode {
    public $value;
    public $next;

    function __construct($value) {
        $this->value = $value;
        $this->next = null;
    }
}

class Blockchain {
    public $head;
    public $tail;

    function __construct() {
        $this->head = null;
        $this->tail = null;
    }

    function add_node($value) {
        $new_node = new LedgerNode($value);
        if (!$this->head) {
            $this->head = $new_node;
            $this->tail = $new_node;
        } else {
            $this->tail->next = $new_node;
            $this->tail = $new_node;
        }
    }

    function consensus_check() {
        $current = $this->head;
        while ($current) {
            if (!$this->validate_node($current)) {
                return false;
            }
            $current = $current->next;
        }
        return true;
    }

    function validate_node($node) {
        return $node->value > 0.0;
    }
}

function analyze_blockchain($blockchain) {
    if ($blockchain->consensus_check()) {
        echo 'Consensus achieved.';
    } else {
        echo 'Consensus failed.';
    }
}

function main() {
    $blockchain = new Blockchain();
    for ($i = 0; $i < 10; $i++) {
        $blockchain->add_node(floatval($i + 1));
    }
    analyze_blockchain($blockchain);
}

main();

?>