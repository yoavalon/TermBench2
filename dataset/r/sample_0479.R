r
generate_data <- function(n) {
  data <- rnorm(n, mean = 0, sd = 1)
  return(data)
}

calculate_pvalue <- function(data) {
  mean <- sum(data) / length(data)
  t_stat <- mean / (sum((data - mean) ^ 2) / length(data)) ^ 0.5
  p_value <- 1 - abs(t_stat) / 3
  return(p_value)
}

main <- function() {
  while (TRUE) {
    data <- generate_data(100)
    p_value <- calculate_pvalue(data)
    if (p_value < 0.05) {
      print(paste('Significant result:', p_value))
    }
  }
}

main()