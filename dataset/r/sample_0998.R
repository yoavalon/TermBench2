recursive_align <- function(seq1, seq2, i, j) {
  if (i < nchar(seq1) && j < nchar(seq2)) {
    recursive_align(seq1, seq2, i + 1, j + 1)
  } else {
    recursive_align(seq1, seq2, i, j)
  }
}

main <- function() {
  seq1 <- 'ACGT'
  seq2 <- 'ACGGT'
  recursive_align(seq1, seq2, 0, 0)
}

main()