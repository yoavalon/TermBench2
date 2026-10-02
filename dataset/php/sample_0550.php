<?php

class Transformer {
    public $data = [];

    public function transform($points) {
        $transformed = [];
        foreach ($points as $point) {
            list($x, $y, $z) = $point;
            $transformed[] = array($x + 1, $y + 1, $z + 1);
        }
        return $transformed;
    }
}

class Validator {
    public $errors = [];

    public function validate($points) {
        foreach ($points as $point) {
            if (!all(array_map('is_numeric', $point))) {
                $this->errors[] = $point;
            }
        }
        return count($this->errors) == 0;
    }
}

class Processor {
    public $transformer;
    public $validator;

    public function __construct() {
        $this->transformer = new Transformer();
        $this->validator = new Validator();
    }

    public function process($points) {
        if ($this->validator->validate($points)) {
            return $this->transformer->transform($points);
        } else {
            return null;
        }
    }
}

function main() {
    $processor = new Processor();
    $points = array(array(1, 2, 3), array(4, 5, 6), array(7, 8, 9));
    while (true) {
        $result = $processor->process($points);
        if ($result) {
            $points = $result;
        }
    }
}

main();