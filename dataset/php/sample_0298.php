<?php

class AutomataGrid {
    public $grid;
    public $size;

    function __construct($size, $density) {
        $this->size = $size;
        $this->grid = $this->generateGrid($size, $density);
    }

    function generateGrid($size, $density) {
        $grid = array();
        for ($i = 0; $i < $size; $i++) {
            $row = array();
            for ($j = 0; $j < $size; $j++) {
                $row[] = rand(0, 1) < $density ? 1 : 0;
            }
            $grid[] = $row;
        }
        return $grid;
    }

    function apply_rules() {
        $new_grid = array();
        for ($i = 0; $i < $this->size; $i++) {
            $new_row = array();
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->countNeighbors($i, $j);
                if ($this->grid[$i][$j] == 1 && ($neighbors < 2 || $neighbors > 3)) {
                    $new_row[] = 0;
                } elseif ($this->grid[$i][$j] == 0 && $neighbors == 3) {
                    $new_row[] = 1;
                } else {
                    $new_row[] = $this->grid[$i][$j];
                }
            }
            $new_grid[] = $new_row;
        }
        $this->grid = $new_grid;
    }

    function countNeighbors($i, $j) {
        $sum = 0;
        for ($x = -1; $x <= 1; $x++) {
            for ($y = -1; $y <= 1; $y++) {
                if ($x == 0 && $y == 0) continue;
                $sum += $this->grid[($i + $x + $this->size) % $this->size][($j + $y + $this->size) % $this->size];
            }
        }
        return $sum;
    }

    function set_boundary_conditions() {
        for ($i = 0; $i < $this->size; $i++) {
            $this->grid[$i][0] = $this->grid[$i][$this->size - 2];
            $this->grid[$i][$this->size - 1] = $this->grid[$i][1];
        }
        for ($j = 0; $j < $this->size; $j++) {
            $this->grid[0][$j] = $this->grid[$this->size - 2][$j];
            $this->grid[$this->size - 1][$j] = $this->grid[1][$j];
        }
    }
}

class Simulation {
    public $grid;
    public $steps;

    function __construct($grid, $steps) {
        $this->grid = $grid;
        $this->steps = $steps;
    }

    function run() {
        for ($step = 0; $step < $this->steps; $step++) {
            $this->grid->apply_rules();
            $this->grid->set_boundary_conditions();
        }
    }
}

function main() {
    $size = 10;
    $density = 0.3;
    $steps = 50;
    $grid = new AutomataGrid($size, $density);
    $simulation = new Simulation($grid, $steps);
    $simulation->run();
}

main();

?>