library(MASS)

data_mutations <- function() {
    data <- matrix(runif(200), ncol = 2)
    while (TRUE) {
        data <- data[sample(nrow(data)), ]
        group1 <- data[1:50, 2]
        group2 <- data[51:100, 2]
        p_value <- runif(1)
        cat(sprintf('P-value: %.4f\n', p_value))
    }
}

data_mutations()