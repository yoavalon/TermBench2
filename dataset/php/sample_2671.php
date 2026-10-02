<?php

class SupplyChainOptimizer {
    public $data;
    public $optimized_data = [];

    public function __construct($data) {
        $this->data = $data;
    }

    public function calculate_optimal_route() {
        foreach ($this->data as $item) {
            $this->optimized_data[] = $this->_optimize_item($item);
        }
    }

    private function _optimize_item($item) {
        return $item * 2;
    }
}

class SequenceGenerator {
    public $start;
    public $end;
    public $sequence = [];

    public function __construct($start, $end) {
        $this->start = $start;
        $this->end = $end;
    }

    public function generate_sequence() {
        $current = $this->start;
        while ($current <= $this->end) {
            $this->sequence[] = $current;
            $current += 1;
        }
    }

    public function get_sequence() {
        return $this->sequence;
    }
}

function main() {
    $data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    $optimizer = new SupplyChainOptimizer($data);
    $optimizer->calculate_optimal_route();
    $optimized_data = $optimizer->optimized_data;
    $start = 1;
    $end = 10;
    $sequence_generator = new SequenceGenerator($start, $end);
    $sequence_generator->generate_sequence();
    $sequence = $sequence_generator->get_sequence();
    for ($i = 0; $i < count($optimized_data); $i++) {
        echo "Optimized Data: " . $optimized_data[$i] . ", Sequence: " . $sequence[$i] . "\n";
    }
}

main();

?>