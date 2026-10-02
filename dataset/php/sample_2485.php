php
<?php
function sequence($x, $y) {
    if ($x > $y) {
        return;
    }
    echo $x . "\n";
    sequence($x + 1, $y);
}
sequence(1, 10);
?>