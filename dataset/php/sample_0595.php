<?php

class Grid {

    public $size;
    public $grid;

    function __construct($size) {
        $this->size = $size;
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
    }

    function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->count_neighbors($i, $j);
                if ($this->grid[$i][$j] == 1) {
                    $new_grid[$i][$j] = ($neighbors == 2 || $neighbors == 3) ? 1 : 0;
                } else {
                    $new_grid[$i][$j] = ($neighbors == 3) ? 1 : 0;
                }
            }
        }
        $this->grid = $new_grid;
    }

    function count_neighbors($x, $y) {
        $count = 0;
        for ($i = max(0, $x - 1); $i < min($this->size, $x + 2); $i++) {
            for ($j = max(0, $y - 1); $j < min($this->size, $y + 2); $j++) {
                if (($i, $j) != ($x, $y)) {
                    $count += $this->grid[$i][$j];
                }
            }
        }
        return $count;
    }
}

class Simulation {

    public $grid;

    function __construct($grid_size) {
        $this->grid = new Grid($grid_size);
        $this->populate_grid();
    }

    function populate_grid() {
        for ($i = 0; $i < $this->grid->size; $i++) {
            for ($j = 0; $j < $this->grid->size; $j++) {
                $this->grid->grid[$i][$j] = mt_rand(0, 1);
            }
        }
    }

    function run() {
        while (true) {
            $this->grid->update();
        }
    }
}

function main() {
    $sim = new Simulation(10);
    $sim->run();
}

main();

?>