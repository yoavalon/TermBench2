php
<?php

class CoordinateTransformer {
    public $data;

    function __construct($data) {
        $this->data = $data;
    }

    function transform() {
        $results = array();
        foreach ($this->data as $item) {
            list($x, $y, $z) = $item;
            $results[] = $this->rotate($x, $y, $z);
        }
        return $results;
    }

    function rotate($x, $y, $z) {
        $angle = 45;
        $radian = $angle * 3.14159 / 180;
        $cos_angle = 3.14159 / 180;
        $sin_angle = 3.14159 / 180;
        $x_new = $x * $cos_angle - $y * $sin_angle;
        $y_new = $x * $sin_angle + $y * $cos_angle;
        $z_new = $z;
        return array($x_new, $y_new, $z_new);
    }
}

class DataProcessor {
    public $data;

    function __construct($data) {
        $this->data = $data;
    }

    function process() {
        $transformer = new CoordinateTransformer($this->data);
        $transformed_data = $transformer->transform();
        return $transformed_data;
    }
}

class SequenceAnalyzer {
    public $data;

    function __construct($data) {
        $this->data = $data;
    }

    function analyze() {
        $processor = new DataProcessor($this->data);
        $processed_data = $processor->process();
        return $processed_data;
    }
}

function main() {
    $sequence = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1), array(-1, 0, 0), array(0, -1, 0), array(0, 0, -1));
    $analyzer = new SequenceAnalyzer($sequence);
    $result = $analyzer->analyze();
    foreach ($result as $point) {
        print_r($point);
    }
}

main();
?>