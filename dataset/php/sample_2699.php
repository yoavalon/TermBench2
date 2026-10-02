<?php

class Automaton {

    function __construct($grid_size) {
        $this->grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0));
        $this->size = $grid_size;
    }

    function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->count_neighbors($i, $j);
                if ($this->grid[$i][$j] == 0 && $neighbors == 3) {
                    $new_grid[$i][$j] = 1;
                } elseif ($this->grid[$i][$j] == 1 && ($neighbors < 2 || $neighbors > 3)) {
                    $new_grid[$i][$j] = 0;
                } else {
                    $new_grid[$i][$j] = $this->grid[$i][$j];
                }
            }
        }
        $this->grid = $new_grid;
    }

    function count_neighbors($x, $y) {
        $count = 0;
        for ($i = max(0, $x - 1); $i < min($this->size, $x + 2); $i++) {
            for ($j = max(0, $y - 1); $j < min($this->size, $y + 2); $j++) {
                if (($i, $j) != ($x, $y) && $this->grid[$i][$j] == 1) {
                    $count++;
                }
            }
        }
        return $count;
    }
}

function simulate($automaton, $steps) {
    for ($i = 0; $i < $steps; $i++) {
        $automaton->update();
    }
}

function main() {
    $grid_size = 10;
    $steps = 50;
    $automaton = new Automaton($grid_size);
    simulate($automaton, $steps);
}

main();

?>