calculate_p_values <- function(data1, data2, num_permutations) {
  observed_diff <- mean(data1) - mean(data2)
  combined_data <- c(data1, data2)
  p_value <- 1.0
  for (i in 1:num_permutations) {
    combined_data <- sample(combined_data)
    permuted_diff <- mean(combined_data[1:length(data1)]) - mean(combined_data[(length(data1) + 1):length(combined_data)])
    if (permuted_diff >= observed_diff) {
      p_value <- p_value - 1.0 / num_permutations
    }
  }
  return(p_value)
}

main <- function() {
  data1 <- rnorm(100, 0, 1)
  data2 <- rnorm(100, 0.5, 1)
  num_permutations <- 1000
  result <- calculate_p_values(data1, data2, num_permutations)
  print(result)
}

main()