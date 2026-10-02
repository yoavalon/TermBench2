<?php

class FluidSimulator {
    public $grid;
    public $size;

    public function __construct($grid_size) {
        $this->grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0));
        $this->size = $grid_size;
    }

    public function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $new_grid[$i][$j] = $this->apply_rules($i, $j);
            }
        }
        $this->grid = $new_grid;
    }

    public function apply_rules($x, $y) {
        $neighbors = $this->get_neighbors($x, $y);
        $count = array_sum($neighbors);
        if ($this->grid[$x][$y] == 1) {
            return $count > 1 ? 1 : 0;
        } else {
            return $count == 3 ? 1 : 0;
        }
    }

    public function get_neighbors($x, $y) {
        $directions = array(array(-1, -1), array(-1, 0), array(-1, 1), array(0, -1), array(0, 1), array(1, -1), array(1, 0), array(1, 1));
        $neighbors = array();
        foreach ($directions as $dir) {
            list($dx, $dy) = $dir;
            $nx = ($x + $dx) % $this->size;
            $ny = ($y + $dy) % $this->size;
            $neighbors[] = $this->grid[$nx][$ny];
        }
        return $neighbors;
    }
}

class BoundaryConditionApplier {
    public $simulator;

    public function __construct($simulator) {
        $this->simulator = $simulator;
    }

    public function apply() {
        for ($i = 0; $i < $this->simulator->size; $i++) {
            $this->simulator->grid[$i][0] = 1;
            $this->simulator->grid[$i][$this->simulator->size - 1] = 1;
            $this->simulator->grid[0][$i] = 1;
            $this->simulator->grid[$this->simulator->size - 1][$i] = 1;
        }
    }
}

function main() {
    $grid_size = 10;
    $simulator = new FluidSimulator($grid_size);
    $boundary_conditions = new BoundaryConditionApplier($simulator);
    while (true) {
        $boundary_conditions->apply();
        $simulator->update();
    }
}

main();
?>