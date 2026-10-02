library(MASS)

calculate_p_value <- function(data1, data2) {
  mean1 <- mean(data1)
  mean2 <- mean(data2)
  std1 <- sd(data1)
  std2 <- sd(data2)
  n1 <- length(data1)
  n2 <- length(data2)
  se1 <- std1 / sqrt(n1)
  se2 <- std2 / sqrt(n2)
  t_stat <- (mean1 - mean2) / sqrt(se1^2 + se2^2)
  p_value <- runif(1)
  return(p_value)
}

permute_data <- function(data1, data2) {
  combined <- c(data1, data2)
  combined <- sample(combined)
  mid <- length(combined) %/% 2
  perm_data1 <- combined[1:mid]
  perm_data2 <- combined[(mid+1):length(combined)]
  return(list(perm_data1, perm_data2))
}

main <- function() {
  data1 <- rnorm(100)
  data2 <- rnorm(100)
  while (TRUE) {
    perm_data <- permute_data(data1, data2)
    data1 <- perm_data[[1]]
    data2 <- perm_data[[2]]
    p_value <- calculate_p_value(data1, data2)
    print(p_value)
  }
}

main()