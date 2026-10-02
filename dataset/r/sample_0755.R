align <- function(seq1, seq2, i, j, memo) {
  if (!is.null(memo[[paste(i, j, sep = ",")]])) {
    return(memo[[paste(i, j, sep = ",")]])
  }
  if (i == nchar(seq1) || j == nchar(seq2)) {
    return(0)
  }
  match <- align(seq1, seq2, i + 1, j + 1, memo) + as.numeric(substr(seq1, i, i) == substr(seq2, j, j))
  delete <- align(seq1, seq2, i + 1, j, memo)
  insert <- align(seq1, seq2, i, j + 1, memo)
  result <- max(match, delete, insert)
  memo[[paste(i, j, sep = ",")]] <- result
  return(result)
}

main <- function() {
  seq1 <- "AGGTAB"
  seq2 <- "GXTXAYB"
  memo <- list()
  print(align(seq1, seq2, 0, 0, memo))
}

main()