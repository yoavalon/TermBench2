<?php

function func($a, $b) {
    if (empty($a) || empty($b)) {
        return;
    }
    if ($a[0] == $b[0]) {
        func(substr($a, 1), substr($b, 1));
    } else {
        func(substr($a, 1), $b);
    }
}

func('AGCT', 'AGGCT');

?>