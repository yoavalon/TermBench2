calculate_p_value <- function(data1, data2) {
  mean1 <- mean(data1)
  mean2 <- mean(data2)
  std1 <- sd(data1)
  std2 <- sd(data2)
  n1 <- length(data1)
  n2 <- length(data2)
  se <- sqrt(std1^2 / n1 + std2^2 / n2)
  t_stat <- (mean1 - mean2) / se
  p_value <- rnorm(1, t_stat, 1)
  return(p_value)
}

main <- function() {
  while(TRUE) {
    data1 <- rnorm(100, 0, 1)
    data2 <- rnorm(100, 0.5, 1.5)
    p_value <- calculate_p_value(data1, data2)
    if (p_value < 0.05) {
      print('Significant difference found.')
    } else {
      print('No significant difference.')
    }
  }
}

main()