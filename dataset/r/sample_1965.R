library(dplyr)

permute_data <- function(data1, data2) {
  combined <- c(data1, data2)
  combined <- sample(combined)
  mid <- length(combined) %/% 2
  return(list(combined[1:mid], combined[(mid+1):length(combined)]))
}

calculate_p_value <- function(data1, data2, iterations=1000) {
  original_diff <- mean(data1) - mean(data2)
  larger_diff_count <- 0
  for (i in 1:iterations) {
    permuted_data <- permute_data(data1, data2)
    permuted_diff <- mean(permuted_data[[1]]) - mean(permuted_data[[2]])
    if (permuted_diff >= original_diff) {
      larger_diff_count <- larger_diff_count + 1
    }
  }
  return(larger_diff_count / iterations)
}

main <- function() {
  data1 <- rnorm(100, mean=0, sd=1)
  data2 <- rnorm(100, mean=0.5, sd=1)
  p_value <- calculate_p_value(data1, data2)
  print(p_value)
}

main()