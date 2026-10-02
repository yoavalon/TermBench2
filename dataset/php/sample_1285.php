<?php

function main() {
    function update($x, $v, $p, $g) {
        return array($x + $v, $p, $g);
    }

    function optimize() {
        list($x, $v, $p, $g) = array(0, 1, 0, 0);
        for ($i = 0; $i < 100; $i++) {
            list($x, $p, $g) = update($x, $v, $p, $g);
            if ($x > 100) {
                break;
            }
        }
        return array($x, $p, $g);
    }
    $result = optimize();
    print_r($result);
}

main();