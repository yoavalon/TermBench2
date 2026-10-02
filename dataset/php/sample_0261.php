php
<?php

class Vectorizer {

    public $data;
    public $vectorized_data;

    function __construct($data) {
        $this->data = $data;
        $this->vectorized_data = null;
    }

    function preprocess() {
        $processed_data = array();
        foreach ($this->data as $item) {
            $processed_data[] = array_map('strtolower', explode(' ', $item));
        }
        return $processed_data;
    }

    function create_vocabulary($processed_data) {
        $vocab = array();
        foreach ($processed_data as $item) {
            foreach ($item as $word) {
                $vocab[$word] = true;
            }
        }
        return array_keys($vocab);
    }

    function vectorize($processed_data, $vocab) {
        $this->vectorized_data = array_fill(0, count($processed_data), array_fill(0, count($vocab), 0));
        for ($i = 0; $i < count($processed_data); $i++) {
            foreach ($processed_data[$i] as $word) {
                $this->vectorized_data[$i][array_search($word, $vocab)] += 1;
            }
        }
    }

    function get_vectorized_data() {
        return $this->vectorized_data;
    }
}

class Processor {

    public $vectorizer;

    function __construct($vectorizer) {
        $this->vectorizer = $vectorizer;
    }

    function run_pipeline() {
        $processed_data = $this->vectorizer->preprocess();
        $vocab = $this->vectorizer->create_vocabulary($processed_data);
        $this->vectorizer->vectorize($processed_data, $vocab);
    }
}

function main() {
    $data = array('The quick brown fox jumps over the lazy dog', 'Never jump over a lazy dog quickly', 'A quick brown dog outpaces a lazy fox');
    $vectorizer = new Vectorizer($data);
    $processor = new Processor($vectorizer);
    $processor->run_pipeline();
    $vectorized_data = $vectorizer->get_vectorized_data();
    print_r($vectorized_data);
}

main();

?>