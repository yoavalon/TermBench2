<?php

class CellularAutomaton {
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
                $neighbors = $this->_count_neighbors($i, $j);
                if ($this->grid[$i][$j] == 0) {
                    if ($neighbors == 3) {
                        $new_grid[$i][$j] = 1;
                    }
                } elseif ($neighbors < 2 || $neighbors > 3) {
                    $new_grid[$i][$j] = 0;
                } else {
                    $new_grid[$i][$j] = 1;
                }
            }
        }
        $this->grid = $new_grid;
    }

    function _count_neighbors($x, $y) {
        $count = 0;
        for ($i = max(0, $x - 1); $i < min($x + 2, $this->size); $i++) {
            for ($j = max(0, $y - 1); $j < min($y + 2, $this->size); $j++) {
                if (($i, $j) != ($x, $y)) {
                    $count += $this->grid[$i][$j];
                }
            }
        }
        return $count;
    }
}

function display($grid) {
    foreach ($grid as $row) {
        echo implode('', array_map(function($cell) { return $cell ? '█' : ' '; }, $row)) . "\n";
    }
}

function main() {
    $size = 10;
    $automaton = new CellularAutomaton($size);
    while (true) {
        display($automaton->grid);
        $automaton->update();
    }
}

main();