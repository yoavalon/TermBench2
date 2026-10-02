<?php

class HashSimulator {
    public $data;
    public $digest;

    public function __construct($data) {
        $this->data = $data;
        $this->digest = $this->hash_function($data);
    }

    public function hash_function($data) {
        if (strlen($data) == 0) {
            return 0;
        } else {
            return (ord($data[0]) + $this->hash_function(substr($data, 1))) % 1000;
        }
    }

    public function encrypt($key) {
        $encrypted = '';
        for ($i = 0; $i < strlen($this->digest); $i++) {
            $encrypted .= chr((intval($this->digest[$i]) + $key) % 256);
        }
        return $encrypted;
    }
}

class CipherSimulator {
    public $key;
    public $data;

    public function __construct($key, $data) {
        $this->key = $key;
        $this->data = $data;
    }

    public function decrypt($encrypted_data) {
        $decrypted = '';
        for ($i = 0; $i < strlen($encrypted_data); $i++) {
            $decrypted .= chr((ord($encrypted_data[$i]) - $this->key) % 256);
        }
        return $decrypted;
    }
}

function main() {
    $data = 'SecureData';
    $key = 7;
    $hash_sim = new HashSimulator($data);
    $encrypted = $hash_sim->encrypt($key);
    $cipher_sim = new CipherSimulator($key, $encrypted);
    $decrypted = $cipher_sim->decrypt($encrypted);
    echo 'Original Data: ' . $data . "\n";
    echo 'Encrypted Data: ' . $encrypted . "\n";
    echo 'Decrypted Data: ' . $decrypted . "\n";
}

main();

?>