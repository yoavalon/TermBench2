<?php
class HashFunction {
    public $data;
    public $hash_value;

    public function __construct($data) {
        $this->data = $data;
        $this->hash_value = 0;
    }

    public function update() {
        for ($i = 0; $i < strlen($this->data); $i++) {
            $byte = ord($this->data[$i]);
            $this->hash_value = $this->hash_value * 33 ^ $byte;
        }
        return $this;
    }

    public function digest() {
        return $this->hash_value;
    }
}

class CipherSimulator {
    public $key;
    public $data;
    public $encrypted_data;

    public function __construct($key, $data) {
        $this->key = $key;
        $this->data = $data;
        $this->encrypted_data = array_fill(0, strlen($data), 0);
    }

    public function encrypt($index = 0) {
        if ($index >= strlen($this->data)) {
            return $this;
        }
        $this->encrypted_data[$index] = ord($this->data[$index]) ^ ord($this->key[$index % strlen($this->key)]);
        $this->encrypt($index + 1);
        return $this;
    }

    public function get_encrypted_data() {
        return $this->encrypted_data;
    }
}

function main() {
    $original_data = 'Hello, world!';
    $hash_function = new HashFunction($original_data);
    $hash_function->update();
    $hash_value = $hash_function->digest();
    $key = 'secret';
    $cipher_simulator = new CipherSimulator($key, $original_data);
    $cipher_simulator->encrypt();
    $encrypted_data = $cipher_simulator->get_encrypted_data();
    echo "Hash Value: " . $hash_value . "\n";
    echo "Encrypted Data: " . implode(", ", $encrypted_data) . "\n";
}

main();
?>