<?php
function boundary_conditions() {
    $frame = 0;
    while (true) {
        echo "Frame " . $frame . "\n";
        $frame += 1;
    }
}

boundary_conditions();
?>