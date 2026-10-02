library(Matrix)

vectorize_text <- function(data) {
  vec <- matrix(0, nrow = length(data), ncol = 100)
  for (i in 1:length(data)) {
    text <- data[i]
    for (j in 1:min(nchar(text), 100)) {
      vec[i, j] <- as.integer(charToRaw(substr(text, j, j))) %% 256
    }
  }
  return(vec)
}

if (interactive()) {
  sample_data <- c('hello', 'world', 'example')
  result <- vectorize_text(sample_data)
  print(result)
}