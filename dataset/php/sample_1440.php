<?php

class Grid {
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
                $neighbors = $this->count_neighbors($i, $j);
                if ($this->grid[$i][$j] == 1 && ($neighbors < 2 || $neighbors > 3)) {
                    $new_grid[$i][$j] = 0;
                } elseif ($this->grid[$i][$j] == 0 && $neighbors == 3) {
                    $new_grid[$i][$j] = 1;
                } else {
                    $new_grid[$i][$j] = $this->grid[$i][$j];
                }
            }
        }
        $this->grid = $new_grid;
    }

    function count_neighbors($x, $y) {
        $count = 0;
        for ($i = $x - 1; $i <= $x + 1; $i++) {
            for ($j = $y - 1; $j <= $y + 1; $j++) {
                if (($i != $x || $j != $y) && $i >= 0 && $i < $this->size && $j >= 0 && $j < $this->size) {
                    $count += $this->grid[$i][$j];
                }
            }
        }
        return $count;
    }
}

class Simulation {
    public $grid;
    public $steps;

    function __construct($grid) {
        $this->grid = $grid;
        $this->steps = 0;
    }

    function run($max_steps) {
        while ($this->steps < $max_steps) {
            $this->grid->update();
            $this->steps++;
        }
    }
}

function main() {
    $size = 50;
    $max_steps = 100;
    $grid = new Grid($size);
    $simulation = new Simulation($grid);
    $simulation->run($max_steps);
}

main();

?>