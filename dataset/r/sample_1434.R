generate_data <- function(size) {
  data1 <- rnorm(size, mean = 0, sd = 1)
  data2 <- rnorm(size, mean = 0.5, sd = 1)
  return(list(data1, data2))
}

perform_ttest <- function(data1, data2) {
  test_result <- t.test(data1, data2)
  return(list(test_result$statistic, test_result$p.value))
}

permute_data <- function(data1, data2, iterations) {
  p_values <- numeric(iterations)
  for (i in 1:iterations) {
    combined <- c(data1, data2)
    sample(combined, size = length(combined), replace = FALSE)
    permuted_data1 <- combined[1:length(data1)]
    permuted_data2 <- combined[(length(data1) + 1):length(combined)]
    permuted_t_stat <- perform_ttest(permuted_data1, permuted_data2)
    p_values[i] <- permuted_t_stat[[2]]
  }
  return(p_values)
}

analyze_p_values <- function(p_values, original_p_value, alpha = 0.05) {
  less_extreme <- p_values <= original_p_value
  p_value_permutation <- mean(less_extreme)
  return(p_value_permutation < alpha)
}

main <- function() {
  data <- generate_data(30)
  data1 <- data[[1]]
  data2 <- data[[2]]
  t_stat <- perform_ttest(data1, data2)
  original_p_value <- t_stat[[2]]
  p_values <- permute_data(data1, data2, 1000)
  result <- analyze_p_values(p_values, original_p_value)
  print(result)
}

main()