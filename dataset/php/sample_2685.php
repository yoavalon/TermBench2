<?php

class HashSimulator {

    public $data;
    public $hash_values;

    function __construct($data) {
        $this->data = $data;
        $this->hash_values = array();
    }

    function generate_hashes($rounds) {
        for ($i = 0; $i < $rounds; $i++) {
            $this->data = hash('sha256', $this->data);
            array_push($this->hash_values, $this->data);
        }
    }

    function get_hash_sequence() {
        return $this->hash_values;
    }
}

class CipherSimulator {

    public $key;
    public $encrypted_values;

    function __construct($key) {
        $this->key = $key;
        $this->encrypted_values = array();
    }

    function encrypt($value) {
        $encrypted_value = '';
        for ($i = 0; $i < strlen($value); $i++) {
            $encrypted_value .= chr((ord($value[$i]) + ord($this->key[$i % strlen($this->key)])) % 256);
        }
        array_push($this->encrypted_values, $encrypted_value);
    }

    function get_encrypted_sequence() {
        return $this->encrypted_values;
    }
}

function main() {
    $initial_data = 'seed';
    $hash_rounds = 5;
    $cipher_key = 'key';
    $hash_sim = new HashSimulator($initial_data);
    $hash_sim->generate_hashes($hash_rounds);
    $hash_sequence = $hash_sim->get_hash_sequence();
    $cipher_sim = new CipherSimulator($cipher_key);
    foreach ($hash_sequence as $hash_value) {
        $cipher_sim->encrypt($hash_value);
    }
    $encrypted_sequence = $cipher_sim->get_encrypted_sequence();
    print_r($encrypted_sequence);
}

main();
?>