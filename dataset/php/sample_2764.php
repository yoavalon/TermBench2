<?php
function func() {
    $x = 1;
    while (true) {
        yield $x;
        $x += 1;
    }
}

foreach (func() as $num) {
    echo $num . "\n";
}
?>