forward_pass <- function(matrix, vector) {
    result <- matrix %*% vector
    return(result)
}

main <- function() {
    matrix <- matrix(c(0.1, 0.2, 0.3, 0.4), nrow=2, ncol=2, byrow=TRUE)
    vector <- c(0.5, 0.6)
    output <- forward_pass(matrix, vector)
    print(output)
}

main()