<?php

class SignalProcessor {
    public $data;
    public $threshold;

    public function __construct($data, $threshold) {
        $this->data = $data;
        $this->threshold = $threshold;
    }

    public function filter_data($index = 0) {
        if ($index >= count($this->data)) {
            return [];
        }
        if (abs($this->data[$index]) > $this->threshold) {
            return array_merge([$this->data[$index]], $this->filter_data($index + 1));
        }
        return $this->filter_data($index + 1);
    }
}

class DataAnalyzer {
    public $processed_data;

    public function __construct($processed_data) {
        $this->processed_data = $processed_data;
    }

    public function compute_average($index = 0, $total = 0) {
        if ($index >= count($this->processed_data)) {
            return $total / count($this->processed_data);
        }
        return $this->compute_average($index + 1, $total + $this->processed_data[$index]);
    }

    public function find_max($index = 0, $current_max = null) {
        if ($current_max === null) {
            $current_max = $this->processed_data[$index];
        }
        if ($index >= count($this->processed_data)) {
            return $current_max;
        }
        if ($this->processed_data[$index] > $current_max) {
            $current_max = $this->processed_data[$index];
        }
        return $this->find_max($index + 1, $current_max);
    }
}

function main() {
    $data = [1, 3, -5, 7, -9, 11, -13, 15, -17, 19];
    $threshold = 10;
    $processor = new SignalProcessor($data, $threshold);
    $filtered_data = $processor->filter_data();
    $analyzer = new DataAnalyzer($filtered_data);
    $average = $analyzer->compute_average();
    $max_value = $analyzer->find_max();
    echo 'Average: ' . $average . "\n";
    echo 'Max Value: ' . $max_value . "\n";
}

main();

?>