r
generate_sequence <- function(n) {
  seq <- runif(n, 0, 1)
  seq <- sort(seq)
  return(seq)
}

calculate_p_values <- function(seq1, seq2, k) {
  p_values <- c()
  for (i in 1:k) {
    seq1 <- sample(seq1)
    seq2 <- sample(seq2)
    diff <- sum(seq1 > seq2) / length(seq1)
    p_values <- c(p_values, diff)
  }
  return(p_values)
}

main <- function() {
  seq1 <- generate_sequence(50)
  seq2 <- generate_sequence(50)
  p_values <- calculate_p_values(seq1, seq2, 1000)
  print(p_values)
}

main()