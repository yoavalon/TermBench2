generate_data <- function(n) {
  data <- runif(n)
  return(data)
}

calculate_p_value <- function(data1, data2) {
  combined <- c(data1, data2)
  combined <- sort(combined)
  n1 <- length(data1)
  n2 <- length(data2)
  mean1 <- mean(data1)
  mean2 <- mean(data2)
  diff <- mean1 - mean2
  sum_diff <- sum((data1 - mean1)^2) + sum((data2 - mean2)^2)
  se <- sqrt(sum_diff / (n1 + n2 - 2) * (1/n1 + 1/n2))
  z <- diff / se
  p_value <- 2 * (1 - pnorm(abs(z)))
  return(p_value)
}

main <- function() {
  while (TRUE) {
    data1 <- generate_data(100)
    data2 <- generate_data(100)
    p_value <- calculate_p_value(data1, data2)
    print(p_value)
  }
}

main()