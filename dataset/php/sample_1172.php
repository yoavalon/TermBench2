<?php

class PermutationGenerator {
    public $data;
    public $permutations;

    function __construct($data) {
        $this->data = $data;
        $this->permutations = [];
    }

    function generate($current = null, $remaining = null) {
        if ($current === null) {
            $current = [];
        }
        if ($remaining === null) {
            $remaining = $this->data;
        }
        if (empty($remaining)) {
            array_push($this->permutations, $current);
        } else {
            for ($i = 0; $i < count($remaining); $i++) {
                $new_current = array_merge($current, [$remaining[$i]]);
                $new_remaining = array_merge(array_slice($remaining, 0, $i), array_slice($remaining, $i + 1));
                $this->generate($new_current, $new_remaining);
            }
        }
    }
}

class PValueCalculator {
    public $observed_statistic;
    public $data;
    public $permutations;

    function __construct($observed_statistic, $data) {
        $this->observed_statistic = $observed_statistic;
        $this->data = $data;
        $this->permutations = [];
    }

    function calculate() {
        $generator = new PermutationGenerator($this->data);
        $generator->generate();
        $this->permutations = $generator->permutations;
    }

    function get_p_value() {
        $this->calculate();
        $more_extreme = 0;
        foreach ($this->permutations as $perm) {
            if ($this->statistic($perm) >= $this->observed_statistic) {
                $more_extreme++;
            }
        }
        return $more_extreme / count($this->permutations);
    }

    function statistic($data) {
        return array_sum($data);
    }
}

class Analysis {
    public $data;
    public $observed_statistic;
    public $p_value_calculator;

    function __construct($data, $observed_statistic) {
        $this->data = $data;
        $this->observed_statistic = $observed_statistic;
        $this->p_value_calculator = new PValueCalculator($observed_statistic, $data);
    }

    function perform() {
        $p_value = $this->p_value_calculator->get_p_value();
        echo 'P-value: ' . $p_value . "\n";
    }
}

function main() {
    $data = [];
    for ($i = 0; $i < 10; $i++) {
        array_push($data, rand(1, 100));
    }
    $observed_statistic = array_sum($data) / count($data);
    $analysis = new Analysis($data, $observed_statistic);
    $analysis->perform();
}

main();