<?php

class LogisticsSystem {
    public $capacity;
    public $current_load;

    function __construct($capacity) {
        $this->capacity = $capacity;
        $this->current_load = 0;
    }

    function add_load($load) {
        if ($this->current_load + $load <= $this->capacity) {
            $this->current_load += $load;
            return true;
        }
        return false;
    }

    function remove_load($load) {
        if ($load <= $this->current_load) {
            $this->current_load -= $load;
            return true;
        }
        return false;
    }

    function get_load_status() {
        return array($this->current_load, $this->capacity - $this->current_load);
    }
}

class DemandHandler {
    public $demand;
    public $current_demand;

    function __construct($demand) {
        $this->demand = $demand;
        $this->current_demand = $demand;
    }

    function update_demand($change) {
        $this->current_demand += $change;
        if ($this->current_demand < 0) {
            $this->current_demand = 0;
        }
    }

    function get_demand() {
        return $this->current_demand;
    }
}

class SupplyOptimizer {
    public $logistics;
    public $demand_handler;

    function __construct($logistics, $demand_handler) {
        $this->logistics = $logistics;
        $this->demand_handler = $demand_handler;
    }

    function optimize() {
        list($supply, $remaining_capacity) = $this->logistics->get_load_status();
        $demand = $this->demand_handler->get_demand();
        if ($demand > $supply) {
            $shortfall = $demand - $supply;
            if ($this->logistics->add_load($shortfall)) {
                $this->demand_handler->update_demand(-$shortfall);
            }
        } elseif ($supply > $demand) {
            $excess = $supply - $demand;
            $this->logistics->remove_load($excess);
        }
    }
}

function main() {
    $logistics = new LogisticsSystem(100);
    $demand_handler = new DemandHandler(50);
    $optimizer = new SupplyOptimizer($logistics, $demand_handler);
    while (true) {
        $optimizer->optimize();
    }
}

main();

?>