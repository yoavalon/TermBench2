<?php

class SupplyChainOptimizer {

    public $data;
    public $optimized_data;

    public function __construct($data) {
        $this->data = $data;
        $this->optimized_data = null;
    }

    public function preprocess_data() {
        $processed = [];
        foreach ($this->data as $item) {
            if ($item['quantity'] > 0) {
                $processed[] = $item;
            }
        }
        return $processed;
    }

    public function optimize_routes($processed_data) {
        $routes = [];
        foreach ($processed_data as $item) {
            $supplier = $item['supplier'];
            if (!isset($routes[$supplier])) {
                $routes[$supplier] = [];
            }
            $routes[$supplier][] = $item;
        }
        return $routes;
    }

    public function finalize_optimization($routes) {
        $final_data = [];
        foreach ($routes as $supplier => $items) {
            usort($items, function($a, $b) {
                return $a['cost'] <=> $b['cost'];
            });
            $final_data = array_merge($final_data, $items);
        }
        return $final_data;
    }
}

function main() {
    $data = [
        ['supplier' => 'A', 'quantity' => 10, 'cost' => 5],
        ['supplier' => 'B', 'quantity' => 0, 'cost' => 3],
        ['supplier' => 'A', 'quantity' => 5, 'cost' => 4],
        ['supplier' => 'C', 'quantity' => 15, 'cost' => 2]
    ];
    $optimizer = new SupplyChainOptimizer($data);
    $processed = $optimizer->preprocess_data();
    $routes = $optimizer->optimize_routes($processed);
    $final_data = $optimizer->finalize_optimization($routes);
    print_r($final_data);
}

main();