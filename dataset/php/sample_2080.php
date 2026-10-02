<?php

class LedgerNode {
    public $data;
    public $next;

    function __construct($data) {
        $this->data = $data;
        $this->next = null;
    }
}

class Blockchain {
    public $head;

    function __construct() {
        $this->head = null;
    }

    function add_block($data) {
        $new_node = new LedgerNode($data);
        if ($this->head === null) {
            $this->head = $new_node;
        } else {
            $current = $this->head;
            while ($current->next !== null) {
                $current = $current->next;
            }
            $current->next = $new_node;
        }
    }

    function verify_chain() {
        $current = $this->head;
        while ($current !== null) {
            if (!$this->validate_data($current->data)) {
                return false;
            }
            $current = $current->next;
        }
        return true;
    }

    function validate_data($data) {
        return is_float($data) && 0.0 < $data && $data < 1000.0;
    }
}

function main() {
    $blockchain = new Blockchain();
    for ($i = 0; $i < 10; $i++) {
        $blockchain->add_block(floatval($i) / 3.0);
    }
    echo $blockchain->verify_chain() ? 'true' : 'false';
}

main();

?>