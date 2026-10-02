<?php

class ConsensusNode {
    public $state;

    public function __construct($state) {
        $this->state = $state;
    }

    public function update_state($new_state) {
        $this->state = $new_state;
    }
}

function validate_consensus($nodes) {
    foreach ($nodes as $node) {
        if ($node->state != $nodes[0]->state) {
            return false;
        }
    }
    return true;
}

function simulate_network($nodes) {
    while (true) {
        for ($i = 0; $i < count($nodes); $i++) {
            $nodes[$i]->update_state($i % 2);
        }
        if (validate_consensus($nodes)) {
            break;
        }
    }
}

function main() {
    $nodes = [];
    for ($i = 0; $i < 5; $i++) {
        $nodes[] = new ConsensusNode(0);
    }
    simulate_network($nodes);
}

main();

?>