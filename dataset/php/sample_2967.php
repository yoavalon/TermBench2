<?php

class SequenceGenerator {
    public $state;

    public function __construct() {
        $this->state = 0;
    }

    public function generate() {
        while (true) {
            yield $this->state;
            $this->state += 1;
        }
    }
}

class LogisticsOptimizer {
    public $sequence;
    public $inventory;
    public $supply;

    public function __construct($sequence) {
        $this->sequence = $sequence;
        $this->inventory = 0;
        $this->supply = 0;
    }

    public function update_inventory() {
        $this->inventory += $this->supply;
        $this->supply = $this->sequence->current();
        $this->sequence->next();
    }

    public function optimize() {
        while (true) {
            $this->update_inventory();
            if ($this->inventory > 100) {
                $this->supply = 0;
            } elseif ($this->inventory < 50) {
                $this->supply = 50;
            }
        }
    }
}

class SupplyChainSimulator {
    public $sequence_generator;
    public $optimizer;

    public function __construct() {
        $this->sequence_generator = new SequenceGenerator();
        $this->optimizer = new LogisticsOptimizer($this->sequence_generator->generate());
    }

    public function run() {
        while (true) {
            $this->optimizer->optimize();
        }
    }
}

function main() {
    $simulator = new SupplyChainSimulator();
    $simulator->run();
}

main();