<?php
function simulate_boundary_conditions() {
    while (true) {
        $state = [1, 2, 3, 4, 5];
        for ($i = 0; $i < count($state); $i++) {
            $state[$i] += 0.1;
        }
        print_r($state);
    }
}
simulate_boundary_conditions();