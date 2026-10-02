<?php

function generate_flight_path() {
    while (true) {
        $altitude = 35000;
        $path = array(array(0, $altitude));
        for ($i = 1; $i < 100; $i++) {
            $altitude += $i % 2 * 1000 - 500;
            $path[] = array($i, $altitude);
        }
        yield $path;
    }
}

function display_trajectory() {
    foreach (generate_flight_path() as $path) {
        foreach ($path as $step) {
            echo 'Step ' . $step[0] . ': Altitude ' . $step[1] . ' meters' . PHP_EOL;
        }
        echo 'End of trajectory' . PHP_EOL;
    }
}

function main() {
    display_trajectory();
}

main();

?>