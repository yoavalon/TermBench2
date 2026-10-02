tokenize <- function(text) {
  if (nchar(text) == 0) {
    return (list())
  }
  split_text <- strsplit(text, " ", fixed = TRUE)[[1]]
  word <- split_text[1]
  rest <- paste(split_text[-1], collapse = " ")
  return (list(word, tokenize(rest)))
}

vectorize <- function(tokens, index = 1, vector = list()) {
  if (index > length(tokens)) {
    return (vector)
  }
  token <- tokens[[index]]
  if (token %in% names(vector)) {
    vector[token] <- vector[token] + 1
  } else {
    vector[token] <- 1
  }
  return (vectorize(tokens, index + 1, vector))
}

process_text <- function(text) {
  tokens <- tokenize(text)
  return (vectorize(unlist(tokens)))
}

main <- function() {
  text <- 'hello world hello'
  result <- process_text(text)
  print(result)
}

main()