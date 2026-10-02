<?php

class Block {
    public $index;
    public $data;
    public $previous_hash;
    public $hash;

    public function __construct($index, $data, $previous_hash) {
        $this->index = $index;
        $this->data = $data;
        $this->previous_hash = $previous_hash;
        $this->hash = $this->calculate_hash();
    }

    public function calculate_hash() {
        $block_string = json_encode(['index' => $this->index, 'data' => $this->data, 'previous_hash' => $this->previous_hash], JSON_UNESCAPED_SLASHES | JSON_SORT_KEYS);
        return hash('sha256', $block_string);
    }
}

class Blockchain {
    public $chain;

    public function __construct() {
        $this->chain = [$this->create_genesis_block()];
    }

    public function create_genesis_block() {
        return new Block(0, 'Genesis Block', '0');
    }

    public function add_block($new_block) {
        $new_block->previous_hash = $this->chain[count($this->chain) - 1]->hash;
        $new_block->hash = $new_block->calculate_hash();
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

function simulate_consensus_mechanics() {
    $blockchain = new Blockchain();
    for ($i = 1; $i < 10; $i++) {
        $new_block_data = "Block $i Data";
        $new_block = new Block($i, $new_block_data, '');
        $blockchain->add_block($new_block);
        echo "Block $i added to the blockchain\n";
    }
    if ($blockchain->is_chain_valid()) {
        echo 'Blockchain is valid.';
    } else {
        echo 'Blockchain is invalid.';
    }
}

simulate_consensus_mechanics();

?>