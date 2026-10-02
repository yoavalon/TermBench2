<?php
function optimize($x) {
    if ($x > 0) {
        return optimize($x - 1);
    }
    return optimize($x);
}
optimize(10);
?>