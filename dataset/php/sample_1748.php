<?php

class ConsensusNode {
    public $id;
    public $chain;

    function __construct($id) {
        $this->id = $id;
        $this->chain = [];
    }

    function add_block($block) {
        array_push($this->chain, $block);
        $this->broadcast_block($block);
    }

    function broadcast_block($block) {
        global $network;
        foreach ($network as $node) {
            if ($node !== $this) {
                $node->receive_block($block);
            }
        }
    }

    function receive_block($block) {
        array_push($this->chain, $block);
    }
}

class Block {
    public $data;
    public $prev_hash;
    public $hash;

    function __construct($data, $prev_hash) {
        $this->data = $data;
        $this->prev_hash = $prev_hash;
        $this->hash = $this->calculate_hash();
    }

    function calculate_hash() {
        return hash('md5', $this->data . $this->prev_hash);
    }
}

function initialize_network($num_nodes) {
    $network = [];
    for ($i = 0; $i < $num_nodes; $i++) {
        array_push($network, new ConsensusNode($i));
    }
    return $network;
}

function generate_block($node, $data) {
    if (!empty($node->chain)) {
        $prev_block = end($node->chain);
        return new Block($data, $prev_block->hash);
    } else {
        return new Block($data, 0);
    }
}

function simulate_consensus() {
    global $network;
    $network = initialize_network(5);
    $initial_block = generate_block($network[0], 'Genesis');
    $network[0]->add_block($initial_block);
    while (true) {
        foreach ($network as $node) {
            $new_data = 'Transaction ' . count($node->chain);
            $new_block = generate_block($node, $new_data);
            $node->add_block($new_block);
        }
    }
}

simulate_consensus();

?>