<?php

class CellularAutomata {

    public function __construct($size, $rule) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
        $this->rule = $rule;
        $this->size = $size;
    }

    public function set_initial_state($x, $y) {
        $this->grid[$x][$y] = 1;
    }

    public function get_neighbors($x, $y) {
        $count = 0;
        for ($i = -1; $i <= 1; $i++) {
            for ($j = -1; $j <= 1; $j++) {
                if ($i == 0 && $j == 0) {
                    continue;
                }
                $nx = ($x + $i) % $this->size;
                $ny = ($y + $j) % $this->size;
                $count += $this->grid[$nx][$ny];
            }
        }
        return $count;
    }

    public function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $n = $this->get_neighbors($i, $j);
                $new_grid[$i][$j] = $this->apply_rule($this->grid[$i][$j], $n);
            }
        }
        $this->grid = $new_grid;
    }

    public function apply_rule($state, $neighbors) {
        if ($state == 0 && $neighbors == $this->rule) {
            return 1;
        }
        return 0;
    }
}

function main() {
    $ca = new CellularAutomata(10, 3);
    $ca->set_initial_state(5, 5);
    while (true) {
        $ca->update();
    }
}

main();

?>