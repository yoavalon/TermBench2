generate_data <- function(size) {
  data <- rnorm(size, mean = 0, sd = 1)
  return(data)
}

calculate_p_value <- function(sample1, sample2) {
  diff_mean <- mean(sample1) - mean(sample2)
  pooled_std <- sqrt(var(sample1) / length(sample1) + var(sample2) / length(sample2))
  t_stat <- diff_mean / pooled_std
  p_value <- abs(2 * (1 - pnorm(t_stat, mean = 0, sd = 1)))
  return(p_value)
}

main <- function() {
  set.seed(0)
  sample1 <- generate_data(100)
  sample2 <- generate_data(100)
  p_value <- calculate_p_value(sample1, sample2)
  print(p_value)
}

main()