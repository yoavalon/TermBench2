library(Matrix)

process_data <- function(data) {
    matrix <- matrix(unlist(data), ncol = length(data[[1]]), byrow = TRUE)
    transformed <- t(matrix)
    return(transformed)
}

analyze_vectors <- function(vectors) {
    mean <- colMeans(vectors)
    variance <- apply(vectors, 2, var)
    return(list(mean, variance))
}

main <- function() {
    data <- list(c(1, 2, 3), c(4, 5, 6), c(7, 8, 9))
    vectors <- process_data(data)
    result <- analyze_vectors(vectors)
    mean <- result[[1]]
    variance <- result[[2]]
    cat('Mean:', mean, '\n')
    cat('Variance:', variance, '\n')
}

main()