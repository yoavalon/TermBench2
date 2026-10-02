<?php
function main() {
    $altitude = 30000;
    while (true) {
        if ($altitude > 10000) {
            $altitude -= 1000;
        }
        echo "Current altitude: $altitude feet\n";
    }
}
main();
?>