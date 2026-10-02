<?php

class FluidCell {
    public $state;

    function __construct($state = 0) {
        $this->state = $state;
    }

    function update_state($neighbors) {
        $count = 0;
        foreach ($neighbors as $cell) {
            if ($cell->state == 1) {
                $count++;
            }
        }
        if ($count == 3) {
            $this->state = 1;
        } elseif ($count < 2 || $count > 3) {
            $this->state = 0;
        }
    }
}

class Grid {
    public $size;
    public $grid;

    function __construct($size, $initial_state = null) {
        $this->size = $size;
        if ($initial_state === null) {
            $initial_state = array_fill(0, $size, array_fill(0, $size, 0));
        }
        $this->grid = array();
        for ($i = 0; $i < $size; $i++) {
            for ($j = 0; $j < $size; $j++) {
                $this->grid[$i][$j] = new FluidCell($initial_state[$i][$j]);
            }
        }
    }

    function get_neighbors($x, $y) {
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

    function update_grid() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->get_neighbors($i, $j);
                $this->grid[$i][$j]->update_state($neighbors);
                $new_grid[$i][$j] = $this->grid[$i][$j]->state;
            }
        }
        $this->grid = array();
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $this->grid[$i][$j] = new FluidCell($new_grid[$i][$j]);
            }
        }
    }
}

function main() {
    $size = 10;
    $initial_state = array(
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 1, 1, 0, 0, 0, 0, 0, 0),
        array(0, 0, 1, 1, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    );
    $grid = new Grid($size, $initial_state);
    while (true) {
        $grid->update_grid();
    }
}

main();
?>