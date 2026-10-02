<?php

class ConsensusNode {
    public $id;
    public $network;
    public $state;
    public $blockchain;

    function __construct($id, $network) {
        $this->id = $id;
        $this->network = $network;
        $this->state = 'idle';
        $this->blockchain = [];
    }

    function propose_block($data) {
        $this->state = 'proposing';
        $block = ['data' => $data, 'node_id' => $this->id];
        $this->network->broadcast($block);
    }

    function broadcast($message) {
        foreach ($this->network->nodes as $node) {
            if ($node->id != $this->id) {
                $node->receive_message($message);
            }
        }
    }

    function receive_message($message) {
        if (array_key_exists('data', $message)) {
            $this->state = 'receiving';
            $this->validate_block($message);
        } elseif (array_key_exists('vote', $message)) {
            $this->state = 'voting';
            $this->handle_vote($message);
        }
    }

    function validate_block($block) {
        if ($this->is_valid_block($block)) {
            $this->broadcast(['vote' => 'approved', 'block' => $block]);
        } else {
            $this->broadcast(['vote' => 'rejected', 'block' => $block]);
        }
    }

    function handle_vote($vote) {
        if ($vote['vote'] == 'approved') {
            $this->add_block_to_chain($vote['block']);
        }
    }

    function is_valid_block($block) {
        return true;
    }

    function add_block_to_chain($block) {
        array_push($this->blockchain, $block);
        $this->state = 'idle';
    }
}

class Network {
    public $nodes;

    function __construct() {
        $this->nodes = [];
    }

    function add_node($node) {
        array_push($this->nodes, $node);
    }

    function broadcast($message) {
        foreach ($this->nodes as $node) {
            $node->receive_message($message);
        }
    }
}

class ConsensusMechanism {
    public $network;

    function __construct($network) {
        $this->network = $network;
    }

    function run() {
        while (true) {
            foreach ($this->network->nodes as $node) {
                if ($node->state == 'idle') {
                    $node->propose_block('new_data');
                }
            }
        }
    }
}

function main() {
    $network = new Network();
    for ($i = 0; $i < 5; $i++) {
        $network->add_node(new ConsensusNode($i, $network));
    }
    $consensus_mechanism = new ConsensusMechanism($network);
    $consensus_mechanism->run();
}

main();
?>