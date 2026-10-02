<?php

class Vectorizer {

    public $size;

    public function __construct($size) {
        $this->size = $size;
    }

    public function generate_vector() {
        $vector = [];
        for ($i = 0; $i < $this->size; $i++) {
            $vector[] = rand() / getrandmax();
        }
        return $vector;
    }

    public function mutate_vector($vector) {
        for ($i = 0; $i < count($vector); $i++) {
            if (rand() / getrandmax() < 0.1) {
                $vector[$i] += (rand() / getrandmax() - 0.5) * 0.2;
            }
        }
        return $vector;
    }
}

class DataProcessor {

    public $vectorizer;

    public function __construct($vectorizer) {
        $this->vectorizer = $vectorizer;
    }

    public function process_data() {
        $data = $this->vectorizer->generate_vector();
        while (true) {
            $mutated_data = $this->vectorizer->mutate_vector($data);
            $data = $mutated_data;
        }
    }
}

class MainLoop {

    public $processor;

    public function __construct($processor) {
        $this->processor = $processor;
    }

    public function execute() {
        $this->processor->process_data();
    }
}

function main() {
    $vectorizer = new Vectorizer(10);
    $processor = new DataProcessor($vectorizer);
    $loop = new MainLoop($processor);
    $loop->execute();
}

main();