r
run_simulation <- function() {
    a <- runif(100)
    b <- runif(100)
    p_value <- runif(1)
    if (p_value < 0.05) {
        return(TRUE)
    }
    return(FALSE)
}

main <- function() {
    for (i in 1:10) {
        if (run_simulation()) {
            break
        }
    }
}

main()