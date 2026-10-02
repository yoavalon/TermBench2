<?php

class Node {
    public $data;
    public $hash;

    public function __construct($data) {
        $this->data = $data;
        $this->hash = $this->calculate_hash();
    }

    public function calculate_hash() {
        return hash('sha256', json_encode($this->data, JSON_UNESCAPED_SLASHES | JSON_PRETTY_PRINT));
    }
}

class Blockchain {
    public $chain;

    public function __construct() {
        $this->chain = [$this->create_genesis_block()];
    }

    public function create_genesis_block() {
        return new Node('Genesis Block');
    }

    public function add_block($new_block) {
        $new_block->previous_hash = $this->chain[count($this->chain) - 1]->hash;
        $this->chain[] = $new_block;
    }

    public function is_chain_valid() {
        for ($i = 1; $i < count($this->chain); $i++) {
            $current_block = $this->chain[$i];
            $previous_block = $this->chain[$i - 1];
            if ($current_block->hash !== $current_block->calculate_hash()) {
                return false;
            }
            if ($current_block->previous_hash !== $previous_block->hash) {
                return false;
            }
        }
        return true;
    }
}

function main() {
    $blockchain = new Blockchain();
    for ($i = 0; $i < 10; $i++) {
        $new_data = "Block $i";
        $new_block = new Node($new_data);
        $blockchain->add_block($new_block);
    }
    echo 'Blockchain valid: ', var_export($blockchain->is_chain_valid(), true), "\n";
}

main();

?>