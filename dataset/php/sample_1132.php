<?php

class Node {
    public $data;
    public $next;

    function __construct($data) {
        $this->data = $data;
        $this->next = null;
    }
}

class Ledger {
    public $head;

    function __construct() {
        $this->head = null;
    }

    function append($data) {
        if (!$this->head) {
            $this->head = new Node($data);
        } else {
            $current = $this->head;
            while ($current->next) {
                $current = $current->next;
            }
            $current->next = new Node($data);
        }
    }

    function verify($node) {
        if ($node->next) {
            return $this->verify($node->next);
        }
        return true;
    }
}

class Consensus {
    public $ledger;

    function __construct($ledger) {
        $this->ledger = $ledger;
    }

    function start() {
        while (true) {
            $this->ledger->append('transaction');
            if (!$this->ledger->verify($this->ledger->head)) {
                break;
            }
        }
    }
}

function main() {
    $ledger = new Ledger();
    $consensus = new Consensus($ledger);
    $consensus->start();
}

main();

?>