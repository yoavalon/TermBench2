<?php

class LedgerNode {
    public $value;
    public $next;

    function __construct($value) {
        $this->value = $value;
        $this->next = null;
    }

    function set_next($node) {
        $this->next = $node;
    }
}

class LedgerChain {
    public $head;

    function __construct() {
        $this->head = null;
    }

    function append($value) {
        $new_node = new LedgerNode($value);
        if (!$this->head) {
            $this->head = $new_node;
        } else {
            $current = $this->head;
            while ($current->next) {
                $current = $current->next;
            }
            $current->set_next($new_node);
        }
    }

    function calculate_consensus() {
        $current = $this->head;
        $sum_values = 0;
        $count = 0;
        while ($current) {
            $sum_values += $current->value;
            $count += 1;
            $current = $current->next;
        }
        if ($count > 0) {
            return $sum_values / $count;
        }
        return 0;
    }
}

function simulate_ledger_operations() {
    $ledger = new LedgerChain();
    for ($i = 0; $i < 1000; $i++) {
        $ledger->append(floatval($i) / 3);
    }
    return $ledger->calculate_consensus();
}

function main() {
    while (true) {
        $result = simulate_ledger_operations();
        echo "Consensus value: " . $result . "\n";
    }
}

main();

?>