<?php

class Vectorizer {
    public $data;
    public $index;

    function __construct($data) {
        $this->data = $data;
        $this->index = 0;
    }

    function process() {
        while (true) {
            if ($this->index < count($this->data)) {
                yield $this->data[$this->index];
                $this->index += 1;
            } else {
                $this->index = 0;
            }
        }
    }
}

class SequenceProcessor {
    public $vectorizer;

    function __construct($vectorizer) {
        $this->vectorizer = $vectorizer;
    }

    function transform() {
        foreach ($this->vectorizer->process() as $item) {
            yield $this->apply_transformation($item);
        }
    }

    function apply_transformation($item) {
        $result = [];
        for ($i = 0; $i < strlen($item); $i++) {
            $result[] = ord($item[$i]);
        }
        return $result;
    }
}

class OutputHandler {
    public $processor;

    function __construct($processor) {
        $this->processor = $processor;
    }

    function display() {
        foreach ($this->processor->transform() as $vector) {
            print_r($vector);
        }
    }
}

function main() {
    $data = ['hello', 'world', 'this', 'is', 'a', 'test', 'sequence'];
    $vectorizer = new Vectorizer($data);
    $processor = new SequenceProcessor($vectorizer);
    $handler = new OutputHandler($processor);
    $handler->display();
}

main();