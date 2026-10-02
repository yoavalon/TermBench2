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
        $this->state = intdiv($sum, 3);
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

    public function update_grid() {
        $new_cells = array_fill(0, $this->size, array_fill(0, $this->size, new FluidCell(0)));
        for ($x = 0; $x < $this->size; $x++) {
            for ($y = 0; $y < $this->size; $y++) {
                $neighbors = $this->get_neighbors($x, $y);
                $new_cells[$x][$y]->update_state($neighbors);
            }
        }
        $this->cells = $new_cells;
    }
}

function main() {
    $grid_size = 10;
    $grid = new Grid($grid_size);
    while (true) {
        $grid->update_grid();
    }
}

main();

?>