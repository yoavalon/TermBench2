<?php

class DataProcessor {

    public function __construct($data) {
        $this->data = $data;
    }

    public function process_data() {
        $transformed_data = [];
        foreach ($this->data as $item) {
            if ($item['status'] == 'active') {
                $transformed_data[] = $this->modify_item($item);
            }
        }
        return $transformed_data;
    }

    public function modify_item($item) {
        $item['quantity'] *= 1.1;
        $item['cost'] *= 0.95;
        return $item;
    }
}

class DataMutator {

    public function __construct($processor) {
        $this->processor = $processor;
    }

    public function mutate_data() {
        $mutated_data = [];
        foreach ($this->processor->data as $item) {
            if ($item['category'] == 'critical') {
                $mutated_data[] = $this->alter_item($item);
            }
        }
        return $mutated_data;
    }

    public function alter_item($item) {
        $item['priority'] = 'high';
        $item['reorder'] = true;
        return $item;
    }
}

class DataAnalyzer {

    public function __construct($mutator) {
        $this->mutator = $mutator;
    }

    public function analyze_data() {
        $analysis = [];
        foreach ($this->mutator->mutated_data as $item) {
            if (!isset($analysis[$item['region']])) {
                $analysis[$item['region']] = ['total_cost' => 0, 'item_count' => 0];
            }
            $analysis[$item['region']]['total_cost'] += $item['cost'];
            $analysis[$item['region']]['item_count'] += 1;
        }
        return $analysis;
    }
}

function main() {
    $initial_data = [['status' => 'active', 'category' => 'critical', 'region' => 'north', 'quantity' => 100, 'cost' => 10], ['status' => 'inactive', 'category' => 'standard', 'region' => 'south', 'quantity' => 200, 'cost' => 20], ['status' => 'active', 'category' => 'critical', 'region' => 'east', 'quantity' => 150, 'cost' => 15], ['status' => 'active', 'category' => 'standard', 'region' => 'west', 'quantity' => 300, 'cost' => 30]];
    $processor = new DataProcessor($initial_data);
    $processed_data = $processor->process_data();
    $mutator = new DataMutator($processor);
    $mutated_data = $mutator->mutate_data();
    $analyzer = new DataAnalyzer($mutator);
    $analysis = $analyzer->analyze_data();
    print_r($analysis);
}

main();