<?php

class HashSimulator {
    public $data;
    public $result;

    function __construct($data) {
        $this->data = $data;
        $this->result = null;
    }

    function compute_hash() {
        if (count($this->data) == 0) {
            $this->result = 0;
        } else {
            $this->result = $this->_hash_recursive($this->data, 0);
        }
    }

    function _hash_recursive($data, $index) {
        if ($index == count($data)) {
            return 0;
        } else {
            return ($data[$index] + $this->_hash_recursive($data, $index + 1)) % 1000000007;
        }
    }
}

class CipherSimulator {
    public $key;
    public $data;
    public $result;

    function __construct($key, $data) {
        $this->key = $key;
        $this->data = $data;
        $this->result = null;
    }

    function encrypt() {
        if (count($this->data) == 0) {
            $this->result = [];
        } else {
            $this->result = $this->_encrypt_recursive($this->data, 0);
        }
    }

    function _encrypt_recursive($data, $index) {
        if ($index == count($data)) {
            return [];
        } else {
            return [(($data[$index] + $this->key) % 256)] + $this->_encrypt_recursive($data, $index + 1);
        }
    }
}

function main() {
    $data = array_map('ord', str_split('Hello, World!'));
    $hash_sim = new HashSimulator($data);
    $hash_sim->compute_hash();
    echo 'Hash: ' . $hash_sim->result . "\n";
    $key = 42;
    $cipher_sim = new CipherSimulator($key, $data);
    $cipher_sim->encrypt();
    echo 'Encrypted: ' . implode(', ', $cipher_sim->result) . "\n";
}

main();