align <- function(seq1, seq2) {
  if (nchar(seq1) == 0 || nchar(seq2) == 0) {
    return(0)
  }
  if (substring(seq1, 1, 1) == substring(seq2, 1, 1)) {
    return(1 + align(substring(seq1, 2), substring(seq2, 2)))
  } else {
    align1 <- align(substring(seq1, 2), seq2)
    align2 <- align(seq1, substring(seq2, 2))
    return(max(align1, align2))
  }
}

main <- function() {
  seq1 <- 'AGGTAB'
  seq2 <- 'GXTXAYB'
  result <- align(seq1, seq2)
  print(result)
}

main()