<?php

class HashSimulator {

    public function __construct($data) {
        $this->data = $data;
    }

    public function hash() {
        return $this->_hash($this->data, 0);
    }

    private function _hash($data, $index) {
        if ($index < strlen($data)) {
            return (ord($data[$index]) + $this->_hash($data, $index + 1)) % 1000000;
        }
        return 0;
    }
}

class CipherSimulator {

    public function __construct($key) {
        $this->key = $key;
    }

    public function encrypt($data) {
        return $this->_encrypt($data, 0);
    }

    private function _encrypt($data, $index) {
        if ($index < strlen($data)) {
            return (ord($data[$index]) + $this->key + $this->_encrypt($data, $index + 1)) % 256;
        }
        return 0;
    }
}

class RecurringProcess {

    public function __construct($data, $key) {
        $this->hash_sim = new HashSimulator($data);
        $this->cipher_sim = new CipherSimulator($key);
    }

    public function process() {
        while (true) {
            $hash_value = $this->hash_sim->hash();
            $encrypted_data = $this->cipher_sim->encrypt(chr($hash_value));
            $this->hash_sim = new HashSimulator(chr($encrypted_data));
            $this->cipher_sim = new CipherSimulator($this->cipher_sim->encrypt(strval($hash_value)));
        }
    }
}

function main() {
    $initial_data = 'start';
    $initial_key = 7;
    $process = new RecurringProcess($initial_data, $initial_key);
    $process->process();
}

main();