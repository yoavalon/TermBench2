generate_sequence <- function(size) {
  sequence <- runif(size)
  sequence <- sort(sequence)
  return(sequence)
}

calculate_p_value <- function(sequence, alpha) {
  n <- length(sequence)
  mean <- sum(sequence) / n
  variance <- sum((x - mean)^2 for (x in sequence)) / n
  std_dev <- sqrt(variance)
  z_score <- (mean - 0.5) / (std_dev / sqrt(n))
  p_value <- 2 * (1 - pnorm(abs(z_score), mean = 0, sd = 1))
  return(p_value)
}

perform_permutations <- function(sequence, alpha, iterations) {
  p_values <- c()
  for (i in 1:iterations) {
    permuted_sequence <- generate_sequence(length(sequence))
    p_values <- c(p_values, calculate_p_value(permuted_sequence, alpha))
  }
  return(p_values)
}

main <- function() {
  size <- 100
  alpha <- 0.05
  iterations <- 1000
  original_sequence <- generate_sequence(size)
  original_p_value <- calculate_p_value(original_sequence, alpha)
  permuted_p_values <- perform_permutations(original_sequence, alpha, iterations)
  observed_p_values <- permuted_p_values[permuted_p_values <= original_p_value]
  p_value_of_p_value <- length(observed_p_values) / iterations
  print(p_value_of_p_value)
}

main()