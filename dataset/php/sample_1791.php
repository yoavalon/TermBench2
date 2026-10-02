<?php

class Cell {
    public $state;

    public function __construct($state = 0) {
        $this->state = $state;
    }

    public function update($neighbors) {
        $live_neighbors = 0;
        foreach ($neighbors as $cell) {
            if ($cell->state == 1) {
                $live_neighbors++;
            }
        }
        if ($this->state == 1) {
            $this->state = ($live_neighbors == 2 || $live_neighbors == 3) ? 1 : 0;
        } else {
            $this->state = ($live_neighbors == 3) ? 1 : 0;
        }
    }
}

class Grid {
    public $width;
    public $height;
    public $grid;

    public function __construct($width, $height, $initial_state = null) {
        $this->width = $width;
        $this->height = $height;
        $this->grid = [];
        for ($i = 0; $i < $height; $i++) {
            $this->grid[$i] = [];
            for ($j = 0; $j < $width; $j++) {
                $this->grid[$i][$j] = $initial_state ? new Cell($initial_state[$i][$j]) : new Cell();
            }
        }
    }

    public function get_neighbors($x, $y) {
        $directions = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]];
        $neighbors = [];
        foreach ($directions as $dir) {
            $dx = $dir[0];
            $dy = $dir[1];
            $nx = $x + $dx;
            $ny = $y + $dy;
            if ($nx >= 0 && $nx < $this->width && $ny >= 0 && $ny < $this->height) {
                $neighbors[] = $this->grid[$ny][$nx];
            }
        }
        return $neighbors;
    }

    public function update() {
        $new_grid = [];
        for ($i = 0; $i < $this->height; $i++) {
            $new_grid[$i] = [];
            for ($j = 0; $j < $this->width; $j++) {
                $new_grid[$i][$j] = new Cell($this->grid[$i][$j]->state);
            }
        }
        for ($i = 0; $i < $this->height; $i++) {
            for ($j = 0; $j < $this->width; $j++) {
                $neighbors = $this->get_neighbors($j, $i);
                $new_grid[$i][$j]->update($neighbors);
            }
        }
        $this->grid = $new_grid;
    }
}

function main() {
    $initial_state = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    $grid = new Grid(3, 3, $initial_state);
    while (true) {
        $grid->update();
    }
}

main();

?>