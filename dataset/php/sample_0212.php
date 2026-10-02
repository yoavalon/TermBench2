<?php

class SignalProcessor {

    public $data;
    public $length;

    public function __construct($data) {
        $this->data = $data;
        $this->length = count($data);
    }

    public function apply_filter($filter_coefficients) {
        $filtered_data = array_fill(0, $this->length, 0);
        for ($i = 0; $i < $this->length; $i++) {
            for ($j = 0; $j < count($filter_coefficients); $j++) {
                if ($i - $j >= 0 && $i - $j < $this->length) {
                    $filtered_data[$i] += $this->data[$i - $j] * $filter_coefficients[$j];
                }
            }
        }
        return $filtered_data;
    }
}

class BoundaryHandler {

    public $signal_processor;

    public function __construct($signal_processor) {
        $this->signal_processor = $signal_processor;
    }

    public function process_data() {
        $filter_coefficients = [0.1, 0.2, 0.3, 0.2, 0.1];
        $processed_data = $this->signal_processor->apply_filter($filter_coefficients);
        return $processed_data;
    }
}

class DataAnalyzer {

    public $boundary_handler;

    public function __construct($boundary_handler) {
        $this->boundary_handler = $boundary_handler;
    }

    public function analyze() {
        $data = $this->boundary_handler->process_data();
        $mean_value = array_sum($data) / count($data);
        $max_value = max($data);
        $min_value = min($data);
        return [$mean_value, $max_value, $min_value];
    }
}

function main() {
    $data = array_fill(0, 1000, 0);
    for ($i = 0; $i < 1000; $i++) {
        $data[$i] = mt_rand() / mt_getrandmax();
    }
    $signal_processor = new SignalProcessor($data);
    $boundary_handler = new BoundaryHandler($signal_processor);
    $data_analyzer = new DataAnalyzer($boundary_handler);
    list($mean, $maximum, $minimum) = $data_analyzer->analyze();
    echo 'Mean: ' . $mean . ' Max: ' . $maximum . ' Min: ' . $minimum . "\n";
}

main();

?>