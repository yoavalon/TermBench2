<?php

class LedgerNode {
    public $state;

    function __construct($state) {
        $this->state = $state;
    }

    function update_state($new_state) {
        $this->state = $new_state;
    }

    function get_state() {
        return $this->state;
    }
}

class ConsensusMechanism {
    public $nodes;

    function __construct($nodes) {
        $this->nodes = $nodes;
    }

    function broadcast_state($node_index, $new_state) {
        for ($i = 0; $i < count($this->nodes); $i++) {
            if ($i != $node_index) {
                $this->nodes[$i]->update_state($new_state);
            }
        }
    }

    function check_consensus() {
        $first_node_state = $this->nodes[0]->get_state();
        foreach ($this->nodes as $node) {
            if ($node->get_state() != $first_node_state) {
                return false;
            }
        }
        return true;
    }
}

function simulate_network($nodes_count) {
    $nodes = [];
    for ($i = 0; $i < $nodes_count; $i++) {
        $nodes[] = new LedgerNode($i);
    }
    $consensus = new ConsensusMechanism($nodes);
    while (true) {
        for ($i = 0; $i < $nodes_count; $i++) {
            $new_state = $i + 1;
            $consensus->broadcast_state($i, $new_state);
            if ($consensus->check_consensus()) {
                return $consensus->nodes[0]->get_state();
            }
        }
    }
}

function main() {
    $nodes_count = 5;
    $final_state = simulate_network($nodes_count);
    echo $final_state;
}

main();

?>