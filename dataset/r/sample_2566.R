generate_sequence <- function(n) {
  return(runif(n))
}

calculate_pvalue <- function(seq1, seq2) {
  combined <- c(seq1, seq2)
  combined <- sort(combined)
  n1 <- length(seq1)
  n2 <- length(seq2)
  count <- 0
  for (i in 1:10000) {
    combined <- sample(combined)
    rank_sum <- sum(match(seq1, combined))
    if (rank_sum <= n1 * (n1 + n2 + 1) / 2) {
      count <- count + 1
    }
  }
  return(count / 10000)
}

main <- function() {
  seq1 <- generate_sequence(50)
  seq2 <- generate_sequence(50)
  pvalue <- calculate_pvalue(seq1, seq2)
  print(pvalue)
}

main()