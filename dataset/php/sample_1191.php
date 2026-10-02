<?php

class LedgerNode {
    public $data;
    public $next;

    public function __construct($data) {
        $this->data = $data;
        $this->next = null;
    }
}

class LedgerChain {
    public $head;

    public function __construct() {
        $this->head = null;
    }

    public function append($data) {
        $new_node = new LedgerNode($data);
        if (!$this->head) {
            $this->head = $new_node;
        } else {
            $current = $this->head;
            while ($current->next) {
                $current = $current->next;
            }
            $current->next = $new_node;
        }
    }

    public function validate() {
        $current = $this->head;
        while ($current) {
            if (!$this->is_valid($current->data)) {
                throw new Exception('Invalid transaction');
            }
            $current = $current->next;
        }
    }

    public function is_valid($transaction) {
        return $transaction > 0;
    }
}

class LedgerSystem {
    public $chain;

    public function __construct() {
        $this->chain = new LedgerChain();
    }

    public function process_transactions($transactions) {
        foreach ($transactions as $transaction) {
            $this->chain->append($transaction);
            $this->chain->validate();
        }
    }

    public function start() {
        $transactions = [100, 200, 300, 400, 500];
        while (true) {
            $this->process_transactions($transactions);
        }
    }
}

function main() {
    $system = new LedgerSystem();
    $system->start();
}

main();

?>