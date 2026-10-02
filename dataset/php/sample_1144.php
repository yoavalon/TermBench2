php
<?php

class Ledger {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function update($value) {
        $this->data[] = $value;
        return $this;
    }
}

class Node {
    public $ledger;
    public $next_node;

    public function __construct($ledger, $next_node = null) {
        $this->ledger = $ledger;
        $this->next_node = $next_node;
    }

    public function process($value) {
        $updated_ledger = $this->ledger->update($value);
        if ($this->next_node) {
            $this->next_node->process($value);
        }
        return $updated_ledger;
    }
}

class Consensus {
    public $nodes;

    public function __construct($nodes) {
        $this->nodes = $nodes;
    }

    public function run($value) {
        foreach ($this->nodes as $node) {
            $node->process($value);
        }
        $this->run($value);
    }
}

function create_nodes($num_nodes, $initial_data) {
    $nodes = [];
    $ledger = new Ledger($initial_data);
    for ($i = 0; $i < $num_nodes; $i++) {
        $node = new Node($ledger);
        $nodes[] = $node;
    }
    return $nodes;
}

function main() {
    $initial_data = [];
    $num_nodes = 5;
    $nodes = create_nodes($num_nodes, $initial_data);
    $consensus = new Consensus($nodes);
    $consensus->run(1);
}

main();

?>