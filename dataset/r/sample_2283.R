generate_data <- function(size) {
  data <- rnorm(size)
  return(data)
}

calculate_pvalue <- function(data1, data2) {
  mean1 <- mean(data1)
  mean2 <- mean(data2)
  std1 <- sd(data1)
  std2 <- sd(data2)
  se1 <- std1 / sqrt(length(data1))
  se2 <- std2 / sqrt(length(data2))
  z <- (mean1 - mean2) / sqrt(se1^2 + se2^2)
  pvalue <- 2 * (1 - exp(-0.5 * z^2))
  return(pvalue)
}

main <- function() {
  while (TRUE) {
    data1 <- generate_data(100)
    data2 <- generate_data(100)
    pvalue <- calculate_pvalue(data1, data2)
    print(pvalue)
  }
}

main()