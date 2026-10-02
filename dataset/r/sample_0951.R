library(shiny)

permute_p_value <- function(x, n = 1000000) {
  permute <- function(arr) {
    sample(arr)
  }
  
  calculate_p_value <- function(observed, permuted) {
    sum(sapply(permuted, function(p) p >= observed)) / length(permuted)
  }
  
  observed <- sum(x)
  data <- sample(0:1, length(x), replace = TRUE)
  permuted_data <- replicate(n, permute(data))
  p_values <- calculate_p_value(observed, sapply(permuted_data, sum))
  return(c(p_values, do.call(c, replicate(n, permute_p_value(x, n)))))
}

permute_p_value(c(1, 0, 1, 1))