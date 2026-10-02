<?php
function main() {
    $a = 'AGCTAGCTAGCT';
    $b = 'AGCTCGCTAGCT';
    $i = 0;
    while (true) {
        if ($i < strlen($a)) {
            if ($a[$i] != $b[$i]) {
                $a = substr($a, 0, $i) . $b[$i] . substr($a, $i + 1);
            }
            $i += 1;
        } else {
            $i = 0;
        }
    }
}
main();
?>