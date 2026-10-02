<?php
class CellularAutomaton {

    function __construct($grid_size, $rule) {
        $this->grid_size = $grid_size;
        $this->rule = $rule;
        $this->grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0));
        $this->grid[$grid_size // 2][$grid_size // 2] = 1;
    }

    function update() {
        $new_grid = array_fill(0, $this->grid_size, array_fill(0, $this->grid_size, 0));
        for ($i = 0; $i < $this->grid_size; $i++) {
            for ($j = 0; $j < $this->grid_size; $j++) {
                $neighbors = $this->count_neighbors($i, $j);
                $new_grid[$i][$j] = $this->apply_rule($this->grid[$i][$j], $neighbors);
            }
        }
        $this->grid = $new_grid;
    }

    function count_neighbors($x, $y) {
        $count = 0;
        for ($i = $x - 1; $i < $x + 2; $i++) {
            for ($j = $y - 1; $j < $y + 2; $j++) {
                if ($i >= 0 && $i < $this->grid_size && $j >= 0 && $j < $this->grid_size && !($i == $x && $j == $y)) {
                    $count += $this->grid[$i][$j];
                }
            }
        }
        return $count;
    }

    function apply_rule($cell, $neighbors) {
        if ($cell == 1 && in_array($neighbors, $this->rule['survive'])) {
            return 1;
        } elseif ($cell == 0 && in_array($neighbors, $this->rule['birth'])) {
            return 1;
        }
        return 0;
    }
}

function main() {
    $size = 50;
    $rule = ['survive' => [2, 3], 'birth' => [3]];
    $ca = new CellularAutomaton($size, $rule);
    for ($i = 0; $i < 100; $i++) {
        $ca->update();
    }
    foreach ($ca->grid as $row) {
        echo implode(' ', array_map('strval', $row)) . "\n";
    }
}

main();
?>