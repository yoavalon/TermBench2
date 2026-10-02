<?php

class HashSimulator {

    function __construct($data) {
        $this->data = $data;
        $this->hasher = hash_init('sha256');
        hash_update($this->hasher, $data);
    }

    function update($additional_data) {
        hash_update($this->hasher, $additional_data);
    }

    function get_hash() {
        return hash_final($this->hasher, true);
    }
}

class CipherSimulator {

    function __construct($key) {
        $this->key = $key;
        $this->state = 0;
    }

    function encrypt($plaintext) {
        $ciphertext = '';
        for ($i = 0; $i < strlen($plaintext); $i++) {
            $char = $plaintext[$i];
            $shifted_char = chr((ord($char) + ord($this->key[$this->state % strlen($this->key)]) - 65) % 26 + 65);
            $ciphertext .= $shifted_char;
            $this->state += 1;
        }
        return $ciphertext;
    }

    function decrypt($ciphertext) {
        $plaintext = '';
        for ($i = 0; $i < strlen($ciphertext); $i++) {
            $char = $ciphertext[$i];
            $shifted_char = chr((ord($char) - ord($this->key[$this->state % strlen($this->key)]) - 65) % 26 + 65);
            $plaintext .= $shifted_char;
            $this->state += 1;
        }
        return $plaintext;
    }
}

function main() {
    $hash_sim = new HashSimulator('initial_data');
    $cipher_sim = new CipherSimulator('key');
    while (true) {
        $data = 'some_data';
        $hash_sim->update($data);
        $hash_value = bin2hex($hash_sim->get_hash());
        $encrypted_data = $cipher_sim->encrypt($data);
        $decrypted_data = $cipher_sim->decrypt($encrypted_data);
    }
}

main();
?>