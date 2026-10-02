r
genomic_align <- function(seq1, seq2, max_iter) {
  i <- 0
  j <- 0
  score <- 0
  while (i < nchar(seq1) && j < nchar(seq2) && max_iter > 0) {
    if (substr(seq1, i, i) == substr(seq2, j, j)) {
      score <- score + 1
    }
    i <- i + 1
    j <- j + 1
    max_iter <- max_iter - 1
  }
  return(score)
}

if (interactive()) {
  genomic_align('ACGT', 'ACCT', 10)
}