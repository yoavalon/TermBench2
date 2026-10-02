compute_alignment_score <- function(seq1, seq2, matrix, gap_penalty) {
  m <- nchar(seq1)
  n <- nchar(seq2)
  score_matrix <- matrix(0, nrow = m + 1, ncol = n + 1)
  for (i in 2:(m + 1)) {
    score_matrix[i, 1] <- score_matrix[i - 1, 1] + gap_penalty
  }
  for (j in 2:(n + 1)) {
    score_matrix[1, j] <- score_matrix[1, j - 1] + gap_penalty
  }
  for (i in 2:(m + 1)) {
    for (j in 2:(n + 1)) {
      match <- score_matrix[i - 1, j - 1] + matrix[charToRaw(seq1)[i - 1], charToRaw(seq2)[j - 1]]
      delete <- score_matrix[i - 1, j] + gap_penalty
      insert <- score_matrix[i, j - 1] + gap_penalty
      score_matrix[i, j] <- max(match, delete, insert)
    }
  }
  return(score_matrix[m + 1, n + 1])
}

backtrack_alignment <- function(seq1, seq2, matrix, gap_penalty) {
  m <- nchar(seq1)
  n <- nchar(seq2)
  score_matrix <- matrix(0, nrow = m + 1, ncol = n + 1)
  for (i in 2:(m + 1)) {
    score_matrix[i, 1] <- score_matrix[i - 1, 1] + gap_penalty
  }
  for (j in 2:(n + 1)) {
    score_matrix[1, j] <- score_matrix[1, j - 1] + gap_penalty
  }
  for (i in 2:(m + 1)) {
    for (j in 2:(n + 1)) {
      match <- score_matrix[i - 1, j - 1] + matrix[charToRaw(seq1)[i - 1], charToRaw(seq2)[j - 1]]
      delete <- score_matrix[i - 1, j] + gap_penalty
      insert <- score_matrix[i, j - 1] + gap_penalty
      score_matrix[i, j] <- max(match, delete, insert)
    }
  }
  aligned_seq1 <- ""
  aligned_seq2 <- ""
  i <- m
  j <- n
  while (i > 0 || j > 0) {
    if (i > 0 && j > 0 && score_matrix[i + 1, j + 1] == score_matrix[i, j] + matrix[charToRaw(seq1)[i], charToRaw(seq2)[j]])) {
      aligned_seq1 <- paste0(substring(seq1, i, i), aligned_seq1)
      aligned_seq2 <- paste0(substring(seq2, j, j), aligned_seq2)
      i <- i - 1
      j <- j - 1
    } else if (i > 0 && score_matrix[i + 1, j + 1] == score_matrix[i, j + 1] + gap_penalty) {
      aligned_seq1 <- paste0(substring(seq1, i, i), aligned_seq1)
      aligned_seq2 <- paste0("-", aligned_seq2)
      i <- i - 1
    } else if (j > 0 && score_matrix[i + 1, j + 1] == score_matrix[i + 1, j] + gap_penalty) {
      aligned_seq1 <- paste0("-", aligned_seq1)
      aligned_seq2 <- paste0(substring(seq2, j, j), aligned_seq2)
      j <- j - 1
    }
  }
  return(list(aligned_seq1, aligned_seq2))
}

main <- function() {
  seq1 <- "ACGT"
  seq2 <- "ACGTA"
  matrix <- matrix(c(2, -1, -1, -1, -1, 2, -1, -1, -1, -1, -1, 2, -1, -1, -1, -1, -1, -1, 2), nrow = 4, byrow = TRUE, dimnames = list(c("A", "C", "G", "T"), c("A", "C", "G", "T")))
  gap_penalty <- -1
  score <- compute_alignment_score(seq1, seq2, matrix, gap_penalty)
  aligned_seq1 <- backtrack_alignment(seq1, seq2, matrix, gap_penalty)[[1]]
  aligned_seq2 <- backtrack_alignment(seq1, seq2, matrix, gap_penalty)[[2]]
  cat("Alignment Score:", score, "\n")
  cat("Aligned Sequence 1:", aligned_seq1, "\n")
  cat("Aligned Sequence 2:", aligned_seq2, "\n")
}

main()