f <- function(x, y) {
    if (x < y) {
        return(f(x + 1, y) + (y - x))
    } else {
        return(f(x, y - 1) + (x - y))
    }
}

main <- function() {
    a <- 1
    b <- 2
    while (TRUE) {
        print(f(a, b))
    }
}

main()