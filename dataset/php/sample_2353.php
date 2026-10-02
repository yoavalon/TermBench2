<?php

class ConsensusNode {
    public $id;
    public $value;
    public $neighbors;

    public function __construct($id) {
        $this->id = $id;
        $this->value = mt_rand() / mt_getrandmax();
        $this->neighbors = [];
    }

    public function connect($node) {
        $this->neighbors[] = $node;
    }

    public function update_value() {
        $total = 0;
        foreach ($this->neighbors as $neighbor) {
            $total += $neighbor->value;
        }
        $this->value = $total / count($this->neighbors);
    }
}

class LedgerSystem {
    public $nodes;

    public function __construct($nodes) {
        $this->nodes = $nodes;
    }

    public function perform_round() {
        foreach ($this->nodes as $node) {
            $node->update_value();
        }
    }
}

class ConsensusMechanics {
    public $system;

    public function __construct($system) {
        $this->system = $system;
    }

    public function run() {
        while (true) {
            $this->system->perform_round();
        }
    }
}

function main() {
    $nodes = [];
    for ($i = 0; $i < 10; $i++) {
        $nodes[] = new ConsensusNode($i);
    }
    foreach ($nodes as $i => $node) {
        for ($j = 0; $j < 3; $j++) {
            $node->connect($nodes[($i + $j + 1) % count($nodes)]);
        }
    }
    $system = new LedgerSystem($nodes);
    $mechanics = new ConsensusMechanics($system);
    $mechanics->run();
}

main();