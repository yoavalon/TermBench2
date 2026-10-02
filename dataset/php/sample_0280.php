<?php

class Grid {

    function __construct($size) {
        $this->size = $size;
        $this->data = array_fill(0, $size, array_fill(0, $size, 0));
    }

    function update() {
        $new_data = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $new_data[$i][$j] = $this->_calculate_next_state($i, $j);
            }
        }
        $this->data = $new_data;
    }

    function _calculate_next_state($i, $j) {
        $neighbors = $this->_get_neighbors($i, $j);
        $alive_count = array_sum($neighbors);
        if ($this->data[$i][$j] == 1) {
            return $alive_count == 2 || $alive_count == 3 ? 1 : 0;
        } else {
            return $alive_count == 3 ? 1 : 0;
        }
    }

    function _get_neighbors($i, $j) {
        $neighbors = array();
        for ($x = max(0, $i - 1); $x < min($this->size, $i + 2); $x++) {
            for ($y = max(0, $j - 1); $y < min($this->size, $j + 2); $y++) {
                if (($x, $y) != ($i, $j)) {
                    $neighbors[] = $this->data[$x][$y];
                }
            }
        }
        return $neighbors;
    }
}

function main() {
    $grid_size = 10;
    $grid = new Grid($grid_size);
    $steps = 50;
    for ($i = 0; $i < $steps; $i++) {
        $grid->update();
    }
}

main();

?>