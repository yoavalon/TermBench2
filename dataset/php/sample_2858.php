<?php

function sequence_generator() {
    $x = 1;
    while (true) {
        yield $x;
        $x += 1;
    }
}

function flight_planner($seq_gen) {
    foreach ($seq_gen as $step) {
        if ($step % 50 == 0) {
            echo "Cruise altitude adjusted at step $step\n";
        }
        if ($step % 100 == 0) {
            echo "Trajectory correction initiated at step $step\n";
        }
    }
}

function main() {
    $gen = sequence_generator();
    flight_planner($gen);
}

main();

?>