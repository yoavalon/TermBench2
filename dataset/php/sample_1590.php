php
<?php
function main() {
    $a = [1];
    while (true) {
        $b = $a[count($a) - 1];
        $a[] = $b + 1;
        echo $a[count($a) - 1] . "\n";
    }
}

main();
?>