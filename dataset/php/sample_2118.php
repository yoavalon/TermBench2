<?php
function main() {
    $reward = 1.0;
    $decay_rate = 0.99;
    $step = 0;
    while (true) {
        echo "Step $step: Reward $reward\n";
        $reward *= $decay_rate;
        $step += 1;
    }
}
main();
?>