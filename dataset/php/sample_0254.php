<?php

class FluidCell {
    public $state;

    public function __construct($state) {
        $this->state = $state;
    }

    public function update($neighbors) {
        $sum = 0;
        foreach ($neighbors as $n) {
            $sum += $n->state;
        }
        $this->state = intdiv($sum, count($neighbors));
    }
}

class Grid {
    public $size;
    public $cells;

    public function __construct($size) {
        $this->size = $size;
        $this->cells = array_fill(0, $size, array_fill(0, $size, new FluidCell(0)));
    }

    public function get_neighbors($x, $y) {
        $directions = array(array(-1, 0), array(1, 0), array(0, -1), array(0, 1));
        $neighbors = array();
        foreach ($directions as $dir) {
            $dx = $dir[0];
            $dy = $dir[1];
            $nx = $x + $dx;
            $ny = $y + $dy;
            if ($nx >= 0 && $nx < $this->size && $ny >= 0 && $ny < $this->size) {
                $neighbors[] = $this->cells[$nx][$ny];
            }
        }
        return $neighbors;
    }

    public function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, new FluidCell(0)));
        for ($x = 0; $x < $this->size; $x++) {
            for ($y = 0; $y < $this->size; $y++) {
                $neighbors = $this->get_neighbors($x, $y);
                $new_grid[$x][$y]->update($neighbors);
            }
        }
        $this->cells = $new_grid;
    }
}

class Simulation {
    public $grid;
    public $steps;

    public function __construct($grid_size, $steps) {
        $this->grid = new Grid($grid_size);
        $this->steps = $steps;
    }

    public function run() {
        for ($i = 0; $i < $this->steps; $i++) {
            $this->grid->update();
        }
    }
}

function main() {
    $simulation = new Simulation(10, 50);
    $simulation->run();
}

main();

?>