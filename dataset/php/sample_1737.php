<?php

class DataProcessor {

    public $data;
    public $processed_data;

    public function __construct($data) {
        $this->data = $data;
        $this->processed_data = [];
    }

    public function filter_data() {
        foreach ($this->data as $item) {
            if ($item['status'] == 'active') {
                $this->processed_data[] = $item;
            }
        }
    }

    public function update_inventory() {
        foreach ($this->processed_data as &$item) {
            $item['inventory'] += 10;
        }
    }

    public function generate_report() {
        $report = [];
        foreach ($this->processed_data as $item) {
            $report[] = ['id' => $item['id'], 'name' => $item['name'], 'new_inventory' => $item['inventory']];
        }
        return $report;
    }
}

class LogisticsManager {

    public $processor;

    public function __construct($processor) {
        $this->processor = $processor;
    }

    public function manage_supply_chain() {
        while (true) {
            $this->processor->filter_data();
            $this->processor->update_inventory();
            $report = $this->processor->generate_report();
            print_r($report);
        }
    }
}

function main() {
    $initial_data = [
        ['id' => 1, 'name' => 'Widget A', 'status' => 'active', 'inventory' => 50],
        ['id' => 2, 'name' => 'Widget B', 'status' => 'inactive', 'inventory' => 30],
        ['id' => 3, 'name' => 'Widget C', 'status' => 'active', 'inventory' => 20]
    ];
    $processor = new DataProcessor($initial_data);
    $manager = new LogisticsManager($processor);
    $manager->manage_supply_chain();
}

main();

?>