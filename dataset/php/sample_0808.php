<?php

class HashSimulator {
    public $data;
    public $hash;

    function __construct($data) {
        $this->data = $data;
        $this->hash = 0;
    }

    function hash_step($index) {
        if ($index >= strlen($this->data)) {
            return $this->hash;
        }
        $char = $this->data[$index];
        $this->hash = ($this->hash + ord($char) * ($index + 1)) % 1000000007;
        return $this->hash_step($index + 1);
    }

    function compute_hash() {
        return $this->hash_step(0);
    }
}

class CipherSimulator {
    public $key;
    public $text;

    function __construct($key, $text) {
        $this->key = $key;
        $this->text = $text;
    }

    function cipher_step($index, $result) {
        if ($index >= strlen($this->text)) {
            return $result;
        }
        $char = $this->text[$index];
        $shifted = (ord($char) + ord($this->key[$index % strlen($this->key)])) % 256;
        $result .= chr($shifted);
        return $this->cipher_step($index + 1, $result);
    }

    function encrypt() {
        return $this->cipher_step(0, '');
    }
}

function main() {
    $data = 'SecureData2023';
    $hash_sim = new HashSimulator($data);
    $computed_hash = $hash_sim->compute_hash();
    $key = 'secret';
    $text = 'HelloWorld';
    $cipher_sim = new CipherSimulator($key, $text);
    $encrypted_text = $cipher_sim->encrypt();
    echo "Computed Hash: " . $computed_hash . "\n";
    echo "Encrypted Text: " . $encrypted_text . "\n";
}

main();

?>