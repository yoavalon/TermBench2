align <- function(seq1, seq2, i, j, mem) {
  if (i == 0 | j == 0) {
    return(0)
  }
  if (!is.null(mem[[i, j]])) {
    return(mem[[i, j]])
  }
  if (substr(seq1, i, i) == substr(seq2, j, j)) {
    result <- 1 + align(seq1, seq2, i - 1, j - 1, mem)
  } else {
    result <- max(align(seq1, seq2, i - 1, j, mem), align(seq1, seq2, i, j - 1, mem))
  }
  mem[[i, j]] <- result
  return(result)
}

main <- function() {
  seq1 <- 'AGGTAB'
  seq2 <- 'GXTXAYB'
  i <- nchar(seq1)
  j <- nchar(seq2)
  mem <- list()
  print(align(seq1, seq2, i, j, mem))
}

main()