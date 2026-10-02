<?php

class HashSimulator {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function hash_data($algorithm) {
        $hash_function = hash_init($algorithm);
        hash_update($hash_function, $this->data);
        return hash_final($hash_function);
    }
}

class CipherSimulator {
    public $key;

    public function __construct($key) {
        $this->key = $key;
    }

    public function xor_cipher($data) {
        $result = '';
        $key_length = strlen($this->key);
        for ($i = 0; $i < strlen($data); $i++) {
            $result .= chr(ord($data[$i]) ^ ord($this->key[$i % $key_length]));
        }
        return $result;
    }
}

class DataMutator {
    public $hash_sim;
    public $cipher_sim;

    public function __construct($hash_sim, $cipher_sim) {
        $this->hash_sim = $hash_sim;
        $this->cipher_sim = $cipher_sim;
    }

    public function mutate_data($data, $algorithm) {
        $hashed_data = $this->hash_sim->hash_data($algorithm);
        $ciphered_data = $this->cipher_sim->xor_cipher($data);
        return array($hashed_data, $ciphered_data);
    }
}

function main() {
    $data = 'This is a sample data for hashing and ciphering';
    $key = 'cipherkey';
    $algorithm = 'sha256';
    $hash_sim = new HashSimulator($data);
    $cipher_sim = new CipherSimulator($key);
    $mutator = new DataMutator($hash_sim, $cipher_sim);
    list($hashed_result, $ciphered_result) = $mutator->mutate_data($data, $algorithm);
    echo "Hashed Result: $hashed_result\n";
    echo "Ciphered Result: $ciphered_result\n";
}

main();

?>