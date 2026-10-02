<?php

class FluidCell {
    public $state;

    function __construct($state) {
        $this->state = $state;
    }

    function update($neighbors) {
        $avg_state = 0;
        foreach ($neighbors as $n) {
            $avg_state += $n->state;
        }
        $avg_state /= count($neighbors);
        $this->state = $avg_state;
    }
}

class Grid {
    public $size;
    public $cells;

    function __construct($size, $initial_state) {
        $this->size = $size;
        $this->cells = array();
        for ($x = 0; $x < $size; $x++) {
            $this->cells[$x] = array();
            for ($y = 0; $y < $size; $y++) {
                $this->cells[$x][$y] = new FluidCell($initial_state);
            }
        }
    }

    function get_neighbors($x, $y) {
        $neighbors = array();
        for ($dx = -1; $dx <= 1; $dx++) {
            for ($dy = -1; $dy <= 1; $dy++) {
                if ($dx == 0 && $dy == 0) {
                    continue;
                }
                $nx = $x + $dx;
                $ny = $y + $dy;
                if ($nx >= 0 && $nx < $this->size && $ny >= 0 && $ny < $this->size) {
                    $neighbors[] = $this->cells[$nx][$ny];
                }
            }
        }
        return $neighbors;
    }

    function update() {
        $new_cells = array();
        for ($x = 0; $x < $this->size; $x++) {
            $new_cells[$x] = array();
            for ($y = 0; $y < $this->size; $y++) {
                $new_cells[$x][$y] = new FluidCell($this->cells[$x][$y]->state);
            }
        }
        for ($x = 0; $x < $this->size; $x++) {
            for ($y = 0; $y < $this->size; $y++) {
                $neighbors = $this->get_neighbors($x, $y);
                $new_cells[$x][$y]->update($neighbors);
            }
        }
        $this->cells = $new_cells;
    }
}

function main() {
    $grid_size = 10;
    $initial_state = 0.5;
    $grid = new Grid($grid_size, $initial_state);
    while (true) {
        $grid->update();
    }
}

main();

?>