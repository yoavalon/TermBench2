<?php

class Grid {
    public $grid;
    public $size;

    function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
        $this->size = $size;
    }

    function update() {
        $new_grid = $this->grid;
        for ($i = 1; $i < $this->size - 1; $i++) {
            for ($j = 1; $j < $this->size - 1; $j++) {
                $neighbors = [];
                for ($ii = $i - 1; $ii <= $i + 1; $ii++) {
                    for ($jj = $j - 1; $jj <= $j + 1; $jj++) {
                        $neighbors[] = $this->grid[$ii][$jj];
                    }
                }
                $new_grid[$i][$j] = $this->rules($neighbors);
            }
        }
        $this->grid = $new_grid;
    }

    function rules($neighbors) {
        $count = array_sum($neighbors) - $this->grid[1][1];
        if ($this->grid[1][1] == 1 && ($count < 2 || $count > 3)) {
            return 0;
        } elseif ($this->grid[1][1] == 0 && $count == 3) {
            return 1;
        }
        return $this->grid[1][1];
    }
}

class BoundaryHandler {
    function apply($grid) {
        for ($j = 0; $j < $grid->size; $j++) {
            $grid->grid[0][$j] = $grid->grid[$grid->size - 2][$j];
            $grid->grid[$grid->size - 1][$j] = $grid->grid[1][$j];
        }
        for ($i = 0; $i < $grid->size; $i++) {
            $grid->grid[$i][0] = $grid->grid[$i][$grid->size - 2];
            $grid->grid[$i][$grid->size - 1] = $grid->grid[$i][1];
        }
    }
}

class Simulator {
    public $grid;
    public $boundary_handler;
    public $iterations;

    function __construct($grid, $boundary_handler, $iterations) {
        $this->grid = $grid;
        $this->boundary_handler = $boundary_handler;
        $this->iterations = $iterations;
    }

    function run() {
        for ($i = 0; $i < $this->iterations; $i++) {
            $this->grid->update();
            $this->boundary_handler->apply($this->grid);
        }
    }
}

function main() {
    $size = 10;
    $iterations = 50;
    $grid = new Grid($size);
    $boundary_handler = new BoundaryHandler();
    $simulator = new Simulator($grid, $boundary_handler, $iterations);
    $simulator->run();
    print_r($grid->grid);
}

main();

?>