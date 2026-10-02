<?php

class FluidCell {
    public $state;

    public function __construct($state) {
        $this->state = $state;
    }

    public function update_state($neighbors) {
        $sum = 0;
        foreach ($neighbors as $n) {
            $sum += $n->state;
        }
        $this->state = $sum / count($neighbors);
    }
}

class FluidGrid {
    public $size;
    public $grid;

    public function __construct($size, $initial_state) {
        $this->size = $size;
        $this->grid = array_fill(0, $size, array_fill(0, $size, new FluidCell($initial_state)));
    }

    public function get_neighbors($x, $y) {
        $neighbors = array();
        for ($dx = -1; $dx <= 1; $dx++) {
            for ($dy = -1; $dy <= 1; $dy++) {
                $nx = $x + $dx;
                $ny = $y + $dy;
                if ($nx >= 0 && $nx < $this->size && $ny >= 0 && $ny < $this->size && ($dx != 0 || $dy != 0)) {
                    $neighbors[] = $this->grid[$nx][$ny];
                }
            }
        }
        return $neighbors;
    }

    public function update_grid() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, new FluidCell(0)));
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
    $size = 10;
    $initial_state = 1.0;
    $grid = new FluidGrid($size, $initial_state);
    while (true) {
        $grid->update_grid();
    }
}

main();

?>