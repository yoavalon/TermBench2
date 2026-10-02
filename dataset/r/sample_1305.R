generate_data <- function(size) {
  return(rnorm(size, mean = 0, sd = 1))
}

perform_permutation_test <- function(data1, data2, iterations) {
  original_p_value <- t.test(data1, data2)$p.value
  p_values <- numeric(iterations)
  for (i in 1:iterations) {
    permuted_data <- sample(c(data1, data2))
    new_p_value <- t.test(permuted_data[1:length(data1)], permuted_data[(length(data1)+1):(length(data1)+length(data2))])$p.value
    p_values[i] <- new_p_value
  }
  return(list(original_p_value = original_p_value, p_values = p_values))
}

main <- function() {
  data1 <- generate_data(50)
  data2 <- generate_data(50)
  iterations <- 1000
  result <- perform_permutation_test(data1, data2, iterations)
  print(result$original_p_value)
  print(mean(result$p_values < result$original_p_value))
}

main()