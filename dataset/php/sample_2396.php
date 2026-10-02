<?php

class FluidCell {
    public $value;

    public function __construct($value) {
        $this->value = $value;
    }

    public function update($neighbors) {
        $sum = 0.0;
        foreach ($neighbors as $n) {
            $sum += $n->value;
        }
        $this->value = $sum / count($neighbors);
    }
}

class FluidGrid {
    public $grid;

    public function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, new FluidCell(0.0)));
    }

    public function get_neighbors($x, $y) {
        $directions = array(array(-1, 0), array(1, 0), array(0, -1), array(0, 1));
        $neighbors = array();
        foreach ($directions as $d) {
            $nx = $x + $d[0];
            $ny = $y + $d[1];
            if ($nx >= 0 && $nx < count($this->grid) && $ny >= 0 && $ny < count($this->grid)) {
                $neighbors[] = $this->grid[$nx][$ny];
            }
        }
        return $neighbors;
    }

    public function update_cells() {
        $new_grid = array_fill(0, count($this->grid), array_fill(0, count($this->grid), new FluidCell(0.0)));
        for ($x = 0; $x < count($this->grid); $x++) {
            for ($y = 0; $y < count($this->grid); $y++) {
                $neighbors = $this->get_neighbors($x, $y);
                $new_grid[$x][$y]->update($neighbors);
            }
        }
        $this->grid = $new_grid;
    }
}

function main() {
    $size = 100;
    $fluid_grid = new FluidGrid($size);
    foreach ($fluid_grid->grid[0] as $cell) {
        $cell->value = 1.0;
    }
    while (true) {
        $fluid_grid->update_cells();
    }
}

main();