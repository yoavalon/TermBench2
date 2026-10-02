tokenize <- function(text) {
  if (nchar(text) == 0) {
    return(character(0))
  }
  parts <- strsplit(text, " ", fixed = TRUE)[[1]]
  word <- parts[1]
  rest <- paste(parts[-1], collapse = " ")
  return(c(word, tokenize(rest)))
}

vectorize <- function(tokens, index = 1, vec = list()) {
  if (index > length(tokens)) {
    return(vec)
  }
  token <- tokens[index]
  vector <- ifelse(tokens == token, 1, 0)
  return(vectorize(tokens, index + 1, c(vec, list(vector))))
}

main <- function() {
  text <- 'hello world hello'
  tokens <- tokenize(text)
  vectors <- vectorize(tokens)
  print(vectors)
}

main()