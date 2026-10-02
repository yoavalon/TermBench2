<?php

class FluidSimulator {
    public $grid;
    public $steps;
    public $step_count;

    function __construct($grid_size, $steps) {
        $this->grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0));
        $this->steps = $steps;
        $this->step_count = 0;
    }

    function update() {
        $new_grid = array_fill(0, count($this->grid), array_fill(0, count($this->grid[0]), 0));
        for ($i = 0; $i < count($this->grid); $i++) {
            for ($j = 0; $j < count($this->grid[$i]); $j++) {
                $neighbors = $this->count_neighbors($i, $j);
                if ($this->grid[$i][$j] == 1 && ($neighbors < 2 || $neighbors > 3)) {
                    $new_grid[$i][$j] = 0;
                } elseif ($this->grid[$i][$j] == 0 && $neighbors == 3) {
                    $new_grid[$i][$j] = 1;
                } else {
                    $new_grid[$i][$j] = $this->grid[$i][$j];
                }
            }
        }
        $this->grid = $new_grid;
        $this->step_count += 1;
    }

    function count_neighbors($x, $y) {
        $count = 0;
        for ($i = $x - 1; $i <= $x + 1; $i++) {
            for ($j = $y - 1; $j <= $y + 1; $j++) {
                if (($i != $x || $j != $y) && $i >= 0 && $i < count($this->grid) && $j >= 0 && $j < count($this->grid[$i])) {
                    $count += $this->grid[$i][$j];
                }
            }
        }
        return $count;
    }

    function run() {
        if ($this->step_count < $this->steps) {
            $this->update();
            $this->run();
        }
    }
}

function main() {
    $sim = new FluidSimulator(10, 100);
    $sim->run();
    foreach ($sim->grid as $row) {
        print_r($row);
    }
}

main();