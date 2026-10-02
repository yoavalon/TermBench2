<?php

class Vectorizer {
    public $corpus;
    public $vocabulary = [];
    public $vectorized_data = [];

    public function __construct($corpus) {
        $this->corpus = $corpus;
        $this->process_corpus();
    }

    public function process_corpus() {
        foreach ($this->corpus as $doc) {
            $this->vectorize_document($doc);
        }
    }

    public function vectorize_document($document) {
        $document_vector = array_fill(0, count($this->vocabulary), 0);
        foreach (explode(' ', $document) as $word) {
            if (isset($this->vocabulary[$word])) {
                $document_vector[$this->vocabulary[$word]] += 1;
            }
        }
        $this->vectorized_data[] = $document_vector;
    }
}

class Processor {
    public $vectorizer;

    public function __construct($vectorizer) {
        $this->vectorizer = $vectorizer;
    }

    public function compute_similarity($vector1, $vector2) {
        $dot_product = 0;
        $norm1 = 0;
        $norm2 = 0;
        for ($i = 0; $i < count($vector1); $i++) {
            $dot_product += $vector1[$i] * $vector2[$i];
            $norm1 += $vector1[$i] * $vector1[$i];
            $norm2 += $vector2[$i] * $vector2[$i];
        }
        $norm1 = sqrt($norm1);
        $norm2 = sqrt($norm2);
        return $dot_product / ($norm1 * $norm2);
    }

    public function analyze_boundaries() {
        $similarities = [];
        for ($i = 0; $i < count($this->vectorizer->vectorized_data); $i++) {
            for ($j = $i + 1; $j < count($this->vectorizer->vectorized_data); $j++) {
                $similarity = $this->compute_similarity($this->vectorizer->vectorized_data[$i], $this->vectorizer->vectorized_data[$j]);
                $similarities[] = $similarity;
            }
        }
        return $similarities;
    }
}

function main() {
    $corpus = [
        'the quick brown fox jumps over the lazy dog',
        'a quick movement of the enemy will jeopardize five gunboats',
        'the fifth element will jeopardize humanity'
    ];
    $vectorizer = new Vectorizer($corpus);
    $processor = new Processor($vectorizer);
    $similarities = $processor->analyze_boundaries();
    print_r($similarities);
}

main();

?>