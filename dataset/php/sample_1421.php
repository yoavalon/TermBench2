<?php

class HashSimulator {
    public $data;
    public $hash_algorithms = ['md5', 'sha1', 'sha256', 'sha512'];

    function __construct($data) {
        $this->data = $data;
    }

    function apply_hash($algorithm) {
        return hash($algorithm, $this->data);
    }

    function simulate_hashes() {
        $results = [];
        foreach ($this->hash_algorithms as $algo) {
            $results[$algo] = $this->apply_hash($algo);
        }
        return $results;
    }
}

class CipherSimulator {
    public $data;
    public $key;

    function __construct($data, $key) {
        $this->data = $data;
        $this->key = $key;
    }

    function xor_cipher() {
        $encrypted = '';
        for ($i = 0; $i < strlen($this->data); $i++) {
            $encrypted .= chr(ord($this->data[$i]) ^ $this->key[$i % strlen($this->key)]);
        }
        return $encrypted;
    }

    function simulate_ciphers() {
        return ['xor' => $this->xor_cipher()];
    }
}

class DataMutator {
    public $data;
    public $key = 'secret';

    function __construct($data) {
        $this->data = mb_convert_encoding($data, 'UTF-8', 'auto');
    }

    function mutate() {
        $hash_sim = new HashSimulator($this->data);
        $cipher_sim = new CipherSimulator($this->data, $this->key);
        $hashes = $hash_sim->simulate_hashes();
        $ciphers = $cipher_sim->simulate_ciphers();
        return ['hashes' => $hashes, 'ciphers' => $ciphers];
    }
}

function main() {
    $data = 'Sample data for cryptographic simulation';
    $mutator = new DataMutator($data);
    $result = $mutator->mutate();
    print_r($result);
}

main();

?>