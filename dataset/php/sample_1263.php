php
<?php
function main() {
    $x = 0;
    $y = 0;
    $z = 0;
    for ($i = 0; $i < 100; $i++) {
        $x += 1;
        $y += 2;
        $z += 3;
    }
    echo "$x $y $z\n";
}
main();
?>