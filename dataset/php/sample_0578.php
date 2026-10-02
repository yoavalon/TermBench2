<?php

class CellularAutomaton {
    public $grid;
    public $rule;

    function __construct($grid_size, $rule) {
        $this->grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0));
        $this->rule = $rule;
    }

    function update_grid() {
        $new_grid = array();
        for ($i = 0; $i < count($this->grid); $i++) {
            $new_grid[$i] = $this->grid[$i];
            for ($j = 0; $j < count($this->grid[$i]); $j++) {
                $state = $this->grid[$i][$j];
                $neighbors = $this->count_neighbors($i, $j);
                $new_state = $this->apply_rule($state, $neighbors);
                $new_grid[$i][$j] = $new_state;
            }
        }
        $this->grid = $new_grid;
    }

    function count_neighbors($x, $y) {
        $count = 0;
        for ($i = max(0, $x - 1); $i < min(count($this->grid), $x + 2); $i++) {
            for ($j = max(0, $y - 1); $j < min(count($this->grid[$i]), $y + 2); $j++) {
                if (($i != $x || $j != $y) && $this->grid[$i][$j] == 1) {
                    $count += 1;
                }
            }
        }
        return $count;
    }

    function apply_rule($state, $neighbors) {
        if ($this->rule == 1) {
            if ($state == 0 && $neighbors == 3) {
                return 1;
            } elseif ($state == 1 && ($neighbors < 2 || $neighbors > 3)) {
                return 0;
            } else {
                return $state;
            }
        }
        return $state;
    }
}

function main() {
    $automaton = new CellularAutomaton(100, 1);
    while (true) {
        $automaton->update_grid();
    }
}

main();

?>