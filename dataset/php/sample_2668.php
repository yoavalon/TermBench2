<?php

class CellularAutomata {
    public $size;
    public $rule;
    public $state;

    public function __construct($size, $rule) {
        $this->size = $size;
        $this->rule = $rule;
        $this->state = array_fill(0, $size, 0);
        $this->state[intdiv($size, 2)] = 1;
    }

    public function apply_rule($left, $center, $right) {
        $index = 4 * $left + 2 * $center + $right;
        return ($this->rule >> $index) & 1;
    }

    public function next_generation() {
        $new_state = array_fill(0, $this->size, 0);
        for ($i = 0; $i < $this->size; $i++) {
            $left = $this->state[($i - 1 + $this->size) % $this->size];
            $center = $this->state[$i];
            $right = $this->state[($i + 1) % $this->size];
            $new_state[$i] = $this->apply_rule($left, $center, $right);
        }
        $this->state = $new_state;
    }

    public function run($steps) {
        $results = array();
        for ($i = 0; $i < $steps; $i++) {
            $results[] = $this->state;
            $this->next_generation();
        }
        return $results;
    }
}

function generate_sequence($size, $rule, $steps) {
    $ca = new CellularAutomata($size, $rule);
    return $ca->run($steps);
}

function display_sequence($sequence) {
    foreach ($sequence as $row) {
        echo implode('', array_map(function($cell) { return $cell ? '1' : '0'; }, $row)) . "\n";
    }
}

function main() {
    $size = 31;
    $rule = 30;
    $steps = 10;
    $sequence = generate_sequence($size, $rule, $steps);
    display_sequence($sequence);
}

main();

?>