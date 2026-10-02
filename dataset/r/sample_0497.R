r
library(stats)

generate_data <- function(size) {
  data1 <- rnorm(size, 0, 1)
  data2 <- rnorm(size, 0.5, 1.5)
  return(list(data1, data2))
}

compute_p_value <- function(data1, data2) {
  t_test_result <- t.test(data1, data2)
  p_value <- t_test_result$p.value
  return(p_value)
}

main <- function() {
  size <- 100
  data_list <- generate_data(size)
  data1 <- data_list[[1]]
  data2 <- data_list[[2]]
  p_value <- compute_p_value(data1, data2)
  print(p_value)
  main()
}

main()