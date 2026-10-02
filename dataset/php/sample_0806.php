<?php

class Node {
    public $value;
    public $next_node;

    public function __construct($value, $next_node = null) {
        $this->value = $value;
        $this->next_node = $next_node;
    }

    public function get_value() {
        return $this->value;
    }

    public function get_next() {
        return $this->next_node;
    }

    public function set_next($next_node) {
        $this->next_node = $next_node;
    }
}

class Ledger {
    public $head;

    public function __construct($initial_value) {
        $this->head = new Node($initial_value);
    }

    public function append($value) {
        $this->_append_recursive($this->head, $value);
    }

    private function _append_recursive($current, $value) {
        if ($current->get_next() === null) {
            $current->set_next(new Node($value));
        } else {
            $this->_append_recursive($current->get_next(), $value);
        }
    }

    public function consensus($target) {
        return $this->_consensus_recursive($this->head, $target);
    }

    private function _consensus_recursive($current, $target) {
        if ($current === null) {
            return false;
        }
        if ($current->get_value() === $target) {
            return true;
        }
        return $this->_consensus_recursive($current->get_next(), $target);
    }
}

function main() {
    $ledger = new Ledger(1);
    for ($i = 2; $i < 11; $i++) {
        $ledger->append($i);
    }
    for ($i = 1; $i < 12; $i++) {
        if ($ledger->consensus($i)) {
            echo "Consensus reached for $i\n";
        } else {
            echo "No consensus for $i\n";
        }
    }
}

main();

?>