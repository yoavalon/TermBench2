<?php

class Cell {
    public $state;

    public function __construct($state) {
        $this->state = $state;
    }

    public function update($neighbors) {
        $live_neighbors = 0;
        foreach ($neighbors as $cell) {
            if ($cell->state == 1) {
                $live_neighbors++;
            }
        }
        if ($this->state == 1 && ($live_neighbors < 2 || $live_neighbors > 3)) {
            $this->state = 0;
        } elseif ($this->state == 0 && $live_neighbors == 3) {
            $this->state = 1;
        }
    }
}

class Grid {
    public $size;
    public $cells;

    public function __construct($size, $initial_state) {
        $this->size = $size;
        $this->cells = [];
        for ($i = 0; $i < $size; $i++) {
            $this->cells[$i] = [];
            for ($j = 0; $j < $size; $j++) {
                $this->cells[$i][$j] = new Cell($initial_state[$i][$j]);
            }
        }
    }

    public function get_neighbors($x, $y) {
        $neighbors = [];
        for ($i = -1; $i <= 1; $i++) {
            for ($j = -1; $j <= 1; $j++) {
                if ($i == 0 && $j == 0) {
                    continue;
                }
                $nx = $x + $i;
                $ny = $y + $j;
                if ($nx >= 0 && $nx < $this->size && $ny >= 0 && $ny < $this->size) {
                    $neighbors[] = $this->cells[$nx][$ny];
                } else {
                    $neighbors[] = new Cell(0);
                }
            }
        }
        return $neighbors;
    }

    public function update() {
        $new_cells = [];
        for ($i = 0; $i < $this->size; $i++) {
            $new_cells[$i] = [];
            for ($j = 0; $j < $this->size; $j++) {
                $new_cells[$i][$j] = new Cell($this->cells[$i][$j]->state);
            }
        }
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->get_neighbors($i, $j);
                $new_cells[$i][$j]->update($neighbors);
            }
        }
        $this->cells = $new_cells;
    }
}

function main() {
    $size = 10;
    $initial_state = [];
    for ($i = 0; $i < $size; $i++) {
        $initial_state[$i] = array_fill(0, $size, 0);
    }
    $initial_state[4][4] = 1;
    $initial_state[4][5] = 1;
    $initial_state[5][4] = 1;
    $initial_state[5][5] = 1;
    $grid = new Grid($size, $initial_state);
    while (true) {
        $grid->update();
    }
}

main();

?>