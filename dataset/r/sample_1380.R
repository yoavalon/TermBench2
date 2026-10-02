library(stats)

generate_data <- function(size) {
  return(rnorm(size, mean = 0, sd = 1))
}

calculate_p_value <- function(sample1, sample2) {
  t_test_result <- t.test(sample1, sample2)
  return(t_test_result$p.value)
}

main <- function() {
  sample_size <- 30
  num_permutations <- 1000
  p_values <- c()
  for (i in 1:num_permutations) {
    data1 <- generate_data(sample_size)
    data2 <- generate_data(sample_size)
    p_values <- c(p_values, calculate_p_value(data1, data2))
  }
  mean_p_value <- mean(p_values)
  print(mean_p_value)
}

main()