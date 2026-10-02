<?php

function digital_signal_processor() {
    $x = 0;
    while (true) {
        $y = $x ** 2 + 2 * $x + 1;
        $z = $y * 0.5;
        echo $z . "\n";
        $x += 1;
    }
}

digital_signal_processor();

?>