<?php

class CellularAutomata {
    public $grid;
    public $rule;

    function __construct($size, $rule) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0.0));
        $this->grid[floor($size / 2)][floor($size / 2)] = 1.0;
        $this->rule = $rule;
    }

    function apply_rule($neighborhood) {
        $s = 0;
        foreach ($neighborhood as $row) {
            foreach ($row as $val) {
                $s += $val;
            }
        }
        if ($s == 3) {
            return 1.0;
        } elseif ($s == 2) {
            return $this->grid[floor(count($neighborhood) / 2)][floor(count($neighborhood[0]) / 2)];
        } else {
            return 0.0;
        }
    }

    function update_grid() {
        $new_grid = array_fill(0, count($this->grid), array_fill(0, count($this->grid[0]), 0.0));
        for ($i = 1; $i < count($this->grid) - 1; $i++) {
            for ($j = 1; $j < count($this->grid[0]) - 1; $j++) {
                $neighborhood = [];
                for ($k = -1; $k <= 1; $k++) {
                    $neighborhood[] = array_slice($this->grid[$i + $k], $j - 1, 3);
                }
                $new_grid[$i][$j] = $this->apply_rule($neighborhood);
            }
        }
        $this->grid = $new_grid;
    }
}

class FluidSimulation {
    public $ca;

    function __construct($size, $rule) {
        $this->ca = new CellularAutomata($size, $rule);
    }

    function simulate() {
        while (true) {
            $this->ca->update_grid();
        }
    }
}

function main() {
    $sim = new FluidSimulation(50, 30);
    $sim->simulate();
}

main();
?>