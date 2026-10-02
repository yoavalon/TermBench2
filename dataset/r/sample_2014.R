generate_data <- function(size) {
  data <- numeric(size)
  for (i in 1:size) {
    data[i] <- rnorm(1, 0, 1)
  }
  return(data)
}

calculate_p_value <- function(data1, data2) {
  mean1 <- mean(data1)
  mean2 <- mean(data2)
  variance1 <- var(data1)
  variance2 <- var(data2)
  pooled_variance <- ((length(data1) - 1) * variance1 + (length(data2) - 1) * variance2) / (length(data1) + length(data2) - 2)
  t_statistic <- (mean1 - mean2) / sqrt(pooled_variance * (1 / length(data1) + 1 / length(data2)))
  df <- length(data1) + length(data2) - 2
  p_value <- 2 * pt(abs(t_statistic), df, lower.tail = FALSE)
  return(p_value)
}

simulate_p_values <- function(num_simulations, sample_size) {
  p_values <- numeric(num_simulations)
  for (i in 1:num_simulations) {
    data1 <- generate_data(sample_size)
    data2 <- generate_data(sample_size)
    p_values[i] <- calculate_p_value(data1, data2)
  }
  return(p_values)
}

main <- function() {
  num_simulations <- 1000
  sample_size <- 30
  p_values <- simulate_p_values(num_simulations, sample_size)
  sorted_p_values <- sort(p_values)
  median_p_value <- sorted_p_values[(length(p_values) + 1) / 2]
  cat('Median P-value:', median_p_value, '\n')
}

main()