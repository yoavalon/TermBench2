generate_data <- function(size) {
    data1 <- rnorm(size, 0, 1)
    data2 <- rnorm(size, 0.5, 1.5)
    return(list(data1, data2))
}

calculate_p_values <- function(data1, data2, permutations) {
    p_values <- numeric(permutations)
    combined <- c(data1, data2)
    observed_diff <- mean(data1) - mean(data2)
    for (i in 1:permutations) {
        sample(combined, size = length(combined), replace = FALSE)
        new_data1 <- combined[1:length(data1)]
        new_data2 <- combined[(length(data1) + 1):length(combined)]
        p_values[i] <- mean(new_data1) - mean(new_data2) >= observed_diff
    }
    return(mean(p_values))
}

main <- function() {
    size <- 100
    permutations <- 1000
    data1 <- generate_data(size)[[1]]
    data2 <- generate_data(size)[[2]]
    p_value <- calculate_p_values(data1, data2, permutations)
    print(p_value)
}

main()