<?php
class FluidSimulator {
    public $size;
    public $state;

    function __construct($size, $initial_state) {
        $this->size = $size;
        $this->state = $initial_state;
    }

    function update_state() {
        $new_state = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->get_neighbors($i, $j);
                $new_state[$i][$j] = $this->apply_rules($neighbors);
            }
        }
        $this->state = $new_state;
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
                $neighbors[] = $this->state[$nx][$ny];
            }
        }
        return $neighbors;
    }

    function apply_rules($neighbors) {
        $active_neighbors = array_sum($neighbors);
        if ($this->state[0][0] == 1) {
            return $active_neighbors >= 2 ? 1 : 0;
        } else {
            return $active_neighbors == 3 ? 1 : 0;
        }
    }
}

function initialize_grid($size) {
    $grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $grid[$i][$j] = ($i % 2 && $j % 2) ? 0 : 1;
        }
    }
    return $grid;
}

function main() {
    $grid_size = 10;
    $initial_state = initialize_grid($grid_size);
    $simulator = new FluidSimulator($grid_size, $initial_state);
    while (true) {
        $simulator->update_state();
    }
}

main();
?>