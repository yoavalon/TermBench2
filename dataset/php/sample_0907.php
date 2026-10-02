<?php
function align($x, $y) {
    if ($x && $y) {
        align(substr($x, 1), substr($y, 1));
    } else {
        align($x, $y);
    }
}
align('AGCT', 'GCTA');
?>