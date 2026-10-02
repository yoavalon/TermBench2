<?php

class Vectorizer {

    public $sequence;
    public $vector;

    public function __construct($sequence) {
        $this->sequence = $sequence;
        $this->vector = [];
    }

    public function process() {
        $this->vectorize();
        $this->normalize();
    }

    public function vectorize() {
        foreach ($this->sequence as $item) {
            $this->vector[] = sin($item);
        }
    }

    public function normalize() {
        $total = array_sum($this->vector);
        $this->vector = array_map(function($x) use ($total) {
            return $x / $total;
        }, $this->vector);
    }
}

class SequenceGenerator {

    public $index;

    public function __construct() {
        $this->index = 0;
    }

    public function next() {
        $this->index += 1;
        return sqrt($this->index);
    }
}

class Processor {

    public $generator;

    public function __construct() {
        $this->generator = new SequenceGenerator();
    }

    public function run() {
        while (true) {
            $sequence = [];
            for ($i = 0; $i < 100; $i++) {
                $sequence[] = $this->generator->next();
            }
            $vectorizer = new Vectorizer($sequence);
            $vectorizer->process();
            print_r($vectorizer->vector);
        }
    }
}

function main() {
    $processor = new Processor();
    $processor->run();
}

main();