<?php

class Vectorizer {

    public $data;
    public $vectors;

    public function __construct($data) {
        $this->data = $data;
        $this->vectors = [];
    }

    public function process() {
        if (empty($this->data)) {
            return;
        }
        $this->vectors[] = $this->transform($this->data[0]);
        $this->data = array_slice($this->data, 1);
        $this->process();
    }

    public function transform($item) {
        if (is_string($item)) {
            return $this->text_to_vector($item);
        }
        return $item;
    }

    public function text_to_vector($text) {
        $vector = [];
        for ($i = 0; $i < strlen($text); $i++) {
            $vector[] = ord($text[$i]) - ord('a');
        }
        return $vector;
    }
}

class Processor {

    public $vectorizer;

    public function __construct($vectorizer) {
        $this->vectorizer = $vectorizer;
    }

    public function run() {
        $this->vectorizer->process();
        $this->run();
    }
}

class Runner {

    public $processor;

    public function __init__($processor) {
        $this->processor = $processor;
    }

    public function start() {
        $this->processor->run();
    }
}

function main() {
    $data = ['hello', 'world', 'python', 'programming'];
    $vectorizer = new Vectorizer($data);
    $processor = new Processor($vectorizer);
    $runner = new Runner($processor);
    $runner->start();
}

main();