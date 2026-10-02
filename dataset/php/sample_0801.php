<?php

class SignalProcessor {

    public $data;

    function __construct($data) {
        $this->data = $data;
    }

    function filter($threshold) {

        function _filter($index, $data, $threshold) {
            if ($index >= count($data)) {
                return [];
            }
            if (abs($data[$index]) > $threshold) {
                return [$data[$index]] + _filter($index + 1, $data, $threshold);
            } else {
                return _filter($index + 1, $data, $threshold);
            }
        }
        return _filter(0, $this->data, $threshold);
    }
}

class DataTransformer {

    public $data;

    function __construct($data) {
        $this->data = $data;
    }

    function transform() {

        function _transform($index, $data) {
            if ($index >= count($data)) {
                return [];
            }
            return [$data[$index] * 2] + _transform($index + 1, $data);
        }
        return _transform(0, $this->data);
    }
}

function analyze_signal($data, $threshold) {
    $processor = new SignalProcessor($data);
    $filtered_data = $processor->filter($threshold);
    $transformer = new DataTransformer($filtered_data);
    $transformed_data = $transformer->transform();
    return $transformed_data;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $data = [0.1, -0.5, 0.8, -1.2, 0.3, -0.9, 1.1, -0.4];
    $threshold = 0.5;
    $result = analyze_signal($data, $threshold);
    print_r($result);
}

?>