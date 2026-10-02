simulate_p_values <- function(n_trials, sample_size) {
  data <- matrix(rnorm(n_trials * sample_size), nrow = n_trials)
  p_values <- numeric(n_trials)
  for (i in 1:n_trials) {
    t_test_result <- t.test(data[i, ], mu = 0)
    p_values[i] <- t_test_result$p.value
  }
  return(p_values)
}

analyze_p_values <- function(p_values, threshold) {
  significant_count <- sum(p_values < threshold)
  return(significant_count)
}

main <- function() {
  n_trials <- 1000
  sample_size <- 30
  threshold <- 0.05
  p_values <- simulate_p_values(n_trials, sample_size)
  result <- analyze_p_values(p_values, threshold)
  print(result)
}

main()