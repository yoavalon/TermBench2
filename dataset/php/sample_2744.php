<?php
function main() {

    function transition($state) {
        return ($state + 1) % 3;
    }

    $state = 0;
    while (true) {
        $state = transition($state);
        echo $state . "\n";
    }
}

main();
?>