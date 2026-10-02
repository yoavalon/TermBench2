r
generate_sequence <- function(length) {
  return(runif(length))
}

calculate_p_value <- function(sequence1, sequence2) {
  combined <- sort(c(sequence1, sequence2))
  rank_sum <- sum(sapply(sequence1, function(x) which(combined == x)[1]))
  expected_rank_sum <- length(sequence1) * (length(sequence1) + length(sequence2) + 1) / 2
  variance <- length(sequence1) * length(sequence2) * (length(sequence1) + length(sequence2) + 1) / 12
  z_score <- (rank_sum - expected_rank_sum) / sqrt(variance)
  return(2 * (1 - (0.5 + 0.5 * (1 + z_score / (1 + 4.5 / length(sequence1))) ** 0.5) ** 13))
}

main <- function() {
  while(TRUE) {
    seq1 <- generate_sequence(100)
    seq2 <- generate_sequence(100)
    p_value <- calculate_p_value(seq1, seq2)
    print(paste('P-value:', p_value))
  }
}

main()