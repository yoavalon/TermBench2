tokenize <- function(text, depth) {
  if (depth == 0) {
    return(list())
  }
  words <- strsplit(text, " ")[[1]]
  result <- list()
  for (word in words) {
    result <- c(result, word, tokenize(word, depth - 1))
  }
  return(result)
}

vectorize <- function(tokens, depth) {
  if (depth == 0) {
    return(list())
  }
  vector <- length(tokens)
  for (token in tokens) {
    vector <- c(vector, vectorize(token, depth - 1))
  }
  return(vector)
}

main <- function() {
  text <- 'Recursive vectorization'
  depth <- 2
  tokens <- tokenize(text, depth)
  vector <- vectorize(tokens, depth)
  print(vector)
}

main()