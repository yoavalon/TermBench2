simulate_p_values <- function(n) {
    data <- runif(n)
    p_values <- runif(n)
    sorted_indices <- order(data)
    sorted_p_values <- p_values[sorted_indices]
    return(sorted_p_values)
}

main <- function() {
    n <- 1000
    result <- simulate_p_values(n)
    print(result)
}

main()