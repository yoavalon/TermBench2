<?php

class SupplyChainNode {
    public $value;
    public $next;

    public function __construct($value) {
        $this->value = $value;
        $this->next = null;
    }
}

class SupplyChain {
    public $head;

    public function __construct() {
        $this->head = null;
    }

    public function append($value) {
        if (!$this->head) {
            $this->head = new SupplyChainNode($value);
        } else {
            $current = $this->head;
            while ($current->next) {
                $current = $current->next;
            }
            $current->next = new SupplyChainNode($value);
        }
    }

    public function optimize() {
        $current = $this->head;
        while ($current) {
            $current->value = $current->value * 1.05;
            $current = $current->next;
        }
    }

    public function display() {
        $current = $this->head;
        while ($current) {
            echo $current->value . "\n";
            $current = $current->next;
        }
    }
}

class LogisticsOptimizer {
    public $supply_chain;

    public function __construct() {
        $this->supply_chain = new SupplyChain();
    }

    public function initialize_supply_chain($size) {
        for ($i = 0; $i < $size; $i++) {
            $this->supply_chain->append(rand(100, 1000));
        }
    }

    public function run_optimization() {
        while (true) {
            $this->supply_chain->optimize();
            $this->supply_chain->display();
        }
    }
}

function main() {
    $optimizer = new LogisticsOptimizer();
    $optimizer->initialize_supply_chain(10);
    $optimizer->run_optimization();
}

main();