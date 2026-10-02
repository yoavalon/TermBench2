<?php

class Grid {
    public $grid;
    public $size;

    function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
        $this->size = $size;
    }

    function update($rule) {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->get_neighbors($i, $j);
                $new_grid[$i][$j] = $rule($this->grid[$i][$j], $neighbors);
            }
        }
        $this->grid = $new_grid;
    }

    function get_neighbors($x, $y) {
        $directions = array(array(-1, -1), array(-1, 0), array(-1, 1), array(0, -1), array(0, 1), array(1, -1), array(1, 0), array(1, 1));
        $neighbors = array();
        foreach ($directions as $dir) {
            $dx = $dir[0];
            $dy = $dir[1];
            $nx = $x + $dx;
            $ny = $y + $dy;
            if ($nx >= 0 && $nx < $this->size && $ny >= 0 && $ny < $this->size) {
                $neighbors[] = $this->grid[$nx][$ny];
            }
        }
        return $neighbors;
    }
}

class Automaton {
    public $grid;

    function __construct($grid) {
        $this->grid = $grid;
    }

    function run($rule, $steps) {
        for ($i = 0; $i < $steps; $i++) {
            $this->grid->update($rule);
        }
    }
}

function simple_rule($center, $neighbors) {
    $live_neighbors = array_sum($neighbors);
    if ($center == 1) {
        return ($live_neighbors == 2 || $live_neighbors == 3) ? 1 : 0;
    } else {
        return ($live_neighbors == 3) ? 1 : 0;
    }
}

function main() {
    $grid_size = 10;
    $initial_grid = new Grid($grid_size);
    $initial_grid->grid[4][4] = 1;
    $initial_grid->grid[5][5] = 1;
    $initial_grid->grid[6][4] = 1;
    $initial_grid->grid[5][3] = 1;
    $initial_grid->grid[4][5] = 1;
    $automaton = new Automaton($initial_grid);
    while (true) {
        $automaton->run('simple_rule', 1);
    }
}

main();

?>