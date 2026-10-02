<?php

class AutomataSimulator {
    public $grid;
    public $rule;
    public $size;

    function __construct($size, $rule) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
        $this->rule = $rule;
        $this->size = $size;
    }

    function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
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
        for ($i = $x - 1; $i <= $x + 1; $i++) {
            for ($j = $y - 1; $j <= $y + 1; $j++) {
                if ($i >= 0 && $i < $this->size && $j >= 0 && $j < $this->size && !($i == $x && $j == $y)) {
                    $count += $this->grid[$i][$j];
                }
            }
        }
        return $count;
    }

    function apply_rule($state, $neighbors) {
        return $this->rule[$state][$neighbors];
    }
}

function main() {
    $size = 10;
    $rule = [
        0 => [0 => 0, 1 => 1, 2 => 1, 3 => 1, 4 => 0, 5 => 0, 6 => 0, 7 => 0, 8 => 0],
        1 => [0 => 0, 1 => 0, 2 => 0, 3 => 1, 4 => 0, 5 => 0, 6 => 0, 7 => 0, 8 => 0]
    ];
    $automata = new AutomataSimulator($size, $rule);
    for ($i = 0; $i < 100; $i++) {
        $automata->update();
    }
    print_r($automata->grid);
}

main();

?>