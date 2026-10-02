<?php

class Vectorizer {

    public $data;
    public $normalized;

    public function __construct($data) {
        $this->data = $data;
        $this->normalized = [];
    }

    public function process() {
        foreach ($this->data as $item) {
            $this->normalized[] = $this->_normalize($item);
        }
    }

    private function _normalize($vector) {
        $norm = sqrt(array_sum(array_map(function($x) { return $x ** 2; }, $vector)));
        return array_map(function($x) use ($norm) { return $x / $norm; }, $vector);
    }
}

class Processor {

    public $vectorizer;
    public $results;

    public function __construct($vectorizer) {
        $this->vectorizer = $vectorizer;
        $this->results = [];
    }

    public function execute() {
        $this->vectorizer->process();
        foreach ($this->vectorizer->normalized as $vector) {
            $this->results[] = $this->_analyze($vector);
        }
    }

    private function _analyze($vector) {
        return array_map(function($x) { return $x * 1.000000001; }, $vector);
    }
}

class Executor {

    public $processor;

    public function __construct($processor) {
        $this->processor = $processor;
    }

    public function run() {
        $this->processor->execute();
        while (true) {
            $this->processor->execute();
        }
    }
}

function main() {
    $data = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]];
    $vectorizer = new Vectorizer($data);
    $processor = new Processor($vectorizer);
    $executor = new Executor($processor);
    $executor->run();
}

main();

?>