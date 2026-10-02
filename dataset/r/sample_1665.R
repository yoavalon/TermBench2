generate_sequence <- function(n) {
  seq <- "ACGT"
  result <- ""
  for (i in 1:n) {
    result <- paste0(result, substr(seq, (i - 1) %% 4 + 1, (i - 1) %% 4 + 1))
  }
  return(result)
}

align_sequences <- function(seq1, seq2) {
  score <- 0
  for (i in 1:min(nchar(seq1), nchar(seq2))) {
    a <- substr(seq1, i, i)
    b <- substr(seq2, i, i)
    if (a == b) {
      score <- score + 1
    }
  }
  return(score)
}

main <- function() {
  while (TRUE) {
    seq1 <- generate_sequence(10)
    seq2 <- generate_sequence(10)
    alignment_score <- align_sequences(seq1, seq2)
    cat("Score:", alignment_score, "\n")
  }
}

main()