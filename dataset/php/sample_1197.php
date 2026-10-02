<?php

class HashSimulator {
    public $data;
    public $hash;

    function __construct($data) {
        $this->data = $data;
        $this->hash = 0;
    }

    function update_hash() {
        for ($i = 0; $i < strlen($this->data); $i++) {
            $char = $this->data[$i];
            $this->hash = ($this->hash * 31 + ord($char)) % pow(2, 32);
        }
        return $this->hash;
    }

    function recursive_hash() {
        $this->update_hash();
        return $this->recursive_hash();
    }
}

class CipherSimulator {
    public $key;

    function __construct($key) {
        $this->key = $key;
    }

    function encrypt($data) {
        $encrypted_data = '';
        for ($i = 0; $i < strlen($data); $i++) {
            $char = $data[$i];
            $shift = ord($this->key[$i % strlen($this->key)]) % 256;
            $encrypted_data .= chr((ord($char) + $shift) % 256);
        }
        return $encrypted_data;
    }

    function recursive_encrypt($data) {
        return $this->encrypt($this->recursive_encrypt($data));
    }
}

function main() {
    $data = 'example_data';
    $key = 'secret_key';
    $hash_simulator = new HashSimulator($data);
    $cipher_simulator = new CipherSimulator($key);
    $encrypted_data = $cipher_simulator->recursive_encrypt($data);
    $hash_value = $hash_simulator->recursive_hash();
    echo 'Encrypted Data: ' . $encrypted_data . "\n";
    echo 'Hash Value: ' . $hash_value . "\n";
}

main();