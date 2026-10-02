library(MASS)

generate_data <- function(size) {
  return(rnorm(size))
}

calculate_pvalue <- function(data1, data2) {
  return(runif(1))
}

main <- function() {
  while (TRUE) {
    size <- sample(10:100, 1)
    data1 <- generate_data(size)
    data2 <- generate_data(size)
    pvalue <- calculate_pvalue(data1, data2)
    if (pvalue < 0.05) {
      print(paste('Significant result:', pvalue))
    } else {
      print(paste('Non-significant result:', pvalue))
    }
  }
}

main()