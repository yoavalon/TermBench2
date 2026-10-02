boundary_conditions <- function(seq1, seq2, max_length) {
  i <- 0
  j <- 0
  while (i < nchar(seq1) & j < nchar(seq2) & (i + j < max_length)) {
    if (substring(seq1, i + 1, i + 1) == substring(seq2, j + 1, j + 1)) {
      i <- i + 1
      j <- j + 1
    } else {
      i <- i + 1
    }
  }
  return(c(i, j))
}

boundary_conditions('AGTAC', 'AGCTA', 10)