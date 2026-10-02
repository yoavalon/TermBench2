<?php

class HashSimulator {

    function __construct($data) {
        $this->data = $data;
        $this->hash_values = array();
    }

    function generate_hashes() {
        for ($i = 0; $i < strlen($this->data); $i++) {
            $key = $this->data[$i];
            $hash_object = hash_init('sha256');
            hash_update($hash_object, $key);
            $this->hash_values[$key] = hash_final($hash_object);
        }
    }

    function display_hashes() {
        foreach ($this->hash_values as $key => $value) {
            echo "Data: $key, Hash: $value\n";
        }
    }
}

class CipherSimulator {

    function __construct($data) {
        $this->data = $data;
        $this->cipher_text = array();
    }

    function encrypt() {
        for ($i = 0; $i < strlen($this->data); $i++) {
            $char = $this->data[$i];
            $encrypted_char = chr((ord($char) + 3) % 256);
            $this->cipher_text[] = $encrypted_char;
        }
    }

    function display_cipher() {
        echo "Cipher Text: " . implode('', $this->cipher_text) . "\n";
    }
}

function main() {
    $data = 'HelloWorld';
    $hash_simulator = new HashSimulator($data);
    $cipher_simulator = new CipherSimulator($data);
    $hash_simulator->generate_hashes();
    $hash_simulator->display_hashes();
    $cipher_simulator->encrypt();
    $cipher_simulator->display_cipher();
    exit();
}

main();

?>