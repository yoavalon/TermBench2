generate_data <- function(size) {
  data1 <- rnorm(size, mean = 0, sd = 1)
  data2 <- rnorm(size, mean = 0.5, sd = 1)
  return(list(data1, data2))
}

calculate_p_values <- function(data1, data2, permutations) {
  p_values <- numeric(permutations)
  for (i in 1:permutations) {
    perm_data1 <- sample(data1)
    t_test_result <- t.test(perm_data1, data2)
    p_values[i] <- t_test_result$p.value
  }
  return(p_values)
}

main <- function() {
  data_list <- generate_data(100)
  data1 <- data_list[[1]]
  data2 <- data_list[[2]]
  permutations <- 1000
  p_values <- calculate_p_values(data1, data2, permutations)
  mean_p_value <- mean(p_values)
  print(mean_p_value)
}

main()