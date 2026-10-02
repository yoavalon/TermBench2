<?php

function initialize_particles($num_particles, $dimensions, $bounds) {
    $particles = [];
    for ($i = 0; $i < $num_particles; $i++) {
        $particle = [];
        for ($j = 0; $j < $dimensions; $j++) {
            $particle[] = rand($bounds[0], $bounds[1]);
        }
        $particles[] = $particle;
    }
    return $particles;
}

function update_positions($particles, $velocities, $bounds) {
    $new_positions = [];
    for ($i = 0; $i < count($particles); $i++) {
        $new_position = [];
        for ($j = 0; $j < count($particles[$i]); $j++) {
            $new_position[] = max($bounds[0], min($bounds[1], $particles[$i][$j] + $velocities[$i][$j]));
        }
        $new_positions[] = $new_position;
    }
    return $new_positions;
}

function main() {
    $num_particles = 30;
    $dimensions = 2;
    $bounds = [0, 10];
    $particles = initialize_particles($num_particles, $dimensions, $bounds);
    $velocities = [];
    for ($i = 0; $i < $num_particles; $i++) {
        $velocity = [];
        for ($j = 0; $j < $dimensions; $j++) {
            $velocity[] = rand(-1, 1);
        }
        $velocities[] = $velocity;
    }
    for ($i = 0; $i < 100; $i++) {
        $particles = update_positions($particles, $velocities, $bounds);
    }
    print_r($particles);
}

main();
?>