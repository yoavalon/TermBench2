<?php

class HashSimulator {

    public $data;
    public $depth;
    public $current_depth;

    public function __construct($data, $depth) {
        $this->data = $data;
        $this->depth = $depth;
        $this->current_depth = 0;
    }

    public function hash_data() {
        return hash('sha256', $this->data);
    }

    public function recursive_hash() {
        if ($this->current_depth >= $this->depth) {
            return $this->hash_data();
        } else {
            $this->current_depth += 1;
            $this->data = $this->hash_data();
            return $this->recursive_hash();
        }
    }
}

class CipherSimulator {

    public $key;
    public $rounds;
    public $current_round;

    public function __construct($key, $rounds) {
        $this->key = $key;
        $this->rounds = $rounds;
        $this->current_round = 0;
    }

    public function simple_cipher($data) {
        $result = '';
        for ($i = 0; $i < strlen($data); $i++) {
            $result .= chr((ord($data[$i]) + ord($this->key)) % 256);
        }
        return $result;
    }

    public function recursive_cipher($data) {
        if ($this->current_round >= $this->rounds) {
            return $data;
        } else {
            $this->current_round += 1;
            $data = $this->simple_cipher($data);
            return $this->recursive_cipher($data);
        }
    }
}

function main() {
    $initial_data = 'SecureData';
    $hash_depth = 5;
    $cipher_rounds = 3;
    $key = 'Secret';
    $hash_simulator = new HashSimulator($initial_data, $hash_depth);
    $hashed_data = $hash_simulator->recursive_hash();
    $cipher_simulator = new CipherSimulator($key, $cipher_rounds);
    $encrypted_data = $cipher_simulator->recursive_cipher($hashed_data);
    echo $encrypted_data;
}

main();

?>