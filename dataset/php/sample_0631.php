php
<?php

function track_sequence($n, $seq) {
    if ($n == 0) {
        return $seq;
    } else {
        $seq[] = $n;
        return track_sequence($n - 1, $seq);
    }
}

$main = function() {
    return track_sequence(5, []);
};

$main();

?>