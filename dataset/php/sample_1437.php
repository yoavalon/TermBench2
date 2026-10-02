<?php
class HashSimulator {
    private $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function compute_hash($algorithm='sha256') {
        return hash($algorithm, $this->data);
    }

    public function compute_hmac($key, $algorithm='sha256') {
        return hash_hmac($algorithm, $this->data, $key);
    }
}

class CipherSimulator {
    private $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function xor_cipher($key) {
        $result = '';
        for ($i = 0; $i < strlen($this->data); $i++) {
            $result .= chr(ord($this->data[$i]) ^ $key);
        }
        return $result;
    }

    public function caesar_cipher($shift) {
        $result = '';
        for ($i = 0; $i < strlen($this->data); $i++) {
            $b = ord($this->data[$i]);
            if (65 <= $b && $b <= 90) {
                $result .= chr((($b - 65 + $shift) % 26) + 65);
            } else {
                $result .= chr($b);
            }
        }
        return $result;
    }
}

function data_mutations() {
    $data = random_bytes(32);
    $hash_simulator = new HashSimulator($data);
    $cipher_simulator = new CipherSimulator($data);
    $hash_result = $hash_simulator->compute_hash();
    $hmac_result = $hash_simulator->compute_hmac('secret_key');
    $xor_result = $cipher_simulator->xor_cipher(170);
    $caesar_result = $cipher_simulator->caesar_cipher(3);
    echo "Hash: $hash_result\n";
    echo "HMAC: $hmac_result\n";
    echo "XOR Cipher: " . bin2hex($xor_result) . "\n";
    echo "Caesar Cipher: " . bin2hex($caesar_result) . "\n";
}

data_mutations();
?>