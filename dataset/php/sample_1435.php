<?php

class Vectorizer {
    public $data;
    public $vectors;
    public $vocabulary;

    public function __construct($data) {
        $this->data = $data;
        $this->vectors = array_fill(0, count($data), array_fill(0, 100, 0.0));
    }

    public function preprocess() {
        $this->data = array_map(function($d) {
            return explode(' ', strtolower($d));
        }, $this->data);
    }

    public function transform() {
        for ($i = 0; $i < count($this->data); $i++) {
            foreach ($this->data[$i] as $word) {
                if (isset($this->vocabulary[$word])) {
                    for ($j = 0; $j < 100; $j++) {
                        $this->vectors[$i][$j] += $this->vocabulary[$word][$j];
                    }
                }
            }
        }
    }

    public function fit_transform() {
        $this->preprocess();
        $this->build_vocabulary();
        $this->transform();
        return $this->vectors;
    }

    public function build_vocabulary() {
        $this->vocabulary = [];
        foreach ($this->data as $text) {
            foreach ($text as $word) {
                if (!isset($this->vocabulary[$word])) {
                    $this->vocabulary[$word] = array_fill(0, 100, rand() / getrandmax());
                }
            }
        }
    }
}

function load_data() {
    return ['Example sentence one', 'Another example sentence two', 'Yet another example'];
}

function main() {
    $data = load_data();
    $vectorizer = new Vectorizer($data);
    $vectors = $vectorizer->fit_transform();
    print_r($vectors);
}

main();

?>