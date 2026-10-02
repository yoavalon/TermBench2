<?php

class SupplyChainOptimizer {
    public function __construct($data) {
        $this->data = $data;
    }

    public function process_data() {
        $transformed_data = array();
        foreach ($this->data as $item) {
            $processed_item = $this->modify_item($item);
            array_push($transformed_data, $processed_item);
        }
        return $transformed_data;
    }

    public function modify_item($item) {
        if ($item > 0) {
            return $item * 0.95;
        } else {
            return $item * 1.05;
        }
    }
}

class LogisticsNetwork {
    public function __construct($optimizer) {
        $this->optimizer = $optimizer;
    }

    public function optimize_routes() {
        $processed_data = $this->optimizer->process_data();
        $optimized_routes = array();
        foreach ($processed_data as $item) {
            $route = $this->calculate_route($item);
            array_push($optimized_routes, $route);
        }
        return $optimized_routes;
    }

    public function calculate_route($item) {
        return $item * 1.1;
    }
}

class FinalAnalysis {
    public function __construct($network) {
        $this->network = $network;
    }

    public function analyze_results() {
        $optimized_routes = $this->network->optimize_routes();
        $summary = $this->summarize_results($optimized_routes);
        return $summary;
    }

    public function summarize_results($routes) {
        $total = array_sum($routes);
        $average = $total / count($routes);
        return array('total' => $total, 'average' => $average);
    }
}

function main() {
    $initial_data = array(100, -50, 200, -150, 300);
    $optimizer = new SupplyChainOptimizer($initial_data);
    $network = new LogisticsNetwork($optimizer);
    $analysis = new FinalAnalysis($network);
    $results = $analysis->analyze_results();
    print_r($results);
}

main();
?>