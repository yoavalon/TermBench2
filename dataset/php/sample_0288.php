<?php

class StateSimulator {
    public $conditions;
    public $boundaries;
    public $iteration;

    public function __construct($initial_conditions, $boundary_conditions) {
        $this->conditions = $initial_conditions;
        $this->boundaries = $boundary_conditions;
        $this->iteration = 0;
    }

    public function update_conditions() {
        for ($i = 0; $i < count($this->conditions); $i++) {
            $this->conditions[$i] += mt_rand() / mt_getrandmax() * 0.1;
            $this->conditions[$i] = max($this->boundaries[0], min($this->conditions[$i], $this->boundaries[1]));
        }
    }

    public function check_stability() {
        foreach ($this->conditions as $condition) {
            if (abs($condition - $this->boundaries[0]) > 0.01 && abs($condition - $this->boundaries[1]) > 0.01) {
                return false;
            }
        }
        return true;
    }
}

class BoundaryConditions {
    public $limit1;
    public $limit2;

    public function __construct($lower, $upper) {
        $this->limit1 = $lower;
        $this->limit2 = $upper;
    }

    public function get_boundaries() {
        return array($this->limit1, $this->limit2);
    }
}

function simulate_state($initial, $boundaries, $max_iterations) {
    $simulator = new StateSimulator($initial, $boundaries);
    for ($i = 0; $i < $max_iterations; $i++) {
        $simulator->update_conditions();
        if ($simulator->check_stability()) {
            break;
        }
    }
    return $simulator->conditions;
}

function main() {
    $initial_conditions = array(0.5, 0.5, 0.5);
    $boundary_conditions = new BoundaryConditions(0, 1);
    $max_iterations = 100;
    $final_state = simulate_state($initial_conditions, $boundary_conditions->get_boundaries(), $max_iterations);
    print_r($final_state);
}

main();
?>