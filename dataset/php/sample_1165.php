php
<?php

class FluidGrid {
    public $grid;
    public $size;

    function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
        $this->size = $size;
    }

    function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $new_grid[$i][$j] = $this->calculate_next_state($i, $j);
            }
        }
        $this->grid = $new_grid;
    }

    function calculate_next_state($x, $y) {
        $neighbors = $this->get_neighbors($x, $y);
        $count = array_sum($neighbors);
        if ($this->grid[$x][$y] == 0) {
            return $count > 2 ? 1 : 0;
        } else {
            return in_array($count, [2, 3]) ? 1 : 0;
        }
    }

    function get_neighbors($x, $y) {
        $directions = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]];
        $neighbors = [];
        foreach ($directions as $dir) {
            list($dx, $dy) = $dir;
            $nx = $x + $dx;
            $ny = $y + $dy;
            if ($nx >= 0 && $nx < $this->size && $ny >= 0 && $ny < $this->size) {
                $neighbors[] = $this->grid[$nx][$ny];
            } else {
                $neighbors[] = 0;
            }
        }
        return $neighbors;
    }
}

function main() {
    $size = 10;
    $grid = new FluidGrid($size);
    while (true) {
        $grid->update();
    }
}

main();

?>