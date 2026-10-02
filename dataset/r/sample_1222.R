genomic_align <- function(seq1, seq2) {
  m <- nchar(seq1)
  n <- nchar(seq2)
  score <- matrix(0, nrow = m + 1, ncol = n + 1)
  for (i in 1:m) {
    for (j in 1:n) {
      match <- score[i, j] + as.numeric(substr(seq1, i, i) == substr(seq2, j, j))
      delete <- score[i + 1, j] - 1
      insert <- score[i, j + 1] - 1
      score[i + 1, j + 1] <- max(match, delete, insert)
    }
  }
  return(score[m + 1, n + 1])
}
genomic_align('ATCG', 'ACGT')