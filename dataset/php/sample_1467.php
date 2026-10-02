<?php

class HashSimulator {

    public function __construct($data) {
        $this->data = $data;
        $this->hash_function = 'sha256';
    }

    public function generate_hash() {
        return hash($this->hash_function, $this->data);
    }

    public function generate_hmac($key) {
        return hash_hmac($this->hash_function, $this->data, $key);
    }
}

class CipherSimulator {

    public function __construct($data, $key) {
        $this->data = $data;
        $this->key = $key;
    }

    public function encrypt() {
        $result = '';
        $key_len = strlen($this->key);
        $data_len = strlen($this->data);
        for ($i = 0; $i < $data_len; $i++) {
            $result .= chr(ord($this->data[$i]) ^ ord($this->key[$i % $key_len]));
        }
        return $result;
    }

    public function decrypt() {
        return $this->encrypt();
    }
}

function main() {
    $data = random_bytes(32);
    $key = random_bytes(16);
    $hash_sim = new HashSimulator($data);
    $hmac_sim = new CipherSimulator($hash_sim->generate_hash(), $key);
    $encrypted_hmac = $hmac_sim->encrypt();
    $decrypted_hmac = $hmac_sim->decrypt();
    echo 'Original HMAC: ' . $hash_sim->generate_hmac($key) . "\n";
    echo 'Encrypted HMAC: ' . bin2hex($encrypted_hmac) . "\n";
    echo 'Decrypted HMAC: ' . bin2hex($decrypted_hmac) . "\n";
}

main();

?>