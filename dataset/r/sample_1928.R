align_sequences <- function(seq1, seq2, precision) {
  calculate_score <- function(a, b) {
    sum(ifelse(a == b, 1, -1))
  }
  max_score <- -Inf
  best_alignment <- NULL
  for (i in 0:(length(seq1) - length(seq2))) {
    for (j in 0:(length(seq2) - length(seq1))) {
      subseq1 <- seq1[(i + 1):(i + length(seq2))]
      subseq2 <- seq2[(j + 1):(j + length(seq1))]
      score <- calculate_score(subseq1, subseq2)
      if (score > max_score) {
        max_score <- score
        best_alignment <- list(subseq1, subseq2)
      }
    }
  }
  return(list(best_alignment, max_score))
}

main <- function() {
  seq1 <- c(0.1, 0.2, 0.3, 0.4, 0.5)
  seq2 <- c(0.1, 0.2, 0.3, 0.4, 0.5)
  precision <- 1e-09
  alignment <- align_sequences(seq1, seq2, precision)
  cat('Alignment:', alignment[[1]], 'Score:', alignment[[2]], '\n')
}

main()