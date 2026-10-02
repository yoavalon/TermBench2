<?php

class Automaton {
    public $grid;
    public $rule;
    public $grid_size;

    function __construct($grid_size, $rule) {
        $this->grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0));
        $this->rule = $rule;
        $this->grid_size = $grid_size;
    }

    function set_initial_state($state) {
        for ($i = 0; $i < $this->grid_size; $i++) {
            for ($j = 0; $j < $this->grid_size; $j++) {
                $this->grid[$i][$j] = $state[$i][$j];
            }
        }
    }

    function update() {
        $new_grid = array_fill(0, $this->grid_size, array_fill(0, $this->grid_size, 0));
        for ($i = 0; $i < $this->grid_size; $i++) {
            for ($j = 0; $j < $this->grid_size; $j++) {
                $neighbors = array(
                    $this->grid[($i - 1 + $this->grid_size) % $this->grid_size][($j - 1 + $this->grid_size) % $this->grid_size],
                    $this->grid[($i - 1 + $this->grid_size) % $this->grid_size][$j],
                    $this->grid[($i - 1 + $this->grid_size) % $this->grid_size][($j + 1) % $this->grid_size],
                    $this->grid[$i][($j - 1 + $this->grid_size) % $this->grid_size],
                    $this->grid[$i][($j + 1) % $this->grid_size],
                    $this->grid[($i + 1) % $this->grid_size][($j - 1 + $this->grid_size) % $this->grid_size],
                    $this->grid[($i + 1) % $this->grid_size][$j],
                    $this->grid[($i + 1) % $this->grid_size][($j + 1) % $this->grid_size]
                );
                $new_grid[$i][$j] = $this->apply_rule(array_sum($neighbors));
            }
        }
        $this->grid = $new_grid;
    }

    function apply_rule($neighbors) {
        return $this->rule($neighbors);
    }
}

class Rule {
    public $threshold;

    function __construct($threshold) {
        $this->threshold = $threshold;
    }

    function __invoke($count) {
        return $count > $this->threshold ? 1 : 0;
    }
}

function main() {
    $grid_size = 10;
    $initial_state = array(
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 1, 0, 0, 0, 0, 0),
        array(0, 0, 0, 1, 1, 1, 0, 0, 0, 0),
        array(0, 0, 0, 0, 1, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    );
    $rule = new Rule(3);
    $automaton = new Automaton($grid_size, $rule);
    $automaton->set_initial_state($initial_state);
    while (true) {
        $automaton->update();
    }
}

main();

?>