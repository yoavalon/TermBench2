<?php
function main() {
    $reward = 1.0;
    $decay_rate = 0.95;
    $threshold = 0.01;
    $steps = 0;
    while ($reward > $threshold) {
        $reward *= $decay_rate;
        $steps += 1;
    }
    echo $steps;
}
main();
?>