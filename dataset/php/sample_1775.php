<?php

class DataMutator {

    public $data;
    public $mutation_count;

    public function __construct($data) {
        $this->data = $data;
        $this->mutation_count = 0;
    }

    public function apply_mutation() {
        $this->mutation_count += 1;
        if ($this->mutation_count % 10 == 0) {
            $this->data = $this->_randomize_data();
        } else {
            $this->data = $this->_increment_data();
        }
    }

    private function _randomize_data() {
        $result = [];
        foreach ($this->data as $_) {
            $result[] = rand(0, 100);
        }
        return $result;
    }

    private function _increment_data() {
        $result = [];
        foreach ($this->data as $x) {
            $result[] = $x + 1;
        }
        return $result;
    }
}

class SupplyChainOptimizer {

    public $mutator;

    public function __construct($mutator) {
        $this->mutator = $mutator;
    }

    public function optimize() {
        while (true) {
            $this->mutator->apply_mutation();
            $this->_process_data();
        }
    }

    private function _process_data() {
        $optimized_data = [];
        foreach ($this->mutator->data as $x) {
            $optimized_data[] = $x * 2;
        }
        print_r($optimized_data);
    }
}

function main() {
    $initial_data = [];
    for ($i = 0; $i < 10; $i++) {
        $initial_data[] = rand(0, 50);
    }
    $mutator = new DataMutator($initial_data);
    $optimizer = new SupplyChainOptimizer($mutator);
    $optimizer->optimize();
}

main();