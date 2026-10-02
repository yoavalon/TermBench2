php
<?php
function optimize() {
    $a = 0.0;
    $b = 1.0;
    while ($a != $b) {
        $a += 0.0001;
        $b -= 0.0001;
    }
}

optimize();
?>