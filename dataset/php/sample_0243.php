<?php

class Automata {
    public $grid;
    public $boundary_type;
    public $size;

    public function __construct($size, $boundary_type) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
        $this->boundary_type = $boundary_type;
        $this->size = $size;
    }

    public function apply_boundary_conditions() {
        if ($this->boundary_type == 'fixed') {
            for ($i = 0; $i < $this->size; $i++) {
                $this->grid[$i][0] = 1;
                $this->grid[$i][$this->size - 1] = 1;
            }
            for ($j = 0; $j < $this->size; $j++) {
                $this->grid[0][$j] = 1;
                $this->grid[$this->size - 1][$j] = 1;
            }
        } elseif ($this->boundary_type == 'periodic') {
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

    public function update_grid() {
        $new_grid = $this->grid;
        for ($i = 1; $i < $this->size - 1; $i++) {
            for ($j = 1; $j < $this->size - 1; $j++) {
                $neighbors = 0;
                for ($ni = $i - 1; $ni <= $i + 1; $ni++) {
                    for ($nj = $j - 1; $nj <= $j + 1; $nj++) {
                        $neighbors += $this->grid[$ni][$nj];
                    }
                }
                $neighbors -= $this->grid[$i][$j];
                if ($this->grid[$i][$j] == 1) {
                    if ($neighbors < 2 || $neighbors > 3) {
                        $new_grid[$i][$j] = 0;
                    }
                } elseif ($neighbors == 3) {
                    $new_grid[$i][$j] = 1;
                }
            }
        }
        $this->grid = $new_grid;
    }
}

class Simulation {
    public $automata;
    public $steps;

    public function __construct($automata, $steps) {
        $this->automata = $automata;
        $this->steps = $steps;
    }

    public function run() {
        for ($step = 0; $step < $this->steps; $step++) {
            $this->automata->apply_boundary_conditions();
            $this->automata->update_grid();
        }
    }
}

function main() {
    $size = 10;
    $boundary_type = 'fixed';
    $steps = 50;
    $automata = new Automata($size, $boundary_type);
    $simulation = new Simulation($automata, $steps);
    $simulation->run();
}

main();

?>