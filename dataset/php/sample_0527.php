<?php
class Node {
    public $id;
    public $state;
    public $neighbors;

    public function __construct($id, $state) {
        $this->id = $id;
        $this->state = $state;
        $this->neighbors = [];
    }

    public function add_neighbor($neighbor) {
        $this->neighbors[] = $neighbor;
    }
}

class Network {
    public $nodes;

    public function __construct() {
        $this->nodes = [];
    }

    public function add_node($node) {
        $this->nodes[] = $node;
    }

    public function update_states() {
        foreach ($this->nodes as $node) {
            $new_state = array_sum(array_map(function($neighbor) {
                return $neighbor->state;
            }, $node->neighbors)) / count($node->neighbors);
            $node->state = $new_state;
        }
    }
}

class ConsensusMechanism {
    public $network;

    public function __construct($network) {
        $this->network = $network;
    }

    public function simulate() {
        while (true) {
            $this->network->update_states();
        }
    }
}

function main() {
    $network = new Network();
    $nodes = array_map(function($i) {
        return new Node($i, 0);
    }, range(0, 4));
    for ($i = 0; $i < 5; $i++) {
        for ($j = $i + 1; $j < 5; $j++) {
            $nodes[$i]->add_neighbor($nodes[$j]);
            $nodes[$j]->add_neighbor($nodes[$i]);
        }
    }
    $network->nodes = $nodes;
    $mechanism = new ConsensusMechanism($network);
    $mechanism->simulate();
}

main();
?>