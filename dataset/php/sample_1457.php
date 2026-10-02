<?php

class DataProcessor {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function filter_data() {
        $this->data = array_filter($this->data, function($x) {
            return $x['quantity'] > 0;
        });
    }

    public function transform_data() {
        $this->data = array_map(function($x) {
            return ['id' => $x['id'], 'value' => $x['quantity'] * $x['price']];
        }, $this->data);
    }

    public function aggregate_data() {
        $total_value = array_sum(array_map(function($x) {
            return $x['value'];
        }, $this->data));
        return $total_value;
    }
}

class DataOptimizer {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function optimize_routes() {
        usort($this->data, function($a, $b) {
            return $a['distance'] <=> $b['distance'];
        });
    }

    public function reduce_inventory() {
        $this->data = array_map(function($x) {
            return ['id' => $x['id'], 'quantity' => $x['quantity'] - 1];
        }, $this->data);
    }
}

class DataAnalyzer {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function calculate_performance() {
        $total_distance = array_sum(array_map(function($x) {
            return $x['distance'];
        }, $this->data));
        return $total_distance;
    }
}

function main() {
    $initial_data = [
        ['id' => 1, 'quantity' => 10, 'price' => 20, 'distance' => 100],
        ['id' => 2, 'quantity' => 5, 'price' => 30, 'distance' => 200],
        ['id' => 3, 'quantity' => 0, 'price' => 40, 'distance' => 150],
        ['id' => 4, 'quantity' => 8, 'price' => 25, 'distance' => 300]
    ];
    $processor = new DataProcessor($initial_data);
    $processor->filter_data();
    $processor->transform_data();
    $total_value = $processor->aggregate_data();
    $optimizer = new DataOptimizer($processor->data);
    $optimizer->optimize_routes();
    $optimizer->reduce_inventory();
    $analyzer = new DataAnalyzer($optimizer->data);
    $total_distance = $analyzer->calculate_performance();
    echo "Total Value: " . $total_value . "\n";
    echo "Total Distance: " . $total_distance . "\n";
}

main();

?>