library(permute)

permute_p_values <- function(data) {
  sample(data)
  permute_p_values(data)
}

data <- runif(100)
permute_p_values(data)