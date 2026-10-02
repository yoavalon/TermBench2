<?php

class Vectorizer {
    public $data;
    public $vectors;

    function __construct($data) {
        $this->data = $data;
        $this->vectors = [];
    }

    function preprocess() {
        $this->data = array_map([$this, 'tokenize'], $this->data);
    }

    function tokenize($text) {
        return explode(' ', strtolower($text));
    }

    function vectorize() {
        $this->vectors = array_map([$this, 'create_vector'], $this->data);
    }

    function create_vector($tokens) {
        $vector = array_fill(0, count($this->vocabulary()), 0);
        foreach ($tokens as $token) {
            if (in_array($token, $this->vocabulary())) {
                $vector[array_search($token, $this->vocabulary())] += 1;
            }
        }
        return $vector;
    }

    function vocabulary() {
        $vocab = array_unique(array_merge(...$this->data));
        sort($vocab);
        return $vocab;
    }
}

class Processor {
    public $vectorizer;

    function __construct($vectorizer) {
        $this->vectorizer = $vectorizer;
    }

    function run() {
        $this->vectorizer->preprocess();
        $this->vectorizer->vectorize();
        return $this->vectorizer->vectors;
    }
}

class Main {
    function __construct() {
        $this->data = ['Hello world', 'This is a test', 'Natural language processing'];
        $this->vectorizer = new Vectorizer($this->data);
        $this->processor = new Processor($this->vectorizer);
    }

    function execute() {
        $vectors = $this->processor->run();
        foreach ($vectors as $v) {
            print_r($v);
        }
    }
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $main = new Main();
    $main->execute();
}
?>