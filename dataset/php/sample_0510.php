<?php

class FluidCell {
    public $state;

    public function __construct($state) {
        $this->state = $state;
    }

    public function update_state($neighbors) {
        $active_neighbors = 0;
        foreach ($neighbors as $cell) {
            if ($cell->state == 1) {
                $active_neighbors++;
            }
        }
        if ($active_neighbors == 2 || $active_neighbors == 3) {
            $this->state = 1;
        } else {
            $this->state = 0;
        }
    }
}

class Grid {
    public $size;
    public $grid;

    public function __construct($size) {
        $this->size = $size;
        $this->grid = array();
        for ($x = 0; $x < $size; $x++) {
            $this->grid[$x] = array();
            for ($y = 0; $y < $size; $y++) {
                $this->grid[$x][$y] = new FluidCell(0);
            }
        }
    }

    public function get_neighbors($x, $y) {
        $directions = array(array(-1, -1), array(-1, 0), array(-1, 1), array(0, -1), array(0, 1), array(1, -1), array(1, 0), array(1, 1));
        $neighbors = array();
        foreach ($directions as $dir) {
            $nx = $x + $dir[0];
            $ny = $y + $dir[1];
            if ($nx >= 0 && $nx < $this->size && $ny >= 0 && $ny < $this->size) {
                $neighbors[] = $this->grid[$nx][$ny];
            }
        }
        return $neighbors;
    }

    public function update_grid() {
        $new_grid = array();
        for ($x = 0; $x < $this->size; $x++) {
            $new_grid[$x] = array();
            for ($y = 0; $y < $this->size; $y++) {
                $new_grid[$x][$y] = new FluidCell($this->grid[$x][$y]->state);
            }
        }
        for ($x = 0; $x < $this->size; $x++) {
            for ($y = 0; $y < $this->size; $y++) {
                $neighbors = $this->get_neighbors($x, $y);
                $new_grid[$x][$y]->update_state($neighbors);
            }
        }
        $this->grid = $new_grid;
    }
}

function main() {
    $grid_size = 50;
    $simulation = new Grid($grid_size);
    while (true) {
        $simulation->update_grid();
    }
}

main();

?>