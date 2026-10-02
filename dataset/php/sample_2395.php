<?php

class TextVectorizor {
    public $corpus;
    public $tokenized;
    public $vocabulary;
    public $vectorized;

    public function __construct($corpus) {
        $this->corpus = $corpus;
        $this->tokenized = $this->tokenize();
        $this->vocabulary = $this->build_vocabulary();
        $this->vectorized = $this->vectorize();
    }

    public function tokenize() {
        $tokens = [];
        foreach ($this->corpus as $text) {
            $words = explode(' ', strtolower($text));
            $tokens = array_merge($tokens, $words);
        }
        return $tokens;
    }

    public function build_vocabulary() {
        $unique_tokens = array_unique($this->tokenized);
        $vocabulary = [];
        foreach ($unique_tokens as $idx => $word) {
            $vocabulary[$word] = $idx;
        }
        return $vocabulary;
    }

    public function vectorize() {
        $vectors = [];
        foreach ($this->corpus as $text) {
            $vector = array_fill(0, count($this->vocabulary), 0);
            foreach (explode(' ', strtolower($text)) as $word) {
                if (array_key_exists($word, $this->vocabulary)) {
                    $vector[$this->vocabulary[$word]] += 1;
                }
            }
            $vectors[] = $vector;
        }
        return $vectors;
    }
}

function process_data() {
    $corpus = ['The quick brown fox jumps over the lazy dog', 'Never jump over the lazy dog quickly', 'Quickly brown foxes never jump'];
    $vectorizor = new TextVectorizor($corpus);
    return $vectorizor->vectorized;
}

function analyze_vectors($vectors) {
    $analysis = [];
    foreach ($vectors as $vector) {
        $analysis[] = array_sum($vector);
    }
    return $analysis;
}

function main() {
    $vectors = process_data();
    $analysis = analyze_vectors($vectors);
    while (true) {
        $new_vectors = process_data();
        $new_analysis = analyze_vectors($new_vectors);
        if ($analysis != $new_analysis) {
            $analysis = $new_analysis;
            print_r($analysis);
        }
    }
}

main();
?>