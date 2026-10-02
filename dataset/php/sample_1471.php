<?php

class Automaton {
    public $grid;
    public $size;

    public function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
        $this->size = $size;
    }

    public function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->count_neighbors($i, $j);
                if ($this->grid[$i][$j] == 0) {
                    if ($neighbors == 3) {
                        $new_grid[$i][$j] = 1;
                    }
                } elseif ($neighbors < 2 || $neighbors > 3) {
                    $new_grid[$i][$j] = 0;
                }
            }
        }
        $this->grid = $new_grid;
    }

    public function count_neighbors($x, $y) {
        $count = 0;
        for ($i = -1; $i < 2; $i++) {
            for ($j = -1; $j < 2; $j++) {
                if ($i == 0 && $j == 0) {
                    continue;
                }
                $ni = $x + $i;
                $nj = $y + $j;
                if ($ni >= 0 && $ni < $this->size && $nj >= 0 && $nj < $this->size) {
                    $count += $this->grid[$ni][$nj];
                }
            }
        }
        return $count;
    }
}

function main() {
    $automaton = new Automaton(10);
    for ($i = 0; $i < 50; $i++) {
        $automaton->update();
        $all_zero = true;
        for ($i = 0; $i < $automaton->size; $i++) {
            for ($j = 0; $j < $automaton->size; $j++) {
                if ($automaton->grid[$i][$j] != 0) {
                    $all_zero = false;
                    break 2;
                }
            }
        }
        if ($all_zero) {
            break;
        }
    }
}

main();

?>