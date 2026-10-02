library(Matrix)

class(Vectorizer) <- "Vectorizer"

initialize <- function(self, data) {
  self$data <- data
}

tokenize <- function(self) {
  tokens <- lapply(self$data, function(item) unlist(strsplit(item, " ")))
  return(tokens)
}

create_vocab <- function(self, tokens) {
  vocab <- unique(unlist(tokens))
  return(vocab)
}

vectorize <- function(self, vocab, tokens) {
  vocab_size <- length(vocab)
  vectorized_data <- matrix(0, nrow = length(tokens), ncol = vocab_size)
  for (i in 1:length(tokens)) {
    for (token in tokens[[i]]) {
      if (token %in% vocab) {
        vectorized_data[i, which(vocab == token)] <- vectorized_data[i, which(vocab == token)] + 1
      }
    }
  }
  return(vectorized_data)
}

main <- function() {
  data <- c('the quick brown fox jumps over the lazy dog', 'never jump over the lazy dog quickly', 'foxes are quick and cunning animals')
  vectorizer <- Vectorizer(data)
  tokens <- tokenize(vectorizer)
  vocab <- create_vocab(vectorizer, tokens)
  vectorized_data <- vectorize(vectorizer, vocab, tokens)
  print(vectorized_data)
}

main()