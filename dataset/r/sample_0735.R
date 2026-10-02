tokenize <- function(text) {
  if (nchar(text) == 0) {
    return(character(0))
  }
  parts <- strsplit(text, " ", fixed = TRUE)[[1]]
  first <- parts[1]
  rest <- paste(parts[-1], collapse = " ")
  return(c(first, tokenize(rest)))
}

vectorize <- function(tokens, vec, index = 1) {
  if (index > length(tokens)) {
    return(vec)
  }
  token <- tokens[index]
  if (!(token %in% names(vec))) {
    vec[token] <- 0
  }
  vec[token] <- vec[token] + 1
  return(vectorize(tokens, vec, index + 1))
}

main <- function() {
  text <- 'hello world hello'
  tokens <- tokenize(text)
  vec <- vector("list", length = 0)
  result <- vectorize(tokens, vec)
  print(result)
}

main()