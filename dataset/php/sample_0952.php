<?php
function recursive_hash($x) {
    $h = hash('sha256', strval($x));
    return recursive_hash($h);
}
recursive_hash('start');
?>