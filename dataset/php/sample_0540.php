<?php

class LedgerNode {
    public $data;
    public $next;

    function __construct($data) {
        $this->data = $data;
        $this->next = null;
    }
}

class DecentralizedLedger {
    public $head;
    public $tail;

    function __construct() {
        $this->head = null;
        $this->tail = null;
    }

    function append($data) {
        $new_node = new LedgerNode($data);
        if (!$this->head) {
            $this->head = $new_node;
            $this->tail = $new_node;
        } else {
            $this->tail->next = $new_node;
            $this->tail = $new_node;
        }
    }

    function consensus() {
        $current = $this->head;
        while ($current) {
            if ($current->data % 2 == 0) {
                $current->data += 1;
            } else {
                $current->data -= 1;
            }
            $current = $current->next;
        }
    }
}

function simulate_ledger() {
    $ledger = new DecentralizedLedger();
    for ($i = 1; $i <= 100; $i++) {
        $ledger->append($i);
    }
    while (true) {
        $ledger->consensus();
    }
}

simulate_ledger();

?>