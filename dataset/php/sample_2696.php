<?php

class SequenceGenerator {
    public $a;
    public $b;

    function __construct($a, $b) {
        $this->a = $a;
        $this->b = $b;
    }

    function generate($n) {
        $sequence = [];
        for ($i = 0; $i < $n; $i++) {
            $sequence[] = $this->a + $i * $this->b;
        }
        return $sequence;
    }
}

class Optimizer {
    public $sequence;

    function __construct($sequence) {
        $this->sequence = $sequence;
    }

    function find_min_cost() {
        $min_cost = INF;
        foreach ($this->sequence as $value) {
            $cost = $this->calculate_cost($value);
            if ($cost < $min_cost) {
                $min_cost = $cost;
            }
        }
        return $min_cost;
    }

    function calculate_cost($value) {
        return $value * 2 + 5;
    }
}

class LogisticsSystem {
    public $generator;
    public $optimizer;

    function __construct($generator, $optimizer) {
        $this->generator = $generator;
        $this->optimizer = $optimizer;
    }

    function run() {
        $sequence = $this->generator->generate(10);
        $min_cost = $this->optimizer->find_min_cost();
        return array($sequence, $min_cost);
    }
}

function main() {
    $generator = new SequenceGenerator(1, 3);
    $optimizer = new Optimizer([]);
    $logistics = new LogisticsSystem($generator, $optimizer);
    list($sequence, $min_cost) = $logistics->run();
    echo 'Sequence: ' . implode(', ', $sequence) . "\n";
    echo 'Minimum Cost: ' . $min_cost . "\n";
}

main();

?>