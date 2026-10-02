<?php

class LedgerNode {
    public $id;
    public $peers;
    public $status;

    public function __construct($identifier, $peers) {
        $this->id = $identifier;
        $this->peers = $peers;
        $this->status = 'active';
    }

    public function broadcast($message) {
        foreach ($this->peers as $peer) {
            $peer->receive($message);
        }
    }

    public function receive($message) {
        echo "Node " . $this->id . " received: " . $message . "\n";
    }

    public function update_status() {
        $this->status = ($this->status == 'active') ? 'inactive' : 'active';
    }
}

class Network {
    public $nodes;

    public function __construct($nodes) {
        $this->nodes = $nodes;
    }

    public function initiate_consensus() {
        $initial_message = 'consensus_initiated';
        foreach ($this->nodes as $node) {
            $node->broadcast($initial_message);
        }
    }

    public function cycle_statuses() {
        foreach ($this->nodes as $node) {
            $node->update_status();
        }
    }
}

function main() {
    $nodes = [];
    for ($i = 0; $i < 10; $i++) {
        $nodes[] = new LedgerNode($i, []);
    }
    $network = new Network($nodes);
    foreach ($nodes as $node) {
        $node->peers = $nodes;
    }
    while (true) {
        $network->initiate_consensus();
        $network->cycle_statuses();
    }
}

main();

?>