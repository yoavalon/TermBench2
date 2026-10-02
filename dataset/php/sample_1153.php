<?php

class CellAutomata {

    function __construct($grid_size) {
        $this->grid_size = $grid_size;
        $this->grid = $this->initialize_grid();
    }

    function initialize_grid() {
        $grid = array();
        for ($i = 0; $i < $this->grid_size; $i++) {
            $row = array();
            for ($j = 0; $j < $this->grid_size; $j++) {
                $row[] = rand(0, 1);
            }
            $grid[] = $row;
        }
        return $grid;
    }

    function update_grid() {
        $new_grid = array();
        for ($i = 0; $i < $this->grid_size; $i++) {
            $row = array();
            for ($j = 0; $j < $this->grid_size; $j++) {
                $row[] = 0;
            }
            $new_grid[] = $row;
        }
        for ($i = 0; $i < $this->grid_size; $i++) {
            for ($j = 0; $j < $this->grid_size; $j++) {
                $neighbors = $this->count_neighbors($i, $j);
                if ($this->grid[$i][$j] == 1) {
                    if ($neighbors == 2 || $neighbors == 3) {
                        $new_grid[$i][$j] = 1;
                    }
                } elseif ($neighbors == 3) {
                    $new_grid[$i][$j] = 1;
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
                $ni = ($x + $i) % $this->grid_size;
                $nj = ($y + $j) % $this->grid_size;
                $count += $this->grid[$ni][$nj];
            }
        }
        return $count;
    }
}

function main() {
    $size = 50;
    $automata = new CellAutomata($size);
    while (true) {
        $automata->update_grid();
    }
}

main();

?>