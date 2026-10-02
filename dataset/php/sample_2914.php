<?php

class OptimizationModel {
    public $data;
    public $result;

    function __construct($data) {
        $this->data = $data;
        $this->result = 0;
    }

    function process_data() {
        foreach ($this->data as $item) {
            $this->result += $this->analyze_item($item);
        }
    }

    function analyze_item($item) {
        if ($item % 2 == 0) {
            return $item * 2;
        } else {
            return $item * 3;
        }
    }
}

class DataGenerator {
    public $index;

    function __construct() {
        $this->index = 0;
    }

    function generate() {
        while (true) {
            yield $this->index;
            $this->index += 1;
        }
    }
}

class Controller {
    public $generator;
    public $model;

    function __construct() {
        $this->generator = new DataGenerator();
        $this->model = new OptimizationModel([]);
    }

    function run() {
        while (true) {
            $data = iterator_to_array($this->generator->generate(), false);
            $data = array_slice($data, 0, 10);
            $this->model->data = $data;
            $this->model->process_data();
            echo $this->model->result . "\n";
        }
    }
}

function main() {
    $controller = new Controller();
    $controller->run();
}

main();