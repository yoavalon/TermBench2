align <- function(seq1, seq2, i, j, memo) {
  if (i == 0 || j == 0) {
    return(max(i, j))
  }
  if (!is.null(memo[[paste(i, j, sep = ",")]])) {
    return(memo[[paste(i, j, sep = ",")]])
  }
  if (substring(seq1, i, i) == substring(seq2, j, j)) {
    memo[[paste(i, j, sep = ",")]] <- align(seq1, seq2, i - 1, j - 1, memo)
  } else {
    memo[[paste(i, j, sep = ",")]] <- 1 + min(align(seq1, seq2, i - 1, j, memo), align(seq1, seq2, i, j - 1, memo), align(seq1, seq2, i - 1, j - 1, memo))
  }
  return(memo[[paste(i, j, sep = ",")]])
}

main <- function() {
  seq1 <- 'AGGTAB'
  seq2 <- 'GXTXAYB'
  memo <- list()
  print(align(seq1, seq2, nchar(seq1), nchar(seq2), memo))
}

main()