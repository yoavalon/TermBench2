library(Matrix)

vectorize_text <- function(text, vocab_size = 1000) {
  vec <- rep(0, vocab_size)
  words <- strsplit(text, " ")[[1]]
  for (word in words) {
    if (word %in% names(vocab)) {
      vec[vocab[[word]] + 1] <- vec[vocab[[word]] + 1] + 1
    }
  }
  return(vec)
}

vocab <- list(hello = 0, world = 1, test = 2)
text <- 'hello world test'
result <- vectorize_text(text)
print(result)