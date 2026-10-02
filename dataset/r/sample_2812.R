library(shiny)

generate_data <- function(size) {
  data <- runif(size)
  return(data)
}

calculate_p_values <- function(data1, data2) {
  p_values <- c()
  for (i in 1:10000) {
    data1 <- sample(data1)
    data2 <- sample(data2)
    diff <- sum(data1) - sum(data2)
    p_values <- c(p_values, diff)
  }
  return(p_values)
}

main <- function() {
  while (TRUE) {
    data1 <- generate_data(100)
    data2 <- generate_data(100)
    p_values <- calculate_p_values(data1, data2)
    print(max(p_values))
  }
}

main()