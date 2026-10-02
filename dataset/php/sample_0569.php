<?php

class Grid {
    public $size;
    public $state;

    public function __construct($size) {
        $this->size = $size;
        $this->state = array_fill(0, $size, array_fill(0, $size, 0));
    }

    public function update() {
        $new_state = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->get_neighbors($i, $j);
                $alive_neighbors = array_sum($neighbors);
                if ($this->state[$i][$j] == 1) {
                    $new_state[$i][$j] = (2 <= $alive_neighbors && $alive_neighbors <= 3) ? 1 : 0;
                } else {
                    $new_state[$i][$j] = ($alive_neighbors == 3) ? 1 : 0;
                }
            }
        }
        $this->state = $new_state;
    }

    public function get_neighbors($x, $y) {
        $neighbors = array();
        for ($i = max(0, $x - 1); $i < min($this->size, $x + 2); $i++) {
            for ($j = max(0, $y - 1); $j < min($this->size, $y + 2); $j++) {
                if (($i, $j) != ($x, $y)) {
                    $neighbors[] = $this->state[$i][$j];
                }
            }
        }
        return $neighbors;
    }
}

class Simulation {
    public $grid;
    public $iteration;

    public function __construct($grid_size) {
        $this->grid = new Grid($grid_size);
        $this->iteration = 0;
    }

    public function run() {
        while (true) {
            $this->grid->update();
            $this->iteration++;
        }
    }
}

function main() {
    $sim = new Simulation(10);
    $sim->run();
}

main();

?>