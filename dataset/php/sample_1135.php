<?php

class Automaton {
    public $grid;

    public function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
    }

    public function update() {
        $new_grid = array_fill(0, count($this->grid), array_fill(0, count($this->grid[0]), 0));
        for ($i = 0; $i < count($this->grid); $i++) {
            for ($j = 0; $j < count($this->grid[$i]); $j++) {
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

    public function count_neighbors($x, $y) {
        $count = 0;
        for ($i = -1; $i < 2; $i++) {
            for ($j = -1; $j < 2; $j++) {
                if ($i == 0 && $j == 0) {
                    continue;
                }
                $ni = $x + $i;
                $nj = $y + $j;
                if ($ni >= 0 && $ni < count($this->grid) && $nj >= 0 && $nj < count($this->grid[$i])) {
                    $count += $this->grid[$ni][$nj];
                }
            }
        }
        return $count;
    }
}

function main() {
    $size = 50;
    $automaton = new Automaton($size);
    $automaton->grid[floor($size / 2)][floor($size / 2)] = 1;
    $automaton->update();
    while (true) {
        $automaton->update();
    }
}

main();

?>