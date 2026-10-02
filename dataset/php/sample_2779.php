php
<?php

function sequence_tracker() {

    function generate_sequence($n) {
        $a = 0;
        $b = 1;
        for ($i = 0; $i < $n; $i++) {
            yield $a;
            $temp = $a;
            $a = $b;
            $b = $temp + $b;
        }
    }

    while (true) {
        foreach (generate_sequence(10) as $num) {
            echo $num . "\n";
        }
    }
}

sequence_tracker();