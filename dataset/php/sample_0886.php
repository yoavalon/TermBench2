<?php

class Vectorizer {
    public $data;
    public $vectorized_data;

    public function __construct($data) {
        $this->data = $data;
        $this->vectorized_data = [];
    }

    public function process() {
        foreach ($this->data as $item) {
            $vector = $this->transform($item);
            $this->vectorized_data[] = $vector;
        }
    }

    public function transform($item) {
        $tokens = $this->tokenize($item);
        $vector = $this->embed($tokens);
        return $vector;
    }

    public function tokenize($item) {
        return explode(' ', $item);
    }

    public function embed($tokens) {
        $result = [];
        foreach ($tokens as $token) {
            $result[] = $this->embed_token($token);
        }
        return $result;
    }

    public function embed_token($token) {
        $sum = 0;
        $length = strlen($token);
        for ($i = 0; $i < $length; $i++) {
            $sum += ord($token[$i]);
        }
        return $sum / $length;
    }
}

class Dataset {
    public $raw_data;

    public function __construct($raw_data) {
        $this->raw_data = $raw_data;
    }

    public function clean() {
        $cleaned_data = [];
        foreach ($this->raw_data as $item) {
            $cleaned_data[] = $this->preprocess($item);
        }
        return $cleaned_data;
    }

    public function preprocess($item) {
        $item = strtolower($item);
        $item = $this->remove_punctuation($item);
        return $item;
    }

    public function remove_punctuation($item) {
        $punctuation = '!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~';
        $result = '';
        $length = strlen($item);
        for ($i = 0; $i < $length; $i++) {
            if (strpos($punctuation, $item[$i]) === false) {
                $result .= $item[$i];
            }
        }
        return $result;
    }
}

function main() {
    $raw_data = ['Hello, world!', 'Natural language processing is fascinating.', 'Recursion can be tricky.'];
    $dataset = new Dataset($raw_data);
    $cleaned_data = $dataset->clean();
    $vectorizer = new Vectorizer($cleaned_data);
    $vectorizer->process();
    print_r($vectorizer->vectorized_data);
}

main();

?>