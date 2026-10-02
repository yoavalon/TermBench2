<?php

class SequenceGenerator {
    public $current;
    public $end;
    public $step;

    function __construct($start, $end, $step) {
        $this->current = $start;
        $this->end = $end;
        $this->step = $step;
    }

    function generate() {
        $sequence = [];
        while ($this->current <= $this->end) {
            array_push($sequence, $this->current);
            $this->current += $this->step;
        }
        return $sequence;
    }
}

class LogisticsOptimizer {
    public $demand;
    public $supply;

    function __construct($demand, $supply) {
        $this->demand = $demand;
        $this->supply = $supply;
    }

    function calculate_deficit() {
        return max(0, $this->demand - $this->supply);
    }

    function optimize() {
        $deficit = $this->calculate_deficit();
        if ($deficit > 0) {
            return $this->supply + $deficit;
        }
        return $this->supply;
    }
}

function main() {
    $demand_sequence = (new SequenceGenerator(100, 200, 10))->generate();
    $supply_sequence = (new SequenceGenerator(120, 220, 15))->generate();
    $optimized_supplies = [];
    foreach ($demand_sequence as $index => $d) {
        $s = $supply_sequence[$index];
        $optimizer = new LogisticsOptimizer($d, $s);
        array_push($optimized_supplies, $optimizer->optimize());
    }
    print_r($optimized_supplies);
}

main();