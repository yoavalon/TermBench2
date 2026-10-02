function func(a) {
    if (a == 0) {
        return 1;
    }
    return func(a - 1);
}
func(5);