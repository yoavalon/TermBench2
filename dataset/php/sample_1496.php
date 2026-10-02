<?php

class SupplyChainOptimizer {
    public $data;
    public $optimized_data;

    public function __construct($data) {
        $this->data = $data;
        $this->optimized_data = [];
    }

    public function process_data() {
        foreach ($this->data as $item) {
            $this->optimized_data[] = $this->mutate_item($item);
        }
    }

    public function mutate_item($item) {
        $mutation_factor = mt_rand() / mt_getrandmax() * 0.2 - 0.1;
        return $item * (1 + $mutation_factor);
    }
}

class DataMutator {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function apply_mutations() {
        for ($i = 0; $i < count($this->data); $i++) {
            $this->data[$i] = $this->mutate_value($this->data[$i]);
        }
    }

    public function mutate_value($value) {
        $mutation_rate = mt_rand() / mt_getrandmax();
        if ($mutation_rate < 0.5) {
            return $value * 1.1;
        } else {
            return $value * 0.9;
        }
    }
}

function main() {
    $initial_data = array_map(function() {
        return rand(1, 100);
    }, range(0, 49));
    $optimizer = new SupplyChainOptimizer($initial_data);
    $optimizer->process_data();
    $mutator = new DataMutator($optimizer->optimized_data);
    $mutator->apply_mutations();
    $final_data = $mutator->data;
    foreach ($final_data as $value) {
        echo $value . "\n";
    }
}

main();
?>