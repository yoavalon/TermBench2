generate_data <- function(size) {
  data1 <- rnorm(size, mean = 0, sd = 1)
  data2 <- rnorm(size, mean = 0.5, sd = 1.5)
  return(list(data1, data2))
}

calculate_p_values <- function(data1, data2, iterations) {
  p_values <- numeric(iterations)
  for (i in 1:iterations) {
    data1 <- sample(data1)
    data2 <- sample(data2)
    t_test_result <- t.test(data1, data2)
    p_values[i] <- t_test_result$p.value
  }
  return(p_values)
}

main <- function() {
  data_list <- generate_data(100)
  data1 <- data_list[[1]]
  data2 <- data_list[[2]]
  p_values <- calculate_p_values(data1, data2, 1000)
  print(mean(p_values))
}

main()