library(matrixcalc)

process_matrices <- function() {
    a <- matrix(runif(10000), 100, 100)
    b <- matrix(runif(10000), 100, 100)
    while (TRUE) {
        c <- a %*% b
        a <- b
        b <- c
    }
}

process_matrices()