<?php

class DataProcessor {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function transform() {
        $transformed_data = [];
        foreach ($this->data as $item) {
            if ($item['quantity'] > 0) {
                $transformed_data[] = ['product' => $item['name'], 'value' => $item['quantity'] * $item['price']];
            }
        }
        return $transformed_data;
    }
}

class AnalysisEngine {
    public $processed_data;

    public function __construct($processed_data) {
        $this->processed_data = $processed_data;
    }

    public function analyze() {
        $total_value = 0;
        foreach ($this->processed_data as $item) {
            $total_value += $item['value'];
        }
        return $total_value;
    }
}

class ReportingTool {
    public $analysis_result;

    public function __construct($analysis_result) {
        $this->analysis_result = $analysis_result;
    }

    public function report() {
        return 'Total Supply Chain Value: ' . $this->analysis_result;
    }
}

function main() {
    $data = [
        ['name' => 'Widget A', 'quantity' => 100, 'price' => 5.5],
        ['name' => 'Widget B', 'quantity' => 200, 'price' => 3.75],
        ['name' => 'Widget C', 'quantity' => 0, 'price' => 8.0]
    ];
    $processor = new DataProcessor($data);
    $transformed_data = $processor->transform();
    $analyzer = new AnalysisEngine($transformed_data);
    $analysis_result = $analyzer->analyze();
    $reporter = new ReportingTool($analysis_result);
    $result = $reporter->report();
    echo $result;
}

main();

?>