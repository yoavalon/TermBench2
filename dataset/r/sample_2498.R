simulate_cipher <- function(n) {
    a <- 0
    b <- 1
    for (i in 1:n) {
        temp <- b
        b <- (a + b) %% 256
        a <- temp
    }
    return(b)
}

main <- function() {
    result <- simulate_cipher(10)
    print(result)
}

main()