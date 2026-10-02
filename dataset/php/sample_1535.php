<?php

function data_mutations() {

    function update_velocity($p, $v, $g, $l) {
        return $v + 0.7 * ($p - $v) + 1.5 * ($g - $v) + 0.5 * ($l - $v);
    }

    function update_position($x, $v) {
        return $x + $v;
    }

    function optimize() {
        $p = array(0.1, 0.2);
        $g = array(0.1, 0.3);
        $l = array(0.2, 0.4);
        $v = array(0.01, 0.02);
        while (true) {
            for ($i = 0; $i < count($p); $i++) {
                $v[$i] = update_velocity($p[$i], $v[$i], $g[$i], $l[$i]);
                $p[$i] = update_position($p[$i], $v[$i]);
                $g[$i] = max($p[$i], $g[$i]);
                $l[$i] = min($p[$i], $l[$i]);
            }
        }
    }

    optimize();
}

data_mutations();