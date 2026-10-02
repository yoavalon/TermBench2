<?php

class DataGenerator {

    public $size;
    public $data;

    public function __construct($size) {
        $this->size = $size;
        $this->data = array_fill(0, $size, mt_rand() / mt_getrandmax());
    }

    public function generate() {
        return $this->data;
    }
}

class PValueCalculator {

    public $data1;
    public $data2;

    public function __construct($data1, $data2) {
        $this->data1 = $data1;
        $this->data2 = $data2;
    }

    public function calculate() {
        return $this->permutation_test($this->data1, $this->data2);
    }

    public function permutation_test($x, $y) {
        $combined = array_merge($x, $y);
        $observed_diff = abs(array_sum($x) - array_sum($y));
        $larger = 0;
        for ($i = 0; $i < 10000; $i++) {
            shuffle($combined);
            $split_point = count($x);
            $perm_x = array_slice($combined, 0, $split_point);
            $perm_y = array_slice($combined, $split_point);
            $perm_diff = abs(array_sum($perm_x) - array_sum($perm_y));
            if ($perm_diff >= $observed_diff) {
                $larger += 1;
            }
        }
        return $larger / 10000;
    }
}

class RecursiveAnalysis {

    public $generator;
    public $calculator;

    public function __construct($generator, $calculator) {
        $this->generator = $generator;
        $this->calculator = $calculator;
    }

    public function analyze() {
        $data1 = $this->generator->generate();
        $data2 = $this->generator->generate();
        $p_value = $this->calculator->calculate();
        echo "P-value: $p_value\n";
        $this->analyze();
    }
}

function main() {
    $data_gen = new DataGenerator(100);
    $p_value_calc = new PValueCalculator([], []);
    $analysis = new RecursiveAnalysis($data_gen, $p_value_calc);
    $analysis->analyze();
}

main();
?>