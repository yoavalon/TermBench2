<?php

class Vectorizer {

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
        $tokenized = [];
        foreach ($this->corpus as $doc) {
            $tokenized[] = explode(' ', strtolower($doc));
        }
        return $tokenized;
    }

    public function build_vocabulary() {
        $vocab = [];
        foreach ($this->tokenized as $doc) {
            foreach ($doc as $word) {
                $vocab[$word] = true;
            }
        }
        $vocabulary = [];
        $idx = 0;
        foreach ($vocab as $word => $_) {
            $vocabulary[$word] = $idx++;
        }
        return $vocabulary;
    }

    public function vectorize() {
        $vectors = [];
        foreach ($this->tokenized as $doc) {
            $vector = array_fill(0, count($this->vocabulary), 0);
            foreach ($doc as $word) {
                if (isset($this->vocabulary[$word])) {
                    $vector[$this->vocabulary[$word]] += 1;
                }
            }
            $vectors[] = $vector;
        }
        return $vectors;
    }
}

function load_data() {
    return ['This is a sample document', 'Another document for testing', 'Sample document number three'];
}

function analyze_vectors($vectors) {
    $average_vector = array_fill(0, count($vectors[0]), 0);
    $max_vector = array_fill(0, count($vectors[0]), 0);
    foreach ($vectors as $vector) {
        for ($i = 0; $i < count($vector); $i++) {
            $average_vector[$i] += $vector[$i];
            if ($vector[$i] > $max_vector[$i]) {
                $max_vector[$i] = $vector[$i];
            }
        }
    }
    for ($i = 0; $i < count($average_vector); $i++) {
        $average_vector[$i] /= count($vectors);
    }
    return [$average_vector, $max_vector];
}

function main() {
    $data = load_data();
    $vectorizer = new Vectorizer($data);
    list($average, $maximum) = analyze_vectors($vectorizer->vectorized);
    echo 'Average Vector: ' . implode(', ', $average) . "\n";
    echo 'Maximum Vector: ' . implode(', ', $maximum) . "\n";
}

main();

?>