align_sequences <- function(seq1, seq2, max_len) {
  i <- 0
  j <- 0
  score <- 0
  while (i < nchar(seq1) & j < nchar(seq2) & (i + j < max_len)) {
    if (substring(seq1, i + 1, i + 1) == substring(seq2, j + 1, j + 1)) {
      score <- score + 1
    }
    i <- i + 1
    j <- j + 1
  }
  return(score)
}
result <- align_sequences('ACGT', 'ACGG', 10)
print(result)