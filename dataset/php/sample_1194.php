<?php

class Automaton {

    function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
        $this->size = $size;
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
        for ($i = -1; $i < 2; $i++) {
            for ($j = -1; $j < 2; $j++) {
                if ($i == 0 && $j == 0) {
                    continue;
                }
                $nx = $x + $i;
                $ny = $y + $j;
                if ($nx >= 0 && $nx < $this->size && $ny >= 0 && $ny < $this->size) {
                    $count += $this->grid[$nx][$ny];
                }
            }
        }
        return $count;
    }
}

function run_simulation($size) {
    $automaton = new Automaton($size);
    $automaton->grid[1][1] = 1;
    $automaton->grid[1][2] = 1;
    $automaton->grid[2][1] = 1;
    $automaton->grid[2][2] = 1;
    while (true) {
        $automaton->update();
    }
}

function main() {
    run_simulation(5);
}

main();