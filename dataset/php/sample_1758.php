<?php

class FluidSimulator {
    public $grid;
    public $size;

    public function __construct($grid_size) {
        $this->grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0));
        $this->size = $grid_size;
    }

    public function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($x = 0; $x < $this->size; $x++) {
            for ($y = 0; $y < $this->size; $y++) {
                $neighbors = $this->get_neighbors($x, $y);
                if ($this->grid[$x][$y] == 1) {
                    if (array_sum($neighbors) < 2 || array_sum($neighbors) > 3) {
                        $new_grid[$x][$y] = 0;
                    } else {
                        $new_grid[$x][$y] = 1;
                    }
                } elseif (array_sum($neighbors) == 3) {
                    $new_grid[$x][$y] = 1;
                }
            }
        }
        $this->grid = $new_grid;
    }

    public function get_neighbors($x, $y) {
        $neighbors = array();
        for ($dx = -1; $dx <= 1; $dx++) {
            for ($dy = -1; $dy <= 1; $dy++) {
                if ($dx == 0 && $dy == 0) {
                    continue;
                }
                $nx = $x + $dx;
                $ny = $y + $dy;
                if ($nx >= 0 && $nx < $this->size && $ny >= 0 && $ny < $this->size) {
                    $neighbors[] = $this->grid[$nx][$ny];
                }
            }
        }
        return $neighbors;
    }

    public function display() {
        foreach ($this->grid as $row) {
            echo implode('', array_map(function($cell) { return $cell == 1 ? '#' : ' '; }, $row)) . "\n";
        }
    }
}

function main() {
    $simulator = new FluidSimulator(10);
    $simulator->grid[4][4] = 1;
    $simulator->grid[5][4] = 1;
    $simulator->grid[4][5] = 1;
    $simulator->grid[5][5] = 1;
    while (true) {
        $simulator->display();
        $simulator->update();
    }
}

main();

?>