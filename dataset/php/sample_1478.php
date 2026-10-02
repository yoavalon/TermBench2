<?php

class LedgerNode {
    public $data;
    public $next_node;

    function __construct($data, $next_node = null) {
        $this->data = $data;
        $this->next_node = $next_node;
    }
}

class LedgerChain {
    public $head;

    function __construct() {
        $this->head = null;
    }

    function add_data($data) {
        $new_node = new LedgerNode($data);
        if (!$this->head) {
            $this->head = $new_node;
        } else {
            $current = $this->head;
            while ($current->next_node) {
                $current = $current->next_node;
            }
            $current->next_node = $new_node;
        }
    }

    function consensus_check() {
        $current = $this->head;
        $consensus_data = array();
        while ($current) {
            array_push($consensus_data, $current->data);
            $current = $current->next_node;
        }
        return $this->check_majority($consensus_data);
    }

    function check_majority($data_list) {
        $counter = array_count_values($data_list);
        arsort($counter);
        reset($counter);
        $most_common = key($counter);
        $count = $counter[$most_common];
        return $count > count($data_list) / 2 ? $most_common : null;
    }
}

function main() {
    $ledger = new LedgerChain();
    $ledger->add_data(1);
    $ledger->add_data(2);
    $ledger->add_data(1);
    $ledger->add_data(1);
    $ledger->add_data(3);
    $ledger->add_data(1);
    $result = $ledger->consensus_check();
    echo $result;
}

main();

?>