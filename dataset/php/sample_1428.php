<?php

class HashSimulator {
    public $data;
    public $key;

    function __construct($data, $key) {
        $this->data = $data;
        $this->key = $key;
    }

    function hash_data() {
        return hash('sha256', $this->data);
    }

    function hmac_data() {
        return hash_hmac('sha256', $this->data, $this->key);
    }
}

class CipherSimulator {
    public $data;
    public $key;

    function __construct($data, $key) {
        $this->data = $data;
        $this->key = $key;
    }

    function encrypt() {
        $encrypted = '';
        for ($i = 0; $i < strlen($this->data); $i++) {
            $encrypted .= chr((ord($this->data[$i]) + ord($this->key[$i % strlen($this->key)])) % 256);
        }
        return $encrypted;
    }

    function decrypt($encrypted_data) {
        $decrypted = '';
        for ($i = 0; $i < strlen($encrypted_data); $i++) {
            $decrypted .= chr((ord($encrypted_data[$i]) - ord($this->key[$i % strlen($this->key)])) % 256);
        }
        return $decrypted;
    }
}

function main() {
    $data = 'SecureData';
    $key = 'SecretKey';
    $hash_sim = new HashSimulator($data, $key);
    $cipher_sim = new CipherSimulator($data, $key);
    $hash_result = $hash_sim->hash_data();
    $hmac_result = $hash_sim->hmac_data();
    $encrypted_data = $cipher_sim->encrypt();
    echo "Hash: $hash_result\n";
    echo "HMAC: $hmac_result\n";
    echo "Encrypted: $encrypted_data\n";
    $decrypted_data = $cipher_sim->decrypt($encrypted_data);
    echo "Decrypted: $decrypted_data\n";
}

main();

?>