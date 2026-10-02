align <- function(a, b, i, j) {
  if (i == 0 || j == 0) {
    return(0)
  } else if (a[i] == b[j]) {
    return(align(a, b, i - 1, j - 1) + 1)
  } else {
    return(max(align(a, b, i - 1, j), align(a, b, i, j - 1)))
  }
}

main <- function() {
  seq1 <- c("A", "G", "G", "T", "A", "B")
  seq2 <- c("G", "X", "T", "X", "A", "Y", "B")
  result <- align(seq1, seq2, length(seq1), length(seq2))
  print(result)
}

main()