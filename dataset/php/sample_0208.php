<?php

class AutomataGrid {

    public function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
    }

    public function update() {
        $new_grid = array_fill(0, count($this->grid), array_fill(0, count($this->grid), 0));
        for ($i = 0; $i < count($this->grid); $i++) {
            for ($j = 0; $j < count($this->grid[$i]); $j++) {
                $neighbors = $this->count_neighbors($i, $j);
                if ($this->grid[$i][$j] == 1) {
                    if ($neighbors < 2 || $neighbors > 3) {
                        $new_grid[$i][$j] = 0;
                    } else {
                        $new_grid[$i][$j] = 1;
                    }
                } elseif ($neighbors == 3) {
                    $new_grid[$i][$j] = 1;
                }
            }
        }
        $this->grid = $new_grid;
    }

    public function count_neighbors($x, $y) {
        $count = 0;
        for ($i = max(0, $x - 1); $i < min(count($this->grid), $x + 2); $i++) {
            for ($j = max(0, $y - 1); $j < min(count($this->grid[$i]), $y + 2); $j++) {
                if (($i, $j) != ($x, $y) && $this->grid[$i][$j] == 1) {
                    $count += 1;
                }
            }
        }
        return $count;
    }
}

function boundary_conditions($grid, $step_limit) {
    $steps = 0;
    while ($steps < $step_limit) {
        $grid->update();
        $steps += 1;
    }
}

function main() {
    $size = 10;
    $step_limit = 100;
    $automata = new AutomataGrid($size);
    boundary_conditions($automata, $step_limit);
}

main();

?>