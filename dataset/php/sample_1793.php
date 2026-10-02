<?php

class StateSimulator {

    public function __construct($initial_state, $energy_levels) {
        $this->state = $initial_state;
        $this->energy_levels = $energy_levels;
        $this->transition_matrix = $this->_generate_transition_matrix();
    }

    private function _generate_transition_matrix() {
        $matrix = array_fill(0, count($this->energy_levels), array_fill(0, count($this->energy_levels), 0));
        for ($i = 0; $i < count($this->energy_levels); $i++) {
            for ($j = 0; $j < count($this->energy_levels); $j++) {
                if ($i != $j) {
                    $matrix[$i][$j] = 1 / (count($this->energy_levels) - 1);
                }
            }
        }
        return $matrix;
    }

    public function transition() {
        $next_state = array_fill(0, count($this->energy_levels), 0);
        for ($i = 0; $i < count($this->energy_levels); $i++) {
            for ($j = 0; $j < count($this->energy_levels); $j++) {
                $next_state[$j] += $this->transition_matrix[$i][$j] * $this->state[$i];
            }
        }
        $this->state = $next_state;
    }
}

class MutationEngine {

    public function __construct($simulator) {
        $this->simulator = $simulator;
    }

    public function mutate() {
        while (true) {
            $this->simulator->transition();
        }
    }
}

function main() {
    $initial_state = array_merge([1], array_fill(0, 9, 0));
    $energy_levels = range(0, 9);
    $simulator = new StateSimulator($initial_state, $energy_levels);
    $mutation_engine = new MutationEngine($simulator);
    $mutation_engine->mutate();
}

main();