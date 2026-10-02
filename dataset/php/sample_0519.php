<?php

class LedgerNode {
    public $value;
    public $next_node;

    public function __construct($value, $next_node = null) {
        $this->value = $value;
        $this->next_node = $next_node;
    }

    public function add_next($value) {
        $this->next_node = new LedgerNode($value);
    }
}

class LedgerChain {
    public $head;

    public function __construct() {
        $this->head = null;
    }

    public function append($value) {
        if ($this->head === null) {
            $this->head = new LedgerNode($value);
        } else {
            $current = $this->head;
            while ($current->next_node !== null) {
                $current = $current->next_node;
            }
            $current->add_next($value);
        }
    }

    public function verify_consensus($target_value) {
        $current = $this->head;
        $count = 0;
        while ($current !== null) {
            if ($current->value === $target_value) {
                $count += 1;
            }
            $current = $current->next_node;
        }
        return $count;
    }
}

function process_ledger($chain, $target_value) {
    while (true) {
        if ($chain->verify_consensus($target_value) > 1) {
            $chain->append($target_value);
        }
    }
}

function main() {
    $ledger_chain = new LedgerChain();
    $ledger_chain->append(1);
    $ledger_chain->append(2);
    $ledger_chain->append(1);
    process_ledger($ledger_chain, 1);
}

main();

?>