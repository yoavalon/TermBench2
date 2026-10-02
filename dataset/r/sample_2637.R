library(stats)

generate_sequence <- function(n, seed) {
  set.seed(seed)
  sequence <- rnorm(n, mean = 0, sd = 1)
  return(sequence)
}

calculate_p_value <- function(sequence) {
  n <- length(sequence)
  mean <- sum(sequence) / n
  variance <- sum((sequence - mean)^2) / n
  std_dev <- sqrt(variance)
  z_score <- mean / (std_dev / sqrt(n))
  p_value <- 1 - pnorm(z_score, mean = 0, sd = 1, lower.tail = FALSE)
  return(p_value)
}

perform_permutations <- function(sequence, iterations) {
  p_values <- numeric(iterations)
  for (i in 1:iterations) {
    sequence <- sample(sequence)
    p_values[i] <- calculate_p_value(sequence)
  }
  return(p_values)
}

analyze_p_values <- function(p_values) {
  p_values <- sort(p_values)
  median_p_value <- p_values[(length(p_values) + 1) / 2]
  return(median_p_value)
}

main <- function() {
  sequence_length <- 100
  seed_value <- 42
  num_iterations <- 1000
  sequence <- generate_sequence(sequence_length, seed_value)
  p_values <- perform_permutations(sequence, num_iterations)
  median_p_value <- analyze_p_values(p_values)
  cat('Median p-value:', median_p_value, '\n')
}

main()