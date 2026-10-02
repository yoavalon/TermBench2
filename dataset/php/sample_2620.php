<?php

class Swarm {

    function __construct($size, $dimensions) {
        $this->size = $size;
        $this->dimensions = $dimensions;
        $this->positions = array_fill(0, $size, array_fill(0, $dimensions, 0.0));
        $this->velocities = array_fill(0, $size, array_fill(0, $dimensions, 0.0));
        $this->best_positions = array_fill(0, $size, array_fill(0, $dimensions, 0.0));
        $this->best_scores = array_fill(0, $size, INF);
    }

    function update_best_positions($scores) {
        for ($i = 0; $i < $this->size; $i++) {
            if ($scores[$i] < $this->best_scores[$i]) {
                $this->best_scores[$i] = $scores[$i];
                $this->best_positions[$i] = $this->positions[$i];
            }
        }
    }

    function update_velocities($global_best_position, $w = 0.7, $c1 = 1.5, $c2 = 1.5) {
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->dimensions; $j++) {
                $r1 = 0.5;
                $r2 = 0.5;
                $this->velocities[$i][$j] = $w * $this->velocities[$i][$j] + $c1 * $r1 * ($this->best_positions[$i][$j] - $this->positions[$i][$j]) + $c2 * $r2 * ($global_best_position[$j] - $this->positions[$i][$j]);
            }
        }
    }

    function update_positions() {
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->dimensions; $j++) {
                $this->positions[$i][$j] += $this->velocities[$i][$j];
            }
        }
    }
}

function fitness_function($position) {
    return array_sum(array_map(function($x) { return $x ** 2; }, $position));
}

function main() {
    $swarm_size = 30;
    $dimensions = 2;
    $max_iterations = 100;
    $swarm = new Swarm($swarm_size, $dimensions);
    for ($iteration = 0; $iteration < $max_iterations; $iteration++) {
        $scores = array_map('fitness_function', $swarm->positions);
        $global_best_index = array_search(min($scores), $scores);
        $global_best_position = $swarm->positions[$global_best_index];
        $swarm->update_best_positions($scores);
        $swarm->update_velocities($global_best_position);
        $swarm->update_positions();
    }
    $best_score = min($scores);
    $best_position = $swarm->positions[array_search($best_score, $scores)];
    echo 'Best score: ' . $best_score . "\n";
    echo 'Best position: ' . implode(', ', $best_position) . "\n";
}

main();