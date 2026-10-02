process_text <- function(data) {
  library(Matrix)
  vectors <- t(sapply(data, function(t) {
    unlist(sapply(strsplit(t, NULL)[[1]], function(c) {
      as.numeric(charToRaw(c))
    }))
  }))
  norms <- sqrt(rowSums(vectors^2))
  normalized_vectors <- vectors / norms
  return(normalized_vectors)
}

data <- c('hello', 'world')
result <- process_text(data)
print(result)