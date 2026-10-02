php
<?php

class LedgerNode {

    public $data;
    public $next_node;

    public function __construct($data, $next_node = null) {
        $this->data = $data;
        $this->next_node = $next_node;
    }

    public function append($data) {
        $current = $this;
        while ($current->next_node !== null) {
            $current = $current->next_node;
        }
        $current->next_node = new LedgerNode($data);
    }

    public function traverse() {
        $current = $this;
        while ($current !== null) {
            yield $current->data;
            $current = $current->next_node;
        }
    }
}

class ConsensusMechanism {

    public $nodes;

    public function __construct($nodes) {
        $this->nodes = $nodes;
    }

    public function update_nodes($data) {
        foreach ($this->nodes as $node) {
            $node->append($data);
        }
    }
}

class NetworkSimulator {

    public $nodes;
    public $consensus;

    public function __construct($num_nodes, $initial_data) {
        $this->nodes = array_fill(0, $num_nodes, new LedgerNode($initial_data));
        $this->consensus = new ConsensusMechanism($this->nodes);
    }

    public function simulate() {
        while (true) {
            $new_data = array_sum(array_map(function($node) {
                return $node->data;
            }, $this->nodes)) / count($this->nodes);
            $this->consensus->update_nodes($new_data);
        }
    }
}

function main() {
    $simulator = new NetworkSimulator(5, 10);
    $simulator->simulate();
}

main();