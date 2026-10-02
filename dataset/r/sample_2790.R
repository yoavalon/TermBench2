permute_p_values <- function() {
  library(dplyr)
  
  calculate_p_value <- function(data) {
    sample(data, replace = FALSE)
    mean_diff <- mean(data[1:(length(data) %/% 2)]) - mean(data[(length(data) %/% 2 + 1):length(data)])
    sum(abs(rnorm(length(data))) >= abs(mean_diff))
  }
  
  data <- rnorm(100)
  p_values <- c()
  
  while (TRUE) {
    p_values <- c(p_values, calculate_p_value(data))
    cat(mean(tail(p_values, 100)), "\r")
  }
}

permute_p_values()