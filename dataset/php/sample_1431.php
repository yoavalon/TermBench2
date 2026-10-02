<?php

class HashSimulator {

    private $data;
    private $hash;

    public function __construct($data) {
        $this->data = $data;
        $this->hash = hash('sha256', $data);
    }

    public function update($new_data) {
        $this->data .= $new_data;
        $this->hash = hash('sha256', $this->data);
    }

    public function get_hash() {
        return $this->hash;
    }
}

class CipherSimulator {

    private $key;
    private $cipher;

    public function __construct($key) {
        $this->key = $key;
        $this->cipher = openssl_encrypt('', 'AES-128-CBC', $key, OPENSSL_RAW_DATA, str_repeat("\0", 16));
    }

    public function encrypt($data) {
        $padded_data = $this->pad($data, openssl_cipher_iv_length('AES-128-CBC'));
        $encrypted_data = openssl_encrypt($padded_data, 'AES-128-CBC', $this->key, OPENSSL_RAW_DATA, str_repeat("\0", 16));
        return $encrypted_data;
    }

    public function decrypt($encrypted_data) {
        $decrypted_data = openssl_decrypt($encrypted_data, 'AES-128-CBC', $this->key, OPENSSL_RAW_DATA, str_repeat("\0", 16));
        return $this->unpad($decrypted_data, openssl_cipher_iv_length('AES-128-CBC'));
    }

    private function pad($data, $block_size) {
        $padding = $block_size - (strlen($data) % $block_size);
        return $data . str_repeat(chr($padding), $padding);
    }

    private function unpad($data, $block_size) {
        $padding = ord($data[strlen($data) - 1]);
        return substr($data, 0, -$padding);
    }
}

function main() {
    $data = 'Hello, World!';
    $hash_sim = new HashSimulator($data);
    echo 'Initial Hash: ' . $hash_sim->get_hash() . "\n";
    $new_data = ' Additional Data';
    $hash_sim->update($new_data);
    echo 'Updated Hash: ' . $hash_sim->get_hash() . "\n";
    $key = random_bytes(16);
    $cipher_sim = new CipherSimulator($key);
    $encrypted = $cipher_sim->encrypt($data);
    echo 'Encrypted: ' . base64_encode($encrypted) . "\n";
    $decrypted = $cipher_sim->decrypt($encrypted);
    echo 'Decrypted: ' . $decrypted . "\n";
}

main();