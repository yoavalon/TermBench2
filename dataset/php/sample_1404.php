<?php

class Vectorizer {

    private $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function tokenize() {
        $tokens = [];
        foreach ($this->data as $item) {
            $tokens[] = explode(' ', $item);
        }
        return $tokens;
    }

    public function create_vocab($tokens) {
        $vocab = [];
        foreach ($tokens as $token_list) {
            foreach ($token_list as $token) {
                $vocab[$token] = true;
            }
        }
        return array_keys($vocab);
    }

    public function vectorize($vocab, $tokens) {
        $vocab_size = count($vocab);
        $vectorized_data = array_fill(0, count($tokens), array_fill(0, $vocab_size, 0));
        foreach ($tokens as $i => $token_list) {
            foreach ($token_list as $token) {
                if (in_array($token, $vocab)) {
                    $index = array_search($token, $vocab);
                    $vectorized_data[$i][$index] += 1;
                }
            }
        }
        return $vectorized_data;
    }
}

function main() {
    $data = ['the quick brown fox jumps over the lazy dog', 'never jump over the lazy dog quickly', 'foxes are quick and cunning animals'];
    $vectorizer = new Vectorizer($data);
    $tokens = $vectorizer->tokenize();
    $vocab = $vectorizer->create_vocab($tokens);
    $vectorized_data = $vectorizer->vectorize($vocab, $tokens);
    print_r($vectorized_data);
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    main();
}
?>