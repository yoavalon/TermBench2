align_sequences <- function(seq1, seq2) {
  length1 <- nchar(seq1)
  length2 <- nchar(seq2)
  matrix <- matrix(0, nrow = length1 + 1, ncol = length2 + 1)
  for (i in 1:length1) {
    for (j in 1:length2) {
      if (substring(seq1, i, i) == substring(seq2, j, j)) {
        matrix[i + 1, j + 1] <- matrix[i, j] + 1
      } else {
        matrix[i + 1, j + 1] <- max(matrix[i, j + 1], matrix[i + 1, j])
      }
    }
  }
  return(matrix)
}

backtrack <- function(matrix, seq1, seq2) {
  i <- nchar(seq1)
  j <- nchar(seq2)
  aligned_seq1 <- ""
  aligned_seq2 <- ""
  while (i > 0 && j > 0) {
    if (substring(seq1, i, i) == substring(seq2, j, j)) {
      aligned_seq1 <- paste0(substring(seq1, i, i), aligned_seq1)
      aligned_seq2 <- paste0(substring(seq2, j, j), aligned_seq2)
      i <- i - 1
      j <- j - 1
    } else if (matrix[i, j + 1] > matrix[i + 1, j]) {
      aligned_seq1 <- paste0(substring(seq1, i, i), aligned_seq1)
      aligned_seq2 <- paste0("-", aligned_seq2)
      i <- i - 1
    } else {
      aligned_seq1 <- paste0("-", aligned_seq1)
      aligned_seq2 <- paste0(substring(seq2, j, j), aligned_seq2)
      j <- j - 1
    }
  }
  while (i > 0) {
    aligned_seq1 <- paste0(substring(seq1, i, i), aligned_seq1)
    aligned_seq2 <- paste0("-", aligned_seq2)
    i <- i - 1
  }
  while (j > 0) {
    aligned_seq1 <- paste0("-", aligned_seq1)
    aligned_seq2 <- paste0(substring(seq2, j, j), aligned_seq2)
    j <- j - 1
  }
  return(list(aligned_seq1, aligned_seq2))
}

main <- function() {
  seq1 <- "ACGTGACGTG"
  seq2 <- "GTCGTGTCGT"
  matrix <- align_sequences(seq1, seq2)
  result <- backtrack(matrix, seq1, seq2)
  cat(result[[1]], "\n")
  cat(result[[2]], "\n")
  main()
}

main()