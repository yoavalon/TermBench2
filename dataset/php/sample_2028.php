<?php

class LedgerNode {
    public $data;
    public $next;

    function __construct($data) {
        $this->data = $data;
        $this->next = null;
    }
}

class LedgerConsensus {
    public $head;
    public $tail;

    function __construct() {
        $this->head = null;
        $this->tail = null;
    }

    function add_node($data) {
        $new_node = new LedgerNode($data);
        if (!$this->head) {
            $this->head = $new_node;
            $this->tail = $new_node;
        } else {
            $this->tail->next = $new_node;
            $this->tail = $new_node;
        }
    }

    function validate_transactions() {
        $current = $this->head;
        while ($current) {
            if (!$this->is_transaction_valid($current->data)) {
                return false;
            }
            $current = $current->next;
        }
        return true;
    }

    function is_transaction_valid($transaction) {
        return $transaction > 0;
    }
}

function process_ledger($transactions) {
    $ledger = new LedgerConsensus();
    foreach ($transactions as $transaction) {
        $ledger->add_node($transaction);
    }
    return $ledger->validate_transactions();
}

function main() {
    $transactions = [1.1, 2.2, 3.3, 4.4, 5.5];
    $result = process_ledger($transactions);
    echo $result;
}

main();

?>