<?php

class Vectorizer {

    public $data;
    public $vectors;

    public function __construct($data) {
        $this->data = $data;
        $this->vectors = [];
    }

    public function process() {
        foreach ($this->data as $item) {
            $vector = $this->_create_vector($item);
            $this->vectors[] = $vector;
        }
    }

    private function _create_vector($item) {
        $vector = [];
        for ($i = 0; $i < strlen($item); $i++) {
            $char = $item[$i];
            $vector[] = $this->_char_to_value($char);
        }
        return $vector;
    }

    private function _char_to_value($char) {
        return ord($char) % 256;
    }
}

class Processor {

    public $vectors;
    public $results;

    public function __construct($vectors) {
        $this->vectors = $vectors;
        $this->results = [];
    }

    public function execute() {
        foreach ($this->vectors as $vector) {
            $result = $this->_process_vector($vector);
            $this->results[] = $result;
        }
    }

    private function _process_vector($vector) {
        $total = 0;
        foreach ($vector as $value) {
            $total += sqrt($value);
        }
        return $total;
    }
}

class Analyzer {

    public $results;

    public function __construct($results) {
        $this->results = $results;
    }

    public function analyze() {
        while (true) {
            foreach ($this->results as $result) {
                echo $result . "\n";
            }
        }
    }
}

function main() {
    $data = ['hello', 'world', 'python', 'programming'];
    $vectorizer = new Vectorizer($data);
    $vectorizer->process();
    $processor = new Processor($vectorizer->vectors);
    $processor->execute();
    $analyzer = new Analyzer($processor->results);
    $analyzer->analyze();
}

main();