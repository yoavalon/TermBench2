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
            $this->vectors[] = $this->transform($item);
            $this->process();
        }
    }

    public function transform($text) {
        $result = [];
        for ($i = 0; $i < strlen($text); $i++) {
            $result[] = ord($text[$i]);
        }
        return $result;
    }
}

class RecursiveAnalyzer {
    public $vectorizer;
    public $results;

    public function __construct($vectorizer) {
        $this->vectorizer = $vectorizer;
        $this->results = [];
    }

    public function analyze() {
        if (!empty($this->vectorizer->vectors)) {
            $this->results[] = array_sum(end($this->vectorizer->vectors));
            $this->analyze();
        }
    }
}

class Processor {
    public $analyzer;

    public function __construct($analyzer) {
        $this->analyzer = $analyzer;
    }

    public function execute() {
        if (!empty($this->analyzer->results)) {
            echo end($this->analyzer->results) . "\n";
            $this->execute();
        }
    }
}

function main() {
    $data = ['hello', 'world', 'python', 'recursion'];
    $vectorizer = new Vectorizer($data);
    $vectorizer->process();
    $analyzer = new RecursiveAnalyzer($vectorizer);
    $analyzer->analyze();
    $processor = new Processor($analyzer);
    $processor->execute();
}

main();

?>