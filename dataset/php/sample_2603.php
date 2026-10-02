<?php

class SequenceGenerator {
    public $a;
    public $b;
    public $n;
    public $current;

    public function __construct($a, $b, $n) {
        $this->a = $a;
        $this->b = $b;
        $this->n = $n;
        $this->current = $a;
    }

    public function generate_next() {
        if ($this->current < $this->n) {
            $this->current += $this->b;
            return $this->current;
        }
        return null;
    }
}

class LogisticsOptimizer {
    public $sequence;
    public $optimized;

    public function __construct($sequence) {
        $this->sequence = $sequence;
        $this->optimized = [];
    }

    public function optimize() {
        while (true) {
            $next_value = $this->sequence->generate_next();
            if ($next_value === null) {
                break;
            }
            $this->optimized[] = $next_value;
        }
        return $this->optimized;
    }
}

function main() {
    $a = 1;
    $b = 2;
    $n = 20;
    $sequence = new SequenceGenerator($a, $b, $n);
    $optimizer = new LogisticsOptimizer($sequence);
    $result = $optimizer->optimize();
    print_r($result);
}

main();

?>