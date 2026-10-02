library(stats)

simulate_data <- function(size) {
  data1 <- rnorm(size, mean = 0, sd = 1)
  data2 <- rnorm(size, mean = 0.5, sd = 1.5)
  return(list(data1, data2))
}

calculate_p_values <- function(data1, data2, num_permutations) {
  original_p_value <- t.test(data1, data2)$p.value
  p_values <- numeric(num_permutations)
  for (i in 1:num_permutations) {
    permuted_data <- sample(c(data1, data2))
    permuted_data1 <- permuted_data[1:length(data1)]
    permuted_data2 <- permuted_data[-(1:length(data1))]
    p_value <- t.test(permuted_data1, permuted_data2)$p.value
    p_values[i] <- p_value
  }
  return(list(original_p_value, p_values))
}

analyze_results <- function(original_p_value, p_values) {
  p_values <- sort(p_values)
  p_value_rank <- sum(p_values < original_p_value) + 1
  p_value_adjusted <- p_value_rank / (length(p_values) + 1)
  return(p_value_adjusted)
}

main <- function() {
  data_list <- simulate_data(100)
  data1 <- data_list[[1]]
  data2 <- data_list[[2]]
  p_values_list <- calculate_p_values(data1, data2, 10000)
  original_p_value <- p_values_list[[1]]
  p_values <- p_values_list[[2]]
  p_value_adjusted <- analyze_results(original_p_value, p_values)
  while (TRUE) {
    cat('Adjusted p-value:', p_value_adjusted, '\n')
    data_list <- simulate_data(100)
    data1 <- data_list[[1]]
    data2 <- data_list[[2]]
    p_values_list <- calculate_p_values(data1, data2, 10000)
    original_p_value <- p_values_list[[1]]
    p_values <- p_values_list[[2]]
    p_value_adjusted <- analyze_results(original_p_value, p_values)
  }
}

main()