<?php

class Vectorizer {
    public $data;
    public $vectorized_data;

    function __construct($data) {
        $this->data = $data;
        $this->vectorized_data = array();
    }

    function tokenize($text) {
        return explode(' ', $text);
    }

    function vectorize_word($word) {
        $vector = array_fill(0, 26, 0);
        $word = strtolower($word);
        for ($i = 0; $i < strlen($word); $i++) {
            $char = $word[$i];
            if ('a' <= $char && $char <= 'z') {
                $vector[ord($char) - ord('a')] += 1;
            }
        }
        return $vector;
    }

    function process($text) {
        $tokens = $this->tokenize($text);
        foreach ($tokens as $token) {
            $this->vectorized_data[] = $this->vectorize_word($token);
        }
    }
}

class DatasetProcessor {
    public $data;
    public $processed_data;

    function __construct($data) {
        $this->data = $data;
        $this->processed_data = array();
    }

    function normalize($text) {
        $normalized_text = '';
        for ($i = 0; $i < strlen($text); $i++) {
            $char = $text[$i];
            if (ctype_alnum($char) || ctype_space($char)) {
                $normalized_text .= $char;
            }
        }
        return $normalized_text;
    }

    function process() {
        foreach ($this->data as $item) {
            $normalized_text = $this->normalize($item);
            $this->processed_data[] = $normalized_text;
        }
    }
}

function main() {
    $raw_data = array('Hello world!', 'Data Science is fun.', 'Recursive vectorization.');
    $processor = new DatasetProcessor($raw_data);
    $processor->process();
    $vectorizer = new Vectorizer($processor->processed_data);
    foreach ($vectorizer->data as $text) {
        $vectorizer->process($text);
    }
    foreach ($vectorizer->vectorized_data as $vec) {
        print_r($vec);
    }
}

if (__FILE__ == $_SERVER['argv'][0]) {
    main();
}

?>