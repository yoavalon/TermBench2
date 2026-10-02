<?php

class FluidSimulator {
    public $grid;
    public $rules;

    function __construct($grid_size, $rules) {
        $this->grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0));
        $this->rules = $rules;
    }

    function update() {
        $new_grid = array_fill(0, count($this->grid), array_fill(0, count($this->grid), 0));
        for ($i = 0; $i < count($this->grid); $i++) {
            for ($j = 0; $j < count($this->grid); $j++) {
                $new_grid[$i][$j] = $this->rules->apply($this->grid, $i, $j);
            }
        }
        $this->grid = $new_grid;
    }

    function display() {
        foreach ($this->grid as $row) {
            echo implode(' ', array_map('strval', $row)) . "\n";
        }
        echo "\n";
    }
}

class RuleSet {
    function apply($grid, $x, $y) {
        $neighbors = $this->count_neighbors($grid, $x, $y);
        return $neighbors == 2 ? 1 : 0;
    }

    function count_neighbors($grid, $x, $y) {
        $count = 0;
        for ($i = max(0, $x - 1); $i < min(count($grid), $x + 2); $i++) {
            for ($j = max(0, $y - 1); $j < min(count($grid), $y + 2); $j++) {
                if (($i, $j) != ($x, $y) && $grid[$i][$j] == 1) {
                    $count += 1;
                }
            }
        }
        return $count;
    }
}

function main() {
    $grid_size = 10;
    $rules = new RuleSet();
    $simulator = new FluidSimulator($grid_size, $rules);
    $simulator->grid[4][4] = 1;
    $simulator->grid[5][4] = 1;
    $simulator->grid[4][5] = 1;
    while (true) {
        $simulator->display();
        $simulator->update();
    }
}

main();

?>