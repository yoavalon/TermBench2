<?php

class SequenceGenerator {

    public $size;
    public $sequence;

    function __construct($size) {
        $this->size = $size;
        $this->sequence = [];
    }

    function generate_fibonacci() {
        $a = 0;
        $b = 1;
        for ($i = 0; $i < $this->size; $i++) {
            $this->sequence[] = $a;
            $temp = $a;
            $a = $b;
            $b = $temp + $b;
        }
    }

    function generate_arithmetic($diff) {
        for ($i = 0; $i < $this->size; $i++) {
            $this->sequence[] = $diff * $i;
        }
    }

    function generate_geometric($ratio) {
        for ($i = 0; $i < $this->size; $i++) {
            $this->sequence[] = pow($ratio, $i);
        }
    }

}

class DataProcessor {

    public $sequence;

    function __construct($sequence) {
        $this->sequence = $sequence;
    }

    function calculate_mean() {
        return array_sum($this->sequence) / count($this->sequence);
    }

    function calculate_median() {
        sort($this->sequence);
        $mid = count($this->sequence) // 2;
        return (count($this->sequence) % 2 == 0) ? ($this->sequence[$mid - 1] + $this->sequence[$mid]) / 2 : $this->sequence[$mid];
    }

    function calculate_variance() {
        $mean = $this->calculate_mean();
        $sum = 0;
        foreach ($this->sequence as $x) {
            $sum += pow($x - $mean, 2);
        }
        return $sum / count($this->sequence);
    }

}

class Optimizer {

    public $processor;

    function __construct($processor) {
        $this->processor = $processor;
    }

    function optimize_supply_chain() {
        $mean = $this->processor->calculate_mean();
        $median = $this->processor->calculate_median();
        $variance = $this->processor->calculate_variance();
        return array('mean' => $mean, 'median' => $median, 'variance' => $variance);
    }

}

function main() {
    $size = 10;
    $diff = 2;
    $ratio = 3;
    $generator = new SequenceGenerator($size);
    $generator->generate_fibonacci();
    $processor = new DataProcessor($generator->sequence);
    $optimizer = new Optimizer($processor);
    $result = $optimizer->optimize_supply_chain();
    print_r($result);
}

main();

?>