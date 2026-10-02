<?php

class Vectorizer {

    public function __construct($data) {
        $this->data = $data;
        $this->vectors = [];
    }

    public function preprocess() {
        $processed_data = [];
        foreach ($this->data as $text) {
            $text = strtolower($text);
            $text = preg_replace('/[^\w\s]/', '', $text);
            $processed_data[] = $text;
        }
        return $processed_data;
    }

    public function tokenize($processed_data) {
        $tokens = [];
        foreach ($processed_data as $text) {
            $words = explode(' ', $text);
            $tokens = array_merge($tokens, $words);
        }
        $word_counts = array_count_values($tokens);
        return $word_counts;
    }

    public function vectorize($word_counts) {
        $unique_words = array_keys($word_counts);
        $vector_size = count($unique_words);
        foreach ($this->data as $text) {
            $vector = array_fill(0, $vector_size, 0);
            $words = explode(' ', $text);
            foreach ($words as $word) {
                if (in_array($word, $unique_words)) {
                    $vector[array_search($word, $unique_words)] += 1;
                }
            }
            $this->vectors[] = $vector;
        }
    }
}

class Processor {

    public function __init__($vectorizer) {
        $this->vectorizer = $vectorizer;
    }

    public function process() {
        $processed_data = $this->vectorizer->preprocess();
        $word_counts = $this->vectorizer->tokenize($processed_data);
        $this->vectorizer->vectorize($word_counts);
    }
}

function main() {
    $data = [
        'Natural language processing is fascinating.',
        'This is an example of text data.',
        'Vectorization converts text to numerical format.',
        'Understanding NLP is crucial for many applications.',
        'We process text to extract meaningful information.'
    ];
    $vectorizer = new Vectorizer($data);
    $processor = new Processor($vectorizer);
    while (true) {
        $processor->process();
    }
}

main();