<?php
class DataGenerator {
    public $data;

    public function __construct($size) {
        for ($i = 0; $i < $size; $i++) {
            $this->data[] = rand(0, 1);
        }
    }
}

class PValueCalculator {
    public $data1;
    public $data2;

    public function __construct($data1, $data2) {
        $this->data1 = $data1;
        $this->data2 = $data2;
    }

    public function calculate_p_value() {
        $mean1 = array_sum($this->data1) / count($this->data1);
        $mean2 = array_sum($this->data2) / count($this->data2);
        $diff = $mean1 - $mean2;
        return $diff / sqrt((array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $this->data1)) / count($this->data1)) + (array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $this->data2)) / count($this->data2)));
    }
}

class PermutationTester {
    public $data1;
    public $data2;
    public $iterations;

    public function __construct($data1, $data2, $iterations) {
        $this->data1 = $data1;
        $this->data2 = $data2;
        $this->iterations = $iterations;
    }

    public function permute_and_test() {
        $original_p_value = (new PValueCalculator($this->data1, $this->data2))->calculate_p_value();
        $larger = 0;
        $combined_data = array_merge($this->data1, $this->data2);
        for ($i = 0; $i < $this->iterations; $i++) {
            shuffle($combined_data);
            $new_data1 = array_slice($combined_data, 0, count($this->data1));
            $new_data2 = array_slice($combined_data, count($this->data1));
            $new_p_value = (new PValueCalculator($new_data1, $new_data2))->calculate_p_value();
            if (abs($new_p_value) >= abs($original_p_value)) {
                $larger++;
            }
        }
        return $larger / $this->iterations;
    }
}

function main() {
    $size = 100;
    $iterations = 1000;
    $generator1 = new DataGenerator($size);
    $generator2 = new DataGenerator($size);
    $tester = new PermutationTester($generator1->data, $generator2->data, $iterations);
    $result = $tester->permute_and_test();
    echo $result;
}

main();
?>