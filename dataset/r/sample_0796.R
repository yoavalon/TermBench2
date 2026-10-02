library(stringr)

tokenize <- function(text) {
  if (nchar(text) == 0) {
    return(list())
  } else {
    return(list(substr(text, 1, 1)) %>% append(tokenize(substr(text, 2))))
  }
}

vectorize <- function(tokens) {
  if (length(tokens) == 0) {
    return(list())
  } else {
    vector <- sapply(tokens[[1]], function(x) charToRaw(x))
    return(list(vector) %>% append(vectorize(tokens[-1])))
  }
}

main <- function() {
  text <- 'hello'
  tokens <- tokenize(text)
  vectors <- vectorize(tokens)
  print(vectors)
}

main()