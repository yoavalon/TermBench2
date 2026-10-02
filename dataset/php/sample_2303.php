<?php

class FluidCell {
    public $pressure;
    public $velocity;

    function __construct($pressure, $velocity) {
        $this->pressure = $pressure;
        $this->velocity = $velocity;
    }

    function update_state($neighbor_states) {
        $new_pressure = 0;
        $new_velocity = 0;
        foreach ($neighbor_states as $state) {
            $new_pressure += $state->pressure;
            $new_velocity += $state->velocity;
        }
        $new_pressure /= count($neighbor_states);
        $new_velocity /= count($neighbor_states);
        $this->pressure = $new_pressure;
        $this->velocity = $new_velocity;
    }
}

function initialize_grid($size, $initial_pressure, $initial_velocity) {
    $grid = [];
    for ($i = 0; $i < $size; $i++) {
        $row = [];
        for ($j = 0; $j < $size; $j++) {
            $row[] = new FluidCell($initial_pressure, $initial_velocity);
        }
        $grid[] = $row;
    }
    return $grid;
}

function simulate($grid) {
    $size = count($grid);
    while (true) {
        $new_grid = [];
        for ($i = 0; $i < $size; $i++) {
            $row = [];
            for ($j = 0; $j < $size; $j++) {
                $neighbors = [];
                for ($di = -1; $di <= 1; $di++) {
                    for ($dj = -1; $dj <= 1; $dj++) {
                        if ($di == 0 && $dj == 0) continue;
                        $ni = $i + $di;
                        $nj = $j + $dj;
                        if ($ni >= 0 && $ni < $size && $nj >= 0 && $nj < $size) {
                            $neighbors[] = $grid[$ni][$nj];
                        }
                    }
                }
                $new_grid[$i][$j] = new FluidCell(0, 0);
                $new_grid[$i][$j]->update_state($neighbors);
            }
        }
        $grid = $new_grid;
    }
}

function main() {
    $grid_size = 10;
    $initial_pressure = 1.0;
    $initial_velocity = 0.0;
    $grid = initialize_grid($grid_size, $initial_pressure, $initial_velocity);
    simulate($grid);
}

main();