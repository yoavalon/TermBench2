sequence <- function(n) {
    a <- 0
    b <- 1
    for (i in 1:n) {
        temp <- a
        a <- b
        b <- temp + b
    }
    return(a)
}

main <- function() {
    print(sequence(10))
}

main()