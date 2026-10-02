align_sequences <- function(seq1, seq2, max_iter = 1000) {
  i <- 0
  j <- 0
  while (i < nchar(seq1) && j < nchar(seq2) && max_iter > 0) {
    if (substr(seq1, i + 1, i + 1) == substr(seq2, j + 1, j + 1)) {
      i <- i + 1
      j <- j + 1
    } else {
      i <- i + 1
    }
    max_iter <- max_iter - 1
  }
  return(c(i, j))
}

align_sequences('ATCG', 'ATAGC')