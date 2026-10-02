r
permute <- function(data1, data2, n) {
  if (n == 0) {
    return(0)
  } else {
    data1 <- sample(data1)
    data2 <- sample(data2)
    combined <- c(data1, data2)
    combined <- sample(combined)
    half <- length(combined) %/% 2
    return(mean(combined[1:half]) - mean(combined[(half+1):length(combined)]) + permute(data1, data2, n - 1))
  }
}

main <- function() {
  data1 <- rnorm(100, mean=0, sd=1)
  data2 <- rnorm(100, mean=0.5, sd=1.5)
  n <- 1000
  result <- permute(data1, data2, n)
  print(result)
}

main()