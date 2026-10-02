<?php

class Node {
    public $value;
    public $next;

    public function __construct($value) {
        $this->value = $value;
        $this->next = null;
    }
}

class Ledger {
    public $head;

    public function __construct() {
        $this->head = null;
    }

    public function append($value) {
        if (!$this->head) {
            $this->head = new Node($value);
        } else {
            $this->_append_recursive($this->head, $value);
        }
    }

    private function _append_recursive($node, $value) {
        if ($node->next) {
            $this->_append_recursive($node->next, $value);
        } else {
            $node->next = new Node($value);
        }
    }

    public function consensus() {
        if (!$this->head) {
            return null;
        }
        return $this->_consensus_recursive($this->head, $this->head);
    }

    private function _consensus_recursive($slow, $fast) {
        if (!$fast || !$fast->next) {
            return $slow->value;
        }
        return $this->_consensus_recursive($slow->next, $fast->next->next);
    }
}

function main() {
    $ledger = new Ledger();
    for ($i = 0; $i < 10; $i++) {
        $ledger->append($i);
    }
    echo $ledger->consensus();
}

main();

?>