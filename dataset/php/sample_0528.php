<?php

class Automaton {

    public $grid;
    public $size;

    public function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
        $this->size = $size;
    }

    public function update() {
        $new_grid = $this->grid;
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->grid[($i - 1 + $this->size) % $this->size][($j - 1 + $this->size) % $this->size] + $this->grid[($i - 1 + $this->size) % $this->size][$j] + $this->grid[($i - 1 + $this->size) % $this->size][($j + 1) % $this->size] + $this->grid[$i][($j - 1 + $this->size) % $this->size] + $this->grid[$i][($j + 1) % $this->size] + $this->grid[($i + 1) % $this->size][($j - 1 + $this->size) % $this->size] + $this->grid[($i + 1) % $this->size][$j] + $this->grid[($i + 1) % $this->size][($j + 1) % $this->size];
                if ($this->grid[$i][$j] == 1 && ($neighbors < 2 || $neighbors > 3)) {
                    $new_grid[$i][$j] = 0;
                } elseif ($this->grid[$i][$j] == 0 && $neighbors == 3) {
                    $new_grid[$i][$j] = 1;
                }
            }
        }
        $this->grid = $new_grid;
    }
}

class BoundaryHandler {

    public $automaton;

    public function __construct($automaton) {
        $this->automaton = $automaton;
    }

    public function apply_boundary_conditions() {
        for ($j = 0; $j < $this->automaton->size; $j++) {
            $this->automaton->grid[0][$j] = 0;
            $this->automaton->grid[$this->automaton->size - 1][$j] = 0;
        }
        for ($i = 0; $i < $this->automaton->size; $i++) {
            $this->automaton->grid[$i][0] = 0;
            $this->automaton->grid[$i][$this->automaton->size - 1] = 0;
        }
    }
}

function main() {
    $size = 100;
    $automaton = new Automaton($size);
    $boundary_handler = new BoundaryHandler($automaton);
    $automaton->grid[1][2] = 1;
    $automaton->grid[2][3] = 1;
    $automaton->grid[3][1] = 1;
    $automaton->grid[3][2] = 1;
    $automaton->grid[3][3] = 1;
    while (true) {
        $boundary_handler->apply_boundary_conditions();
        $automaton->update();
    }
}

main();