r
align_sequences <- function(seq1, seq2) {
    len1 <- nchar(seq1)
    len2 <- nchar(seq2)
    matrix <- matrix(0, nrow = len1 + 1, ncol = len2 + 1)
    for (i in 1:len1) {
        for (j in 1:len2) {
            if (substr(seq1, i, i) == substr(seq2, j, j)) {
                matrix[i + 1, j + 1] <- matrix[i, j] + 1
            } else {
                matrix[i + 1, j + 1] <- max(matrix[i, j + 1], matrix[i + 1, j])
            }
        }
    }
    return(matrix[len1 + 1, len2 + 1])
}

process_data <- function(data) {
    results <- list()
    for (pair in data) {
        seq1 <- pair[[1]]
        seq2 <- pair[[2]]
        score <- align_sequences(seq1, seq2)
        results <- c(results, score)
    }
    return(results)
}

main <- function() {
    data <- list(c("AGGTAB", "GXTXAYB"), c("ABCBDAB", "BDCAB"), c("", "XYZ"), c("AAAA", "AAAA"))
    output <- process_data(data)
    print(output)
}

main()