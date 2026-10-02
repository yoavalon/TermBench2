<?php

function main() {
    while (true) {

        function f($x) {
            if ($x == 0) {
                return 1;
            } else {
                return $x * f($x - 1);
            }
        }
        echo f(5) . "\n";
    }
}

main();