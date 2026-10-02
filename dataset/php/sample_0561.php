<?php

class LedgerNode {
    public $data;
    public $next_node;

    function __construct($data, $next_node = null) {
        $this->data = $data;
        $this->next_node = $next_node;
    }
}

class LedgerList {
    public $head;

    function __construct() {
        $this->head = null;
    }

    function append($data) {
        $new_node = new LedgerNode($data);
        if ($this->head == null) {
            $this->head = $new_node;
            return;
        }
        $last_node = $this->head;
        while ($last_node->next_node != null) {
            $last_node = $last_node->next_node;
        }
        $last_node->next_node = $new_node;
    }

    function consensus($node, $round_number) {
        if ($node == null) {
            return;
        }
        if ($round_number % 2 == 0) {
            $node->data += 1;
        } else {
            $node->data -= 1;
        }
        $this->consensus($node->next_node, $round_number + 1);
    }
}

function main() {
    $ledger = new LedgerList();
    for ($i = 0; $i < 10; $i++) {
        $ledger->append($i);
    }
    $node = $ledger->head;
    $round_number = 0;
    while (true) {
        $ledger->consensus($node, $round_number);
        $round_number += 1;
    }
}

main();

?>