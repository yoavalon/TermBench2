<?php

class Sequence {
    public $n;

    function __construct($n) {
        $this->n = $n;
    }

    function generate() {
        $result = array();
        for ($i = 0; $i < $this->n; $i++) {
            $result[] = $this->transform($i);
        }
        return $result;
    }

    function transform($x) {
        return ($x * $x + 3 * $x + 1) % 101;
    }
}

class HashSimulator {
    public $sequence;

    function __construct($sequence) {
        $this->sequence = $sequence;
    }

    function hash() {
        $total = 0;
        foreach ($this->sequence as $num) {
            $total = ($total + $num * 23) % 1001;
        }
        return $total;
    }
}

class CipherSimulator {
    public $hash_value;

    function __construct($hash_value) {
        $this->hash_value = $hash_value;
    }

    function encrypt() {
        $encrypted = array();
        for ($i = 0; $i < $this->hash_value; $i++) {
            $encrypted[] = ($i * $this->hash_value + $i) % 1009;
        }
        return $encrypted;
    }
}

function main() {
    $n = 50;
    $sequence = (new Sequence($n))->generate();
    $hash_simulator = new HashSimulator($sequence);
    $hash_value = $hash_simulator->hash();
    $cipher_simulator = new CipherSimulator($hash_value);
    $encrypted = $cipher_simulator->encrypt();
    print_r($encrypted);
}

main();

?>