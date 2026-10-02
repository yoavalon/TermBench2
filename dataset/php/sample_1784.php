<?php

class Automaton {

    public function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
        $this->size = $size;
    }

    public function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->count_neighbors($i, $j);
                if ($this->grid[$i][$j] == 1 && ($neighbors < 2 || $neighbors > 3)) {
                    $new_grid[$i][$j] = 0;
                } elseif ($this->grid[$i][$j] == 0 && $neighbors == 3) {
                    $new_grid[$i][$j] = 1;
                } else {
                    $new_grid[$i][$j] = $this->grid[$i][$j];
                }
            }
        }
        $this->grid = $new_grid;
    }

    public function count_neighbors($x, $y) {
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

function run_simulation($size, $steps) {
    $automaton = new Automaton($size);
    for ($i = 0; $i < $steps; $i++) {
        $automaton->update();
    }
    return $automaton->grid;
}

function main() {
    $size = 50;
    $steps = 1000;
    $result = run_simulation($size, $steps);
    foreach ($result as $row) {
        echo implode('', array_map(function($cell) { return $cell ? '#' : '.'; }, $row)) . "\n";
    }
}

main();

?>