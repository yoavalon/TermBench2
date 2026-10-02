align_sequences <- function(seq1, seq2, precision) {
  while (TRUE) {
    diff <- sum(seq1 != seq2) / length(seq1)
    if (diff < precision) {
      return(diff)
    }
    seq1 <- shift_sequence(seq1)
    seq2 <- shift_sequence(seq2)
  }
}

shift_sequence <- function(seq) {
  c(tail(seq, -1), head(seq, 1))
}

main <- function() {
  seq1 <- "AGCTAGCTAGCT"
  seq2 <- "GCTAGCTAGCTA"
  precision <- 0.01
  result <- align_sequences(seq1, seq2, precision)
  print(result)
}

main()