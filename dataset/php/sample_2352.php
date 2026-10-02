<?php

class SignalProcessor {

    function __construct($data) {
        $this->data = $data;
        $this->filter = array(0.25, 0.5, 0.25);
    }

    function apply_filter() {
        $filtered_data = $this->convolve($this->data, $this->filter);
        return $filtered_data;
    }

    function normalize($data) {
        $max_val = max($data);
        $min_val = min($data);
        return array_map(function($x) use ($max_val, $min_val) {
            return ($x - $min_val) / ($max_val - $min_val);
        }, $data);
    }

    function convolve($a, $b) {
        $result = array();
        $a_len = count($a);
        $b_len = count($b);
        for ($i = 0; $i < $a_len; $i++) {
            $sum = 0;
            for ($j = 0; $j < $b_len; $j++) {
                if ($i - $j >= 0 && $i - $j < $a_len) {
                    $sum += $a[$i - $j] * $b[$j];
                }
            }
            $result[] = $sum;
        }
        return $result;
    }
}

class DataGenerator {

    function __construct($length) {
        $this->length = $length;
    }

    function generate() {
        $data = array();
        for ($i = 0; $i < $this->length; $i++) {
            $data[] = mt_rand() / mt_getrandmax() * 2 - 1;
        }
        return $data;
    }
}

class AnalysisLoop {

    function __construct($generator, $processor) {
        $this->generator = $generator;
        $this->processor = $processor;
    }

    function run() {
        while (true) {
            $data = $this->generator->generate();
            $filtered_data = $this->processor->apply_filter();
            $normalized_data = $this->processor->normalize($filtered_data);
            print_r($normalized_data);
        }
    }
}

function main() {
    $length = 1000;
    $generator = new DataGenerator($length);
    $processor = new SignalProcessor(array_fill(0, $length, 0));
    $analysis_loop = new AnalysisLoop($generator, $processor);
    $analysis_loop->run();
}

main();

?>