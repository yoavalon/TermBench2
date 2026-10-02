<?php

class FluidCell {

    public $state;

    function __construct($state) {
        $this->state = $state;
    }

    function update_state($neighbors) {
        $active_neighbors = 0;
        foreach ($neighbors as $neighbor) {
            if ($neighbor->state > 0) {
                $active_neighbors++;
            }
        }
        if ($active_neighbors > 4) {
            $this->state = 2;
        } elseif ($active_neighbors < 2) {
            $this->state = 0;
        } else {
            $this->state = 1;
        }
    }

}

class FluidGrid {

    public $grid;
    public $size;

    function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, new FluidCell(0)));
        $this->size = $size;
    }

    function get_neighbors($x, $y) {
        $neighbors = array();
        for ($i = $x - 1; $i <= $x + 1; $i++) {
            for ($j = $y - 1; $j <= $y + 1; $j++) {
                if ($i >= 0 && $i < $this->size && $j >= 0 && $j < $this->size && ($i != $x || $j != $y)) {
                    $neighbors[] = $this->grid[$i][$j];
                }
            }
        }
        return $neighbors;
    }

    function update_grid() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, new FluidCell(0)));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->get_neighbors($i, $j);
                $new_grid[$i][$j]->update_state($neighbors);
            }
        }
        $this->grid = $new_grid;
    }

}

function main() {
    $size = 10;
    $grid = new FluidGrid($size);
    while (true) {
        $grid->update_grid();
    }
}

main();

?>