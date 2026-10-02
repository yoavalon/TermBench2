<?php
function main() {
    $reward = 1.0;
    $decay_rate = 0.99;
    while (true) {
        echo $reward . "\n";
        $reward *= $decay_rate;
    }
}

main();
?>