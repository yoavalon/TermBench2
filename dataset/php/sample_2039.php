<?php

class CellularAutomaton {
    public $grid;

    public function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, rand(0, 1)));
    }

    public function update() {
        $new_grid = $this->grid;
        for ($i = 0; $i < count($this->grid); $i++) {
            for ($j = 0; $j < count($this->grid[$i]); $j++) {
                $neighbors = 0;
                for ($x = -1; $x <= 1; $x++) {
                    for ($y = -1; $y <= 1; $y++) {
                        $neighbors += $this->grid[($i + $x + count($this->grid)) % count($this->grid)][($j + $y + count($this->grid[$i])) % count($this->grid[$i])];
                    }
                }
                $new_grid[$i][$j] = ($neighbors == 3 || ($this->grid[$i][$j] == 1 && $neighbors == 2)) ? 1 : 0;
            }
        }
        $this->grid = $new_grid;
    }

    public function get_state() {
        return $this->grid;
    }
}

class FluidSimulator {
    public $size;
    public $steps;
    public $ca;

    public function __construct($size, $steps) {
        $this->size = $size;
        $this->steps = $steps;
        $this->ca = new CellularAutomaton($size);
    }

    public function simulate() {
        for ($i = 0; $i < $this->steps; $i++) {
            $this->ca->update();
        }
    }

    public function get_result() {
        return $this->ca->get_state();
    }
}

function main() {
    $size = 100;
    $steps = 1000;
    $simulator = new FluidSimulator($size, $steps);
    $simulator->simulate();
    $result = $simulator->get_result();
    print_r($result);
}

main();