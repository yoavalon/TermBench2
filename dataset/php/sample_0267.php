<?php

class Grid {

    public function __construct($size, $boundary) {
        $this->size = $size;
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
        $this->boundary = $boundary;
    }

    public function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->boundary_condition($i, $j);
                $new_grid[$i][$j] = $this->apply_rules($neighbors, $this->grid[$i][$j]);
            }
        }
        $this->grid = $new_grid;
    }

    public function boundary_condition($x, $y) {
        $neighbors = array();
        for ($dx = -1; $dx <= 1; $dx++) {
            for ($dy = -1; $dy <= 1; $dy++) {
                if ($dx == 0 && $dy == 0) {
                    continue;
                }
                $nx = $x + $dx;
                $ny = $y + $dy;
                if ($this->boundary == 'fixed') {
                    if ($nx >= 0 && $nx < $this->size && $ny >= 0 && $ny < $this->size) {
                        $neighbors[] = $this->grid[$nx][$ny];
                    }
                } elseif ($this->boundary == 'periodic') {
                    $neighbors[] = $this->grid[($nx + $this->size) % $this->size][($ny + $this->size) % $this->size];
                }
            }
        }
        return $neighbors;
    }

    public function apply_rules($neighbors, $current) {
        $count = array_sum($neighbors);
        if ($current == 1) {
            if ($count < 2 || $count > 3) {
                return 0;
            }
            return 1;
        } else {
            if ($count == 3) {
                return 1;
            }
            return 0;
        }
    }
}

function main() {
    $size = 10;
    $boundary = 'periodic';
    $grid = new Grid($size, $boundary);
    $steps = 50;
    for ($i = 0; $i < $steps; $i++) {
        $grid->update();
    }
}

main();

?>