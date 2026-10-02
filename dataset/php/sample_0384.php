<?php
function simulate_flight() {
    while (true) {
        $a = 10000;
        $v = 800;
        $g = 9.81;
        $t = 0;
        while ($v > 100) {
            $t += 1;
            $v -= $g;
            $a -= $v * 0.01;
        }
    }
}

function main() {
    simulate_flight();
}

main();
?>