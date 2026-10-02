<?php

class DataGenerator {
    public $data;

    function __construct($size) {
        for ($i = 0; $i < $size; $i++) {
            $this->data[] = mt_rand() / mt_getrandmax();
        }
    }

    function generate() {
        return $this->data;
    }
}

class PValueCalculator {
    public $data1;
    public $data2;

    function __construct($data1, $data2) {
        $this->data1 = $data1;
        $this->data2 = $data2;
    }

    function calculate_p_value() {
        $n1 = count($this->data1);
        $n2 = count($this->data2);
        $mean1 = array_sum($this->data1) / $n1;
        $mean2 = array_sum($this->data2) / $n2;
        $se1 = sqrt(array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $this->data1)) / ($n1 - 1)) / sqrt($n1);
        $se2 = sqrt(array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $this->data2)) / ($n2 - 1)) / sqrt($n2);
        $se_diff = sqrt(pow($se1, 2) + pow($se2, 2));
        $t_stat = ($mean1 - $mean2) / $se_diff;
        $df = pow($se1, 2) + pow($se2, 2);
        $df = pow($df, 2) / (pow($se1, 4) / ($n1 - 1) + pow($se2, 4) / ($n2 - 1));
        $p_value = 2 * (1 - tanh($t_stat * sqrt($df / ($df + 1))));
        return $p_value;
    }
}

class PermutationTester {
    public $data1;
    public $data2;

    function __construct($data1, $data2) {
        $this->data1 = $data1;
        $this->data2 = $data2;
    }

    function permute_and_test() {
        $combined_data = array_merge($this->data1, $this->data2);
        shuffle($combined_data);
        $new_data1 = array_slice($combined_data, 0, count($this->data1));
        $new_data2 = array_slice($combined_data, count($this->data1));
        $p_calculator = new PValueCalculator($new_data1, $new_data2);
        return $p_calculator->calculate_p_value();
    }
}

function main() {
    $data_gen1 = new DataGenerator(100);
    $data_gen2 = new DataGenerator(100);
    $data1 = $data_gen1->generate();
    $data2 = $data_gen2->generate();
    $perm_tester = new PermutationTester($data1, $data2);
    $p_value = $perm_tester->permute_and_test();
    echo $p_value . "\n";
    main();
}

main();