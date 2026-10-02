<?php

class FluidCell {
    public $state;

    public function __construct($state = 0) {
        $this->state = $state;
    }

    public function update($neighbors) {
        $new_state = array_sum(array_map(function($n) { return $n->state; }, $neighbors)) / count($neighbors);
        $this->state = $new_state;
    }
}

class Grid {
    public $width;
    public $height;
    public $grid;

    public function __construct($width, $height, $initial_state = 0) {
        $this->width = $width;
        $this->height = $height;
        $this->grid = array_fill(0, $height, array_fill(0, $width, new FluidCell($initial_state)));
    }

    public function get_neighbors($x, $y) {
        $directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
        $neighbors = [];
        foreach ($directions as $dir) {
            $nx = $x + $dir[0];
            $ny = $y + $dir[1];
            if ($nx >= 0 && $nx < $this->width && $ny >= 0 && $ny < $this->height) {
                $neighbors[] = $this->grid[$ny][$nx];
            }
        }
        return $neighbors;
    }

    public function update_cells() {
        for ($y = 0; $y < $this->height; $y++) {
            for ($x = 0; $x < $this->width; $x++) {
                $neighbors = $this->get_neighbors($x, $y);
                $this->grid[$y][$x]->update($neighbors);
            }
        }
    }
}

class Simulation {
    public $grid;

    public function __construct($grid) {
        $this->grid = $grid;
    }

    public function run() {
        while (true) {
            $this->grid->update_cells();
        }
    }
}

function main() {
    $grid = new Grid(10, 10, 50);
    $simulation = new Simulation($grid);
    $simulation->run();
}

main();

?>