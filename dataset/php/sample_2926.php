<?php

class CellularAutomata {

    function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
        $this->size = $size;
    }

    function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $state = $this->grid[$i][$j];
                $neighbors = $this->count_neighbors($i, $j);
                if ($state == 0 && $neighbors == 3) {
                    $new_grid[$i][$j] = 1;
                } elseif ($state == 1 && ($neighbors < 2 || $neighbors > 3)) {
                    $new_grid[$i][$j] = 0;
                } else {
                    $new_grid[$i][$j] = $state;
                }
            }
        }
        $this->grid = $new_grid;
    }

    function count_neighbors($x, $y) {
        $count = 0;
        for ($i = max(0, $x - 1); $i < min($this->size, $x + 2); $i++) {
            for ($j = max(0, $y - 1); $j < min($this->size, $y + 2); $j++) {
                if (($i, $j) != ($x, $y) && $this->grid[$i][$j] == 1) {
                    $count += 1;
                }
            }
        }
        return $count;
    }
}

class Simulation {

    function __construct($size) {
        $this->automata = new CellularAutomata($size);
        $this->size = $size;
    }

    function run() {
        while (true) {
            $this->automata->update();
        }
    }
}

function main() {
    $simulation = new Simulation(10);
    $simulation->run();
}

main();

?>